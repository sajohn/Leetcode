
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeIdxHash {
    
    int val; 
    int idxPreOrder; 
    int idxInorder; 
    UT_hash_handle hh; 
}TreeIdxHash;


struct TreeNode* buildTreeHelper(TreeIdxHash** guser, int* inorder, int inStart, int inEnd,  int* preorder,  int pStart, int pEnd){
    
      if(inorder == NULL || preorder == NULL || (inStart> inEnd) || (pStart > pEnd)) 
        return NULL; 
    
    TreeIdxHash* element = NULL;
    
    struct TreeNode* root =  (struct TreeNode*)calloc(1, sizeof( struct TreeNode));
    if(root == NULL)
        return NULL; 
    root->val = preorder[pStart];
    
     HASH_FIND_INT(*guser, &root->val, element);
        if(element== NULL)
             return NULL; 
    
    int leftTreeSize =  element->idxInorder - inStart; 
    int rightTreesize = inEnd - element->idxInorder;
        
    root->left  = buildTreeHelper(guser, inorder, inStart, element->idxInorder-1, preorder, pStart+1, pStart+ leftTreeSize );
    root->right = buildTreeHelper(guser, inorder, element->idxInorder+1, inEnd, preorder, pEnd-rightTreesize+1, pEnd );
    
    
    return root; 
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {

    if(inorder == NULL || preorder == NULL || inorderSize == 0 || preorderSize == 0)
        return NULL; 
    
    TreeIdxHash* guser = NULL, *element= NULL; 
   //Inorder 
    for(int i =0; i< inorderSize; i++)
    {
        HASH_FIND_INT(guser, &inorder[i], element);
        if(element == NULL)
        {
            element = (TreeIdxHash*)calloc(1, sizeof(TreeIdxHash));
            element->val = inorder[i];
            element->idxInorder = i; 
            HASH_ADD_INT(guser, val, element);
        }
    }
    //Postorder
    for(int i =0; i< inorderSize; i++)
    {
        HASH_FIND_INT(guser, &preorder[i], element);
        if(element != NULL)
        {
            element->idxPreOrder = i; 
        } else {
            return NULL; 
        }
    }
    
    
    
    return buildTreeHelper(&guser, inorder, 0, inorderSize-1, preorder, 0 , preorderSize-1);
}
