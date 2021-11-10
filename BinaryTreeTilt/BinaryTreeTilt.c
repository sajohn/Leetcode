/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int SumofTree(struct TreeNode* root, int* sum ){
 
    if(root == NULL)
        return 0; 
    
    
     int left  = SumofTree(root->left, sum);
     int right = SumofTree(root->right, sum);
    
        *sum += abs(left-right);
     
    return root->val + left+right; 
}

int findTilt(struct TreeNode* root){
    
   int sum = 0;

     SumofTree(root, &sum); 
    return sum; 
}
