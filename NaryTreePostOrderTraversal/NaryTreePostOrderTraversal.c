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

void TraversePostOrder(struct Node* root, int* returnSize, int* ret)
{
    if(root == NULL)
        return;
    
  if(root->children != NULL && root->numChildren>0)
  {
    int i =0; 
    while(i < root->numChildren)
    {
        
      if(root->children[i] == NULL)
          ret[(*returnSize)++]  = root->children[i]->val;
      else
          TraversePostOrder(root->children[i], returnSize,ret);
      i++;
    }
      //done with children add root 
      
        ret[(*returnSize)++]  = root->val;
  }
  else
     ret[(*returnSize)++]  = root->val;
 }

int* postorder(struct Node* root, int* returnSize) 
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
        
       for(int i =0; i < root->numChildren; i++)
          TraversePostOrder(root->children[i], returnSize, ret);
       ret[(*returnSize)++] = root->val;
     }
    
    return ret;
    
}
