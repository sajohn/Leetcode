/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool IsMirror(struct TreeNode* left, struct TreeNode* right ){
    if((left == NULL && right ) || (left && right == NULL) )
        return false;
    if(left== NULL && right == NULL)
        return true;
    
    if((left && right) && left->val == right->val )
        return (IsMirror(left->right, right->left) && IsMirror(left->left, right->right));
   
    return false;
    
}

bool isSymmetric(struct TreeNode* root){
    
    if(root == NULL || (root!= NULL && (root->left == NULL && root->right == NULL)))
        return true;
       
    return IsMirror(root->left, root->right);   

}
