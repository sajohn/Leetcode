struct TreeNode* findMinBST(struct TreeNode* root)
{
    if(root== NULL)
        return NULL;
    else if(root->left == NULL)
        return root;
    else return findMinBST(root->left);
}
struct TreeNode* findMaxBST(struct TreeNode* root)
{
    if(root== NULL)
        return NULL;
    else if(root->right == NULL)
        return root;
    else return findMaxBST(root->right);
}

struct TreeNode* deleteNode(struct TreeNode* root, int key){
    
    if(root == NULL)
        return NULL; 

    if(root->val == key)
    {
        //Leaf node
        if(root->left == NULL &&  root->right == NULL){
            free(root);
          return NULL;
        }
        //Left and Right
        else if(root->left && root->right)
        {
            //Go to max/min node on left of right sub tree and replace its value with 
            
            struct TreeNode* tmp = findMaxBST(root->left);
            
            root->val = tmp->val;
            
            root->left = deleteNode(root->left, root->val);
                
        }
        //Left only
        else if(root->left && root->right == NULL){
              struct TreeNode* tmp = root;
            root = root->left; 
            free(tmp);
        }
        //Right only
        else if(root->left == NULL && root->right){
              struct TreeNode* tmp = root; 
            
            root = root->right; 
            free(tmp);
        }
    
    }
    else if(root->val < key)
    {
        root->right = deleteNode(root->right, key);
    }
    else  if(root->val > key)   
    {
        root->left =  deleteNode(root->left, key);
    }
    
    return root; 
    
}

