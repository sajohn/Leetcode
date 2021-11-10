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

void FindLonelyNode(struct TreeNode* parent,struct TreeNode* root,  int* returnSize, int** ret){
    
     if(root == NULL)
         return ;
    
     FindLonelyNode(root, root->left, returnSize, ret);
     FindLonelyNode(root, root->right, returnSize, ret);
    
     if(parent!= NULL){
         int val =0; 
       if(parent->left == NULL && parent->right != NULL && parent->right->val == root->val)
           val = parent->right->val; 
        if(parent->right == NULL && parent->left != NULL && parent->left->val == root->val)
          val = parent->left->val; 
         
           if(val){  
               *ret = (int*)realloc(*ret, ((*returnSize)+1)*sizeof(int));

                 if(ret == NULL)
                     return ; 

                 (*ret)[ (*returnSize)++]  = val; 
                
           }
     }
    
    
}

int* getLonelyNodes(struct TreeNode* root, int* returnSize){
    
    
      *returnSize = 0; 
    
      int* ret = NULL; 
    
      FindLonelyNode(NULL, root, returnSize, &ret);
    
    return ret; 
}
