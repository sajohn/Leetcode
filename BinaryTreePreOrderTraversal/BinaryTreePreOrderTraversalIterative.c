/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


int CalSize(struct TreeNode* root)
{
     if(root == NULL)
         return 0;
    int size =0;
   
   return 1+ CalSize(root->left)+ CalSize(root->right);
}

int isStackEmpty(int* top)
{
     if((*top) < 0)
         return 1;
    
    return 0;
}

void preorderTraversalHelper(struct TreeNode* root, int** returnSize, int* ret,  struct TreeNode** stack , int* top)
{
   if(stack == NULL || root == NULL || ret == NULL || top == NULL)
       return ;   

    while(1)
    {
        while(root!=NULL)
        {
          ret[(**returnSize)++] = root->val;
              stack[++(*top)] = root;
              root = root->left;
        }
        
        if(isStackEmpty(top))
            return;
        
          root = stack[(*top)];
          stack[(*top)--] = NULL; 

          root = root->right;
   
    }
    
}


int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    if(root == NULL || returnSize ==0)
    {
        *returnSize = 0;
        return NULL;
    }  

    int size = CalSize(root);
    
  
     int* ret = (int*) calloc(size, sizeof(int));
    if(ret == NULL)
        return NULL;
     
    if(size ==1)
    {
        *returnSize =1;
        ret[0] = root->val;
        return ret;
    }
    
    struct TreeNode** stack = (struct TreeNode**) calloc(size, sizeof(struct TreeNode*));
    
     if(stack == NULL)
        return NULL;  
   
    *returnSize = 0;  
    int* top =(int*)calloc(1, sizeof(int));
    if(top == NULL)
        return NULL;
    *top =-1;
    
    if(root!=NULL)  
        preorderTraversalHelper(root, &returnSize, ret, stack, top);

    
    *returnSize=  size;
    
    free(stack);
    
    return ret;
    
}
