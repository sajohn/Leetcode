/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int isLeaf(struct TreeNode* root)
{
    if(root == NULL)
        return 1;
    
    if(root->left == NULL && root->right == NULL)
        return 1;
    
    return 0;
}


struct TreeNode* removeLeafNodes(struct TreeNode* root, int target)
{
    //Traverse in left and traverse in right to find a target with leaf
    //If found Delete and return 
    //If after a return node becomes leave delete and repeat else return
    
    
    if(root)
    {
         if(root->val == target && isLeaf(root))
        {
              free(root);
             return NULL;
        }
        else
        { 
            if(root->left)
                root->left = removeLeafNodes(root->left, target);
            
            if(root->right)
                 root->right =  removeLeafNodes(root->right, target);
            
           if(root->val == target && isLeaf(root))
                return removeLeafNodes(root, target);
            else
                return root;
        }
    }
     return NULL;
}
