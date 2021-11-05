/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void SumOfRange(struct TreeNode* root, int low, int high, int* result){
    
    if(root == NULL)
        return 0; 
    
       SumOfRange(root->left, low, high, result);
       SumOfRange(root->right, low, high, result); 
    
      if(root->val >= low && root->val <=high )
         (*result)  +=root->val;
    
    return;
}



int rangeSumBST(struct TreeNode* root, int low, int high){
    
    if(root == NULL)
        return 0;
    int result = 0; 
     SumOfRange(root, low, high, &result);

    return result; 
}
