/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void findSum(struct TreeNode* root, int sum, int* count)
{
    if(root == NULL)
        return;
    if(root->val == sum )
        (*count) = *count +1;

    findSum(root->left, sum-root->val, count );
     findSum(root->right, sum-root->val, count); 

}

int pathSum(struct TreeNode* root, int sum)
{
    if(root == NULL )
        return 0;
     int* count = calloc(1, sizeof(int));   
    
    //Find sum on left without root
    //Find sum on right without root
   int val = pathSum(root->left, sum)+ 
         pathSum(root->right, sum) ;
   
    
    //Find sum with root on left
    //Find sum with root on right
     
    findSum(root, sum, count );  
    
    return val+ (*count);
}
