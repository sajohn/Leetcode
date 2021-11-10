/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool Helper(struct TreeNode* root)
{
    if(root == NULL)
        return true; 
    
   if(root->left && root->val != root->left->val)
        return false; 
    if(root->right && root->val != root->right->val)
        return false; 
    
    return (Helper(root->left) && Helper(root->right));
    
  
   
}

bool isUnivalTree(struct TreeNode* root){
    
    if(root == NULL)
        return true; 
    
    if(root->left == NULL && root->right == NULL)
        return true; 
    
    
    return Helper(root);

}
