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

void PreOrderHelper(struct TreeNode* root, int* returnSize, int* ret)
{
    if(root)
    {
        ret[(*returnSize)++] = root->val;
        PreOrderHelper(root->left, returnSize, ret);
        PreOrderHelper(root->right, returnSize, ret);
       
    }
    
}
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
  //Left Right Root
      *returnSize =0;
    if(root == NULL)
        return NULL;
    
    int size = CalSize(root);
    
    int* ret = (int*)calloc(size, sizeof(int));
    if(ret == NULL)
        return NULL;
    
  
    
    PreOrderHelper(root , returnSize, ret);
        
    return ret;
}

