/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void Helper(struct TreeNode** root, char* ret, int* idx)
{
 
    if( ret[*idx] == NULL )
        return;
    unsigned int val = 0, sign = 1;
    
    while(ret[*idx]!= '(' &&  ret[*idx] !=')' && ret[*idx]!= '\0')
    {
        if( ret[*idx] == '-'){
            sign = -1; 
            (*idx)++; 
            continue; 
        }
        
        val = val*10 + (ret[*idx] - '0');
        (*idx)++; 
    }
    
    *root = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
    
    (*root)->val = sign*val; 
    (*root)->left = NULL; 
    (*root)->right = NULL; 
        

     if(ret[*idx] == '('){
         (*idx)++; 
         if((*root)->left == NULL){
             Helper(&(*root)->left,  ret, idx);  //  2->left 3 --> right 
            if(ret[*idx] == ')'){
                 (*idx)++; 
            return; 
            }
         }
        //After a return you are getting this check which is required to contiue with string parsing.... 
        if(ret[(*idx)] == '(')
        { 
            (*idx)++; 
            Helper(&(*root)->right,  ret, idx);  //  1---> ) 
              if(ret[*idx] == ')'){
                 (*idx)++; 
            return; 
            }
        }

     }
      else if(ret[*idx] == ')')
      {
            (*idx)++; 
             return;   
      }

      return;    
}

struct TreeNode* str2tree(char * s){
    
     if(s == NULL)
        return NULL;
    
 int len = strlen(s);
 if(len == 0)
     return NULL; 
 struct TreeNode* root = (struct TreeNode*)calloc(1, sizeof(struct TreeNode)); 
 int idx =0; 
 Helper(&root, s, &idx);

    return root; 
}
