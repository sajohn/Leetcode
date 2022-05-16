/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

long HelperCount(struct TreeNode* root, int* count){
    
    if(root == NULL)
        return 0; 
    
    long left = HelperCount(root->left, count);
    long right = HelperCount(root->right, count);
    
    if(root->val == left+right)
       (*count)++;
    
    return root->val + left+right; 
}

int equalToDescendants(struct TreeNode* root){
    
    
    if(root == NULL)
        return 1; 
    int count = 0; 
    HelperCount(root, &count);

    return count; 
}

