/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int isLeaf(struct TreeNode* root)
{
    if(root == NULL)
        return 1;
    if(root->left == NULL && root->right == NULL)
        return 1;
    return 0;
}

void preOrderSum(struct TreeNode* root, int cursum, int* sum, int target)
{
    if(root)
    {
       cursum = cursum+root->val;
        if(isLeaf(root))
        {
            if(cursum == target)
                *sum =1;
           else
              cursum -=root->val;
        }
        else
        {
            preOrderSum(root->left, cursum, sum, target);
             preOrderSum(root->right, cursum, sum, target);
        }
     } 
}

bool hasPathSum(struct TreeNode* root, int target)
{
    int sum =0;
    preOrderSum(root, 0, &sum, target);
    return (sum ==1? true:false); 
}
