/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 
 
 */

//preorder = root left right 

void Helper(struct TreeNode* root, char* ret)
{
    int idx = 0;
    if(root == NULL)
        return;
    
    
      idx +=sprintf(ret+idx, "%d", root->val);
    
        if(root->left == NULL && root->right == NULL)
            return ;
    else{

             idx +=sprintf(ret+idx, "(");
                Helper(root->left,  ret+idx);
                 idx +=sprintf(ret+strlen(ret), ")");
        
        if(root->right)
        {
          idx +=sprintf(ret+strlen(ret), "(");
          Helper(root->right,  ret+strlen(ret));
          idx +=sprintf(ret+strlen(ret), ")");
            
        }
    return;
    }
}

char * tree2str(struct TreeNode* root)
{
    if(root == NULL)
        return "";
    char* ret = (char*)calloc(1024*1024, sizeof(char));
    
    if(ret == NULL)
        return NULL;
    Helper(root, ret);
    
    
    
    return ret;
}
