/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool isLeaf(struct TreeNode* root){
    if(root == NULL)
        return true; 
    
    if(root->left == NULL && root->right == NULL)
        return true; 
    return false; 
    
}
void PreOrderLeft(struct TreeNode* root, int* returnSize, int dir, int** ret){
    
    if(root == NULL)
        return; 
    
    if(isLeaf(root))
        return; 
        
        if(dir == 1 )
        {
            
            *ret = (int*)realloc(*ret, ((*returnSize)+1)*sizeof(int)); 
            (*ret)[(*returnSize)++] = root->val; 
            
        }
    if(root->left)
         PreOrderLeft(root->left, returnSize, dir, ret);
    if(root->left == NULL && root->right)
       PreOrderLeft(root->right, returnSize, dir, ret);    
    
}
void PreOrderRight(struct TreeNode* root, int* returnSize, int dir, int** ret){
    
    if(root == NULL)
        return; 
    
    if(isLeaf(root))
        return; 
        
        if(dir == 2 )
        {
            
           *ret = (int*)realloc(*ret, ((*returnSize)+1)*sizeof(int)); 
             printf("%d ", root->val);
            (*ret)[(*returnSize)++] = root->val; 
        }
    if(root->right)
         PreOrderRight(root->right, returnSize, dir, ret);
    if(root->right == NULL && root->left)
       PreOrderRight(root->left, returnSize, dir, ret);    
    
}

void GetLeaves(struct TreeNode* root, int* returnSize, int dir, int** ret){
        if(root == NULL)
        return; 
    
    if(isLeaf(root) && dir == 0)
    {
        *ret = (int*)realloc(*ret, ((*returnSize)+1)*sizeof(int)); 
         
        (*ret)[(*returnSize)++] = root->val; 
 
    }
    
    GetLeaves(root->left, returnSize, 0, ret);
    GetLeaves(root->right, returnSize, 0, ret);
}

int* boundaryOfBinaryTree(struct TreeNode* root, int* returnSize){
    *returnSize = 0; 
    if(root == NULL)
        return NULL; 
    
    int* ret = calloc(1, sizeof(int));
     ret[(*returnSize)++] = root->val; 
    
    if(isLeaf(root))
        return ret; 
    
    if(root->left)
        PreOrderLeft(root->left, returnSize, 1, &ret);
       
    GetLeaves(root, returnSize, 0, &ret);
    
    int idx = *returnSize ; 
  
    if(root->right)
        PreOrderRight(root->right, returnSize, 2, &ret);
    int start = idx, end = (*returnSize)-1; 
    while(start < end){
        
        int tmp = ret[start];
        ret[start] = ret[end];
        ret[end] = tmp; 
        start++; end--; 
    }
    
return ret; 
}
