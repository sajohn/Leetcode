/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int GetLength(struct TreeNode* root, int* max)
{
    if(root == NULL)
        return 0;
  
   int left=0, right=0;
    left = GetLength(root->left, max);
    right =  GetLength(root->right, max); 
    
   int maxLeftSofar =0 , maxRightSofar =0;
    
    if(root->left != NULL && root->val == root->left->val)
         maxLeftSofar += left+ 1;
    if(root->right != NULL && root->val == root->right->val)
         maxRightSofar += right+ 1;
    
       *max = (*max<(maxLeftSofar+maxRightSofar)?(maxLeftSofar+maxRightSofar) : *max);
    return (maxRightSofar>maxLeftSofar?maxRightSofar:maxLeftSofar);
}


int longestUnivaluePath(struct TreeNode* root)
{
    
    if(root == NULL)
        return 0;
    
    int max =0;
    GetLength(root, &max);
  
    return max;
    
    
}
