/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void countNode(struct TreeNode* root, int max, int* count){
    
if(root) {
        if(root->val >=max) {
            max = root->val;
            (*count)++; 
        }
            countNode(root->left, max, count);
            countNode(root->right , max, count);
   }
    
}

int goodNodes(struct TreeNode* root){
    
    if(root == NULL)
        return 0; 
    
   int count = 0; 
    
    if(root->left == NULL && root->right == NULL)
        return 1;
    
    countNode(root, root->val, &count);
    
   return count;
}
