/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSameTree(struct TreeNode* s, struct TreeNode* t)
{
    if(s == NULL && t== NULL)
          return true;
    
    if((s == NULL && t != NULL) ||(s!= NULL && t == NULL))
        return false;
    
    if(s->val != t->val)
        return false;
    
    //Now root is same
      return (isSameTree(s->left, t->left) && isSameTree(s->right, t->right));
    
    return false;
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
      if(s == NULL && t== NULL)
          return true;
    
    if((s == NULL && t != NULL) ||(s!= NULL && t == NULL))
        return false;
    
    //if this conditino fails ==> root didn't match with t 
     if( isSameTree(s, t))
         return true;
    //So compare the left with t or right with t
    return ( isSubtree(s->left, t) || isSubtree(s->right, t));
    
}

