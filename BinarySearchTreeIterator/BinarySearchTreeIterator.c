/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



typedef struct {
    int* arr;
    int next;
    int size;
    
} BSTIterator;


void inorder(BSTIterator* bst, struct TreeNode* root){
    
    if(bst == NULL || root == NULL)
        return ;
    
    inorder(bst, root->left);
    bst->arr = (int*)realloc(bst->arr, (bst->next+1)*sizeof(int));
    if(bst->arr == NULL)
        return ; 
    
    bst->arr[(bst->next)++] = root->val; 
    inorder(bst, root->right);
    
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
   if(root == NULL)
       return NULL; 
    
    BSTIterator* bst = (BSTIterator*)calloc(1, sizeof(BSTIterator));
    if(bst == NULL)
        return NULL; 
    bst->arr = NULL;
    inorder(bst, root);
    bst->size = bst->next;
    bst->next = 0; 
    return bst; 
}

int bSTIteratorNext(BSTIterator* obj) {

      return obj->arr[obj->next++];
 
}

bool bSTIteratorHasNext(BSTIterator* obj) {
  
    if(obj == NULL)
        return false; 
    if(obj->next >=0 && obj->next < obj->size)
        return true; 
    
    return false; 
}

void bSTIteratorFree(BSTIterator* obj) {
    
    if(obj== NULL)
        return; 
    free(obj->arr);
    free(obj);
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 
 * bool param_2 = bSTIteratorHasNext(obj);
 
 * bSTIteratorFree(obj);
*/
