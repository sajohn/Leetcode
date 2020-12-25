/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


int isLeaf(struct TreeNode* root)
{
    if(root == NULL)
        return 1;
    if(root->left == NULL && root->right == NULL)
        return 1;
    return 0;
}

void preOrderSum(struct TreeNode* root, int cursum, int* buff, int idx, int* returnSize, int** returnColumnSizes, int** ret)
{
    if(root)
    {
        cursum -=root->val;
        buff[idx++] = root->val;
     
        if(cursum ==0 && isLeaf(root))
        {
        
             (*returnColumnSizes)[*returnSize] = idx;
              ret[*returnSize] = (int*)calloc( idx, sizeof(int));
              memcpy( ret[*returnSize], buff, sizeof(int)*idx );
             (*returnSize)++;
            return;
        }
        
            preOrderSum(root->left, cursum, buff, idx, returnSize, returnColumnSizes, ret);
            preOrderSum(root->right, cursum, buff, idx, returnSize, returnColumnSizes, ret);
     }
        
}

int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes)
{
    
     *returnSize = 0;

    
         
     int** ret = (int**)calloc(1000, sizeof(int*));
     *returnColumnSizes = (int*)calloc(1000, sizeof(int));
     int* buff = (int*)calloc(1000, sizeof(int));

     if(ret == NULL || *returnColumnSizes == NULL || root == NULL || buff == NULL)  
         return NULL;
     int idx =0;
    preOrderSum(root, sum, buff, idx, returnSize, returnColumnSizes, ret);
    free(buff);
    return ret;
}


