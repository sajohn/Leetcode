/*
// Definition for a Node.
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};
*/


void Inorder(struct Node *root, struct Node** head,struct Node** ret )
{
    if(root == NULL)
        return; 
    Inorder(root->left, head, ret);
    
    if((*head) == NULL){
        
        (*ret) = root; 
        (*head) = root;
    }
    else
    {
       (*head)->right = root; 
        root->left = (*head); 
        (*head) = (*head)->right; 

    }

    Inorder(root->right, head, ret);
    
}


struct Node* treeToDoublyList(struct Node *root) {
    
 struct Node* cur = NULL, *ret; 
    
    if(root == NULL)
        return NULL; 
    
  Inorder(root, &cur, &ret);
    
    return ret; 
}
