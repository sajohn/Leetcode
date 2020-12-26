/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int Max(int a, int b)
{
    return (a>b? a:b);
}

int maxPathSumHelp(struct TreeNode* root, int* max)
{
    
    if(root == NULL)
        return 0;
       
    int left = Max(maxPathSumHelp(root->left, max),0);
    int right =  Max(maxPathSumHelp(root->right, max), 0);
        
     *max = Max( *max, left+root->val+right);
    
    //Else return max of value with current node of its right or left
   //This is the path which determines the max path but the above code just updates max out of current node     
    return root->val + Max(left, right);
}

int maxPathSum(struct TreeNode* root){
    
    if(root == NULL)
        return 0;
    
    int max = INT_MIN;
    
    maxPathSumHelp(root, &max);
    
    return max;

}
