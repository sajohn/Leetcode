/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


int CalSize(struct Node* root)
{
     if(root == NULL)
         return 0;
    int size =0;
    for(int i =0; i < root->numChildren; i++)
      size+= CalSize(root->children[i]);
    
    return 1+size;
}

void TraversePreOrder(struct Node* root, int* returnSize, int* ret)
{
    if(root == NULL)
        return;
    
  ret[(*returnSize)++]  = root->val;
    
  if(root->children != NULL && root->numChildren>0)
  {
    int i =0; 
    while(i < root->numChildren)
          TraversePreOrder(root->children[i++], returnSize,ret);
   }
      
 }

int* preorder(struct Node* root, int* returnSize) 
{
       if(root == NULL)
       {
           *returnSize = 0;
           return NULL;
       }
    
    int size = CalSize(root);
    int* ret = (int*) calloc(size, sizeof(int));
    if(ret == NULL)
        return NULL;
   
    *returnSize = 0;  
    
     if(root->children == NULL)
     {       
         *returnSize = 1;
         *ret = root->val;
         return ret;   
     }
     else if(root->children!=NULL )
     {
        ret[(*returnSize)++] = root->val; 
       for(int i =0; i < root->numChildren; i++)
       {
          TraversePreOrder(root->children[i], returnSize, ret);
       }
     }
    
    return ret;
    
}
