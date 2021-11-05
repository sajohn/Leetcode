/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void Inorder(struct TreeNode* root, int** arr, int* size)
{
    
    if(root == NULL)
        return; 
    
    Inorder(root->left, arr, size);
    
    *arr = (int*)realloc(*arr, ((*size)+1)*sizeof(int));
    if(arr == NULL)
     return ; 
    
    (*arr)[(*size)++] = root->val;  
                    
    
    Inorder(root->right, arr, size);
    
}
struct TreeNode*  CreateBST(int* arr, int left, int right)
{
    if(arr == NULL || left>right )
        return NULL; 
    
    int mid = left + (right -left)/2;
    
    struct TreeNode* root = ( struct TreeNode* )calloc(1, sizeof( struct TreeNode));
    if(root == NULL)
        return NULL; 
    
    root->val = arr[mid];
    
    root->left = CreateBST(arr, left, mid-1);
    
    root->right =  CreateBST(arr,mid+1, right);
        
   return root;      
}
struct TreeNode* balanceBST(struct TreeNode* root){
    
    
    if(root == NULL)
        return NULL; 
    
    //Get sorted array
    
    int* arr = NULL; 
    int count = 0; 
    
    Inorder(root, &arr, &count);
    
    return CreateBST(arr, 0, count -1);

}
