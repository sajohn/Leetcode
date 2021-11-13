/*
// Definition for a Node.
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
};

*/


struct TreeNode* helper(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
     if(root == NULL)
       return NULL;
    
    struct TreeNode* left = NULL, *right = NULL; 
    
    if(root->val == p->val || root->val == q->val)
      return root;
    
    else
    {
       left = helper(root->left, p, q);
      
       right = helper(root->right,p, q);
           
        if(left == NULL && right == NULL)
            return NULL;
    }
      
      if(left && right)
        return root; 
      

    return (left?left:right);
    
return NULL;
}



struct Node* lowestCommonAncestor(struct Node* p,struct Node* q) {
    
    if(p == NULL)
        return q->parent; 
    if(q == NULL)
        return p->parent; 
  struct Node* pp   = p; 
  struct Node* qq   = q;  
    
    while(pp && pp->parent != NULL)
        pp = pp->parent; 
    
     while(qq && qq->parent != NULL)
        qq = qq->parent; 
    
    
   if(pp->val != qq->val)
       return NULL; 
    
    
    return helper(pp, p, q);
    
	
}
