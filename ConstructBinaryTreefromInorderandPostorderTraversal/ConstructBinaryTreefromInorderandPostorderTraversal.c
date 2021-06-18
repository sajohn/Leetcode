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
    int idxPostOrder; 
    int idxInorder; 
    UT_hash_handle hh; 
}TreeIdxHash;


struct TreeNode* buildTreeHelper(TreeIdxHash** guser, int* inorder, int inStart, int inEnd,  int* postorder,  int pStart, int pEnd){
    
      if(inorder == NULL || postorder == NULL || (inStart> inEnd) || (pStart > pEnd)) 
        return NULL; 
    
    TreeIdxHash* element = NULL;
    
    struct TreeNode* root =  (struct TreeNode*)calloc(1, sizeof( struct TreeNode));
    if(root == NULL)
        return NULL; 
    root->val = postorder[pEnd];
    
     HASH_FIND_INT(*guser, &root->val, element);
        if(element== NULL)
             return NULL; 
    
    int leftTreeSize =  element->idxInorder - inStart; 
    int rightTreesize = inEnd - element->idxInorder;
        
    root->left  = buildTreeHelper(guser, inorder, inStart, element->idxInorder-1, postorder, pStart, pStart+ leftTreeSize -1);
    root->right = buildTreeHelper(guser, inorder, element->idxInorder+1, inEnd, postorder, pEnd-rightTreesize, pEnd-1 );
    
    
    return root; 
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){

    if(inorder == NULL || postorder == NULL || inorderSize == 0 || postorderSize == 0)
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
        HASH_FIND_INT(guser, &postorder[i], element);
        if(element != NULL)
        {
            element->idxPostOrder = i; 
        } else {
            return NULL; 
        }
    }
    
    
    
    return buildTreeHelper(&guser, inorder, 0, inorderSize-1, postorder, 0 , postorderSize-1);
}
