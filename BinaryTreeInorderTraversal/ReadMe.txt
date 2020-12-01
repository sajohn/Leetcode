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



int CalSize(struct TreeNode* root)
{
     if(root == NULL)
         return 0;
    int size =0;
   
   return 1+ CalSize(root->left)+ CalSize(root->right);
}



void inorderTraversalHelper(struct TreeNode* root, int* returnSize, int* ret)
{
   
        if(root)
        {
            inorderTraversalHelper(root->left, returnSize, ret);
            ret[(*returnSize)++] = root->val;
            inorderTraversalHelper(root->right, returnSize, ret);  
        }
}


int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
     *returnSize = 0;
    if(root == NULL || returnSize ==0)
        return NULL;
  
    int size = CalSize(root);
    
  
    int* ret = (int*) calloc(size, sizeof(int));
    if(ret == NULL)
        return NULL;
     
    if(size ==1)
    {
        *returnSize =1;
        ret[0] = root->val;
        return ret;
    }
    inorderTraversalHelper(root, returnSize, ret);
  
    return ret;
    
Validate Binary Search Tree
Medium
Binary Tree Preorder Traversal
Medium
Binary Tree Postorder Traversal
Medium
Binary Search Tree Iterator
Medium
Kth Smallest Element in a BST
Medium
Closest Binary Search Tree Value II
Hard
Inorder Successor in BST
Medium
Convert Binary Search Tree to Sorted Doubly Linked List
Medium
Minimum Distance Between BST Nodes
Easy}
