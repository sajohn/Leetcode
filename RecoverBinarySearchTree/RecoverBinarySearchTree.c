/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//The first node which create problem should be x and should go to x


void Helper(struct TreeNode* root, struct TreeNode** x, struct TreeNode** y, struct TreeNode** prev){
    
  if(root){
     
     Helper(root->left, x, y, prev);

          if((*prev) != NULL && (*prev)->val > root->val) {      
            //Cannot swap here just wait for final change
            (*y) = root; 
           if((*x) == NULL)
               (*x) = *prev; 
             else 
               //Shouldn't have happened
                 return; 
             
         } 
         
         *prev = root; 
         
     Helper(root->right, x, y, prev);
  }
}

void recoverTree(struct TreeNode* root){

struct TreeNode* x = NULL, *y= NULL, *prev= NULL; 
 
    if(root == NULL)
        return ;
   
    
    Helper(root, &x, &y, &prev);
    if(x != NULL && y != NULL){
        int tmp = x->val; 
        x->val = y->val;
        y->val = tmp;
    }

}
