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
int max = 0, count =1;  struct TreeNode* previous = NULL; 
int** result = NULL;

void traverse(struct TreeNode* root, int** result, int* returnSize) {
    
    if(root) {
        traverse(root->left, result, returnSize);
        
        if(previous != NULL) {
            if(previous->val == root->val) {
                count++; 
            }
            else{ count =1; }
        }
              
    if(count >max) {
        max = count; 
     
        *result = calloc(1, sizeof(int));
         (*returnSize)= 1; 
        (*result)[(*returnSize)-1]= root->val; 
         //printf("-- %d \n", (*result)[(*returnSize)-1]);
        
    } else if(count == max) {
        *result = realloc(*result, ((*returnSize)+1)* sizeof(int));
        (*returnSize)++; 
        (*result)[(*returnSize)-1] = root->val; 
    }
    
        previous = root; 
        traverse(root->right, result, returnSize);
    }
    
}


int* findMode(struct TreeNode* root, int* returnSize) {
    
    *returnSize = 0; 
     max = 0; count =1;  previous = NULL; 
     result = NULL;
    
    if(root == NULL)
        return NULL; 
    if(root->left == NULL && root->right == NULL){
        
        *returnSize = 1; 
        return root;
    }
        
    result = (int*)calloc(1, sizeof(int*)); 
    if(result == NULL)
        return NULL; 
 
    traverse(root, result, returnSize);
     
   
    return (*result); 
    
}
