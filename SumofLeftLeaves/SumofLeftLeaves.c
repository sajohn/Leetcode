/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void Helper(struct TreeNode* root, int* sum, int dir){
    
    if(root== NULL )
        return ;
    if(root->left){
        dir = 0;
         Helper(root->left, sum,  dir);
    }
    if(root->right){
        dir = 1; 
            Helper(root->right, sum,  dir);
    }
    
    if(root->left == NULL && root->right == NULL)
        if(dir == 0)
            *sum += root->val; 
    
    
    
    
}

int sumOfLeftLeaves(struct TreeNode* root){

    int sum = 0;
     Helper(root, &sum, -1);
    return sum; 
}
