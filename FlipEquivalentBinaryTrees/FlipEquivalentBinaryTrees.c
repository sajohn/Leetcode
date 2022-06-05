/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool Helper(struct TreeNode* root1, struct TreeNode* root2){
    
    if(root1== NULL && root2 == NULL)
        return true; 
    
    if(root1 && root2){
        if(root1->val !=root2->val)
            return false;

    return ( (Helper(root1->left, root2->right) && Helper(root1->right, root2->left))  || 
                     (Helper(root1->left, root2->left) && Helper(root1->right, root2->right)) );
        
    }
    
    return false;
}


bool flipEquiv(struct TreeNode* root1, struct TreeNode* root2){
    
    
    if(root1 == NULL && root2 == NULL)
        return true; 
    
    return Helper(root1, root2);

}
