struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    
   int alpha = p->val;

   int beta = q->val; 
        
          
    while(1)
    {
          if(root->val < alpha && root->val < beta) 
               root = root->right;
          else if(root->val > alpha && root->val > beta) 
             root = root->left;
          else
              return root;
    }
  return NULL;       
}
