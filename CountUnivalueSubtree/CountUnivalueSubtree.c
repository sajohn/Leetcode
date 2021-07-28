/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int count = 0; 


bool IsUniValue(struct TreeNode* root, int* count){
    
    if(root) {
        if( root->left == NULL && root->right == NULL){
            (*count)++; 
            return true; 
        }
    }
    bool isTrue = true; 
        
      if( root->left) {
                 isTrue = isTrue && (root->left->val == root->val);
                 bool tmp =  IsUniValue(root->left, count); 
                isTrue = isTrue && tmp; 
      }
        
      if(root->right) {
                isTrue = isTrue &&  (root->right->val == root->val);
                bool tmp  = IsUniValue(root->right, count);
               isTrue = isTrue && tmp; 
      }
       
        if(!isTrue)
           return false; 
    
         (*count)++; 
           return true;  
    
}

int countUnivalSubtrees(struct TreeNode* root){
    
    if(root == NULL)
        return 0; 
    int count = 0; 
    IsUniValue(root, &count);
          
    return count; 
}
