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
    
    return 1 + CalSize( root->left)+ CalSize( root->right);
}

void PostOrderHelper(struct TreeNode* root, int* returnSize, int* ret)
{
    if(root)
    {
        
        PostOrderHelper(root->left, returnSize, ret);
        PostOrderHelper(root->right, returnSize, ret);
        ret[(*returnSize)++] = root->val;
    }
    
}
int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
  //Left Right Root
      *returnSize =0;
    if(root == NULL)
        return NULL;
    
    int size = CalSize(root);
    
    int* ret = (int*)calloc(size, sizeof(int));
    if(ret == NULL)
        return NULL;
    
  
    
    PostOrderHelper(root , returnSize, ret);
        
    return ret;
}
