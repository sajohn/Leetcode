struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    
   int alpha = p->val;

   int beta = q->val; 
          
          if(root->val < alpha && root->val < beta) 
              return lowestCommonAncestor(root->right, p, q);
          else if(root->val > alpha && root->val > beta) 
              return lowestCommonAncestor(root->left, p, q);
          else
              return root;
  return NULL;        
}

