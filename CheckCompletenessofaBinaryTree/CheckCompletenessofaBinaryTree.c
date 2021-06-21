/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isCompleteTree(struct TreeNode* root){
    
    if(root == NULL)
        return true; 
    
    struct TreeNode* queue[200]; 
    int head = 0, tail = 0; 
    
    queue[head] = root; 
    tail = head; 
 
    
    bool isCompleteTree = false; 
    
    while(head< tail || queue[head]!= NULL) {
        
        root = queue[head++];
        
        if(root == NULL) 
        {
            isCompleteTree = true; //First node found that is null should be last node...
        } else {
            
            if(isCompleteTree == true)
              return false; 
 
              queue[++tail] = root->left; 
              queue[++tail] = root->right; 
            
        }
    
    }
    
    
return true; 
    
}
