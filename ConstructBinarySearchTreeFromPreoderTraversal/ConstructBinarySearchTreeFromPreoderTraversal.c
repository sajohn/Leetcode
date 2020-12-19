/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int getIndex(int* preorder, int preorderSize)
{ 
    int i =0;
   for( i = 1; i < preorderSize; i++ )
   {
       if(preorder[0]>preorder[i])
           continue;
        else
            break;
   }

    return i;
}


struct TreeNode* bstFromPreorder(int* preorder, int preorderSize)
{

   if(preorder == NULL || preorderSize == 0)
       return NULL;
    
   struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if(!root)
        return NULL;
    
    root->val = preorder[0];
    
    if(preorderSize ==1)
    {
        root->left = root->right = NULL;
        return root;
    }
    
    int i = getIndex(preorder,preorderSize);
    
    if(i==1) //We could never move to find left tree element so left is null
        root->left = NULL;
    else 
        root->left = bstFromPreorder(preorder+1, i-1);
     
    
    if(i<preorderSize) //If i didn't move then this is a right index 
        root->right = bstFromPreorder(preorder+i, preorderSize-i);    
    else 
        root->right = NULL;  //This is the case where only left skewed tree or leaf node is hit....
    
    return root;
}
