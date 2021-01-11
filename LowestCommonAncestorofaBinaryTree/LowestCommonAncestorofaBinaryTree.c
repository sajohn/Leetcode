/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* helper(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q, struct TreeNode* ans)
{
     if(root == NULL)
       return NULL;
    
    struct TreeNode* left = NULL, *right = NULL; 
    
    if(root->val == p->val )
       return root;
 
    else if(root->val == q->val)
      return root;
    
    else
    {
       left = helper(root->left, p, q, ans);
       right = helper(root->right,p, q, ans);
           
        if(left == NULL && right == NULL)
            return NULL;
    }
      
      if(left && right)
      {
          ans = root;
          return ans;
      }
    if(left && !right )
        return left; 
    if(!left && right )
        return right; 
    
return NULL;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
  
    if(root== NULL)
        return NULL;
  struct TreeNode ans = {0}; 
    return helper(root, p, q, &ans); 

