/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void Helper(struct TreeNode* root,struct TreeNode* parent, int current, int* max){
    
    if(root == NULL )
        return ;
    
    
    //if parent == NULL then height is one (left and right ) to begin with 
    // else diff between prent and current node is one then sequnce +1 else check left check right 
    
    current = ((parent != NULL && parent->val +1 == root->val)? current +1: 1);
    if(current> *max)
        *max = current; 
    //With this current value go anywhere (i.e. left or right)
     Helper(root->left, root, current, max);
     Helper(root->right, root, current, max);
    
}


int longestConsecutive(struct TreeNode* root){
    if(root == NULL)
        return 0; 
    int max = 0, current =0;
    
    Helper(root, NULL, current, &max);
    
    return max; 
    
}
