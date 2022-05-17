/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct Node{
    double sum; 
    int count; 
}Node; 


 Node* Helper(struct TreeNode* root, double* avg){
    
    if(root == NULL){
        return NULL; 
    }
    
    
  
    Node* leftsum = Helper(root->left, avg);
    Node* rightsum = Helper(root->right, avg);

  
        
    Node* node = (Node*)calloc(1, sizeof(Node));
     if(node == NULL)
         return NULL; 
     
     int totalcount = 1 + (leftsum? leftsum->count: 0) + (rightsum ? rightsum->count: 0);
     double totalsum  = root->val + (leftsum? leftsum->sum :0)+ (rightsum? rightsum->sum : 0);
     
     node->sum =(double) totalsum ; 
     node->count = totalcount; 
     
     if(*avg < (node->sum/node->count) )
         *avg = (node->sum/node->count); 
     
    return node; 
}
double maximumAverageSubtree(struct TreeNode* root){
    
    
    if(root == NULL)
        return 0.0;
  
    double maxavg = 0.0; 
    
    Helper(root, &maxavg);

    return maxavg; 
}
