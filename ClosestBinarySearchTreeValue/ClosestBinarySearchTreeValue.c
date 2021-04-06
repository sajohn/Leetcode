/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int closestValue(struct TreeNode* root, double target){
    
     if(root == NULL)
         return INT_MIN; 
    
    int val, closest= root->val;
   
   while(root!= NULL){
       val = root->val;
        closest = abs(val - round(target)) < abs( closest - round(target))? val:closest;
      root = round(target) < root->val? root->left:root->right; 
   }
    return closest;
}
