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
    return (a>b?a:b);
}

int Height(struct TreeNode* root)
{
    if(root == NULL)
        return 0;
    
    return 1+ max(Height(root->left), Height(root->right));
}

bool isBalanced(struct TreeNode* root)
{
 
    
    if(root == NULL )
        return true;
    //Only checking isBalanced may not give result so combined condition is check height diff 
 return abs(Height(root->left) - Height(root->right)) <2 &&
           isBalanced(root->left) && isBalanced(root->right);

}
