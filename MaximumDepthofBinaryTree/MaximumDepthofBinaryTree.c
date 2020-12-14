/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a, int b)
{
    return (a>b? a:b);
}

int maxDepth(struct TreeNode* root){

    int depth =0;
    if(root)
        depth = 1+ max(maxDepth(root->left), maxDepth(root->right));
    
    
    return depth;
}
