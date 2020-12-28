/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/** Encodes a tree to a single string. */
#define SIZE 100000

char* serialize(struct TreeNode* root) 
{
    if(root == NULL)
        return "";
    
    struct TreeNode* queue[SIZE] = {0};
    char* ret = (char*) calloc(SIZE, sizeof(char));
   
    if(ret== NULL)
        return NULL;
    
     if(root!= NULL && (root->left == NULL && root->right == NULL))
     {
          sprintf(ret, "%d,", root->val);
           return ret;
     }
    
    int head =0, tail = 0, idx=0, id; 
    
    tail = head;
    queue[head] = root;
    tail++;
    queue[tail++] = NULL;
    
    while(head<tail)
    {
        root = queue[head++];
       
        if(root!= NULL)
        {
           
            id = sprintf(ret+idx, "%d,", root->val);
            idx = idx+id;
             if(root->left)
                queue[tail++] = root->left;
              if(root->right)
                queue[tail++] = root->right;
    
        }
        else
        {
            
           if(head == tail)
               break;
           else 
           {
               queue[tail++] = NULL;
            }
        }
    }
   ret[idx-1] = '\0';
  return ret;  
}


struct TreeNode* LevelOrder(struct TreeNode* root , int data)  
{ 
     if(root==NULL){     
        root = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
        root->val = data;
         root->left = root->right = NULL;
        return root; 
     } 
     if(data <= root->val) 
     root->left = LevelOrder(root->left, data); 
     else
     root->right = LevelOrder(root->right, data); 
     return root;      
} 
  

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) 
{
  
    if(data == NULL)
        return NULL;
    
    
    struct TreeNode* root = NULL;
    char s[2] = {',', '\0'};
    int* tmp = (int*) calloc(1, sizeof(int));    
     char* token = strtok(data, s);
     int i =0;   
     if(token == NULL)
         return NULL;   
      
    
      while( token != NULL ) {     
      root= LevelOrder(root, atoi(token) );  
      token = strtok(NULL, s);
   }
                 
   return root;

}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);
