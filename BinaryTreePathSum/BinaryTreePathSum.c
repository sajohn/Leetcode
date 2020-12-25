
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

void helper(struct TreeNode* root, int* returnSize, int idx, int* buff, char** ret)
{
    
    if(root)
    {
        buff[idx++] = root->val;
     
        if(root->left == NULL && root->right == NULL)
        {
            
            ret[*returnSize] = (char*)calloc( 5*idx, sizeof(char));//digits could go big and negative as well 
            ret[*returnSize][0] = '\0';
            int i =0;
            for(i = 0; i< idx-1;i++)
              sprintf(  ret[*returnSize],"%s%d->",  ret[*returnSize], buff[i]);
    
            sprintf( ret[*returnSize],"%s%d", ret[*returnSize], buff[i]);
            
            (*returnSize)++;
        
            return;
        }

         helper(root->left,returnSize, idx, buff, ret );
         helper(root->right,returnSize, idx, buff, ret );
    }
}
char ** binaryTreePaths(struct TreeNode* root, int* returnSize)
{
      *returnSize =0;
      if(root == NULL)
          return NULL;
    char** ret = (char**)calloc(100, sizeof(char*));
    int* buff = (int*)calloc(100, sizeof(int));
    if(!buff || !ret)
        return NULL;
   int idx =0; 
    
   helper(root,returnSize, idx, buff, ret );
   
  free(buff);
  
  return ret;      
}

