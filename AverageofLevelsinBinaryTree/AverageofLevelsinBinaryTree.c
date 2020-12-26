

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

#define SIZE 20000

void levelOrderAverage(struct TreeNode* root, int* returnSize, double* ret)
{
        *returnSize =0;
       if(root==NULL) 
           return ;
    
    
    struct TreeNode* queue[SIZE] = {0};
     
     if(root!= NULL && (root->left == NULL && root->right == NULL))
     {
           ret[*returnSize] = root->val;
           *returnSize =1;
           return;
     }
    
    long head =0, tail = 0, sum = 0, count =0; 
    
    tail = head;
    queue[head] = root;
    tail++;
    queue[tail++] = NULL;
    
    while(head<tail)
    {
        root = queue[head++];

        if(root!= NULL)
        {
              
            // ret[*returnSize]= root->val;
            sum  += root->val;
            count++;
             if(root->left)
                queue[tail++] = root->left;
              if(root->right)
                queue[tail++] = root->right;
    
        }
        else
        {
            
           if(head == tail) //Queue is empty 
           {
               ret[*returnSize]= (double)(sum)/(double)(count);
               sum = 0;
               count = 0;
                (*returnSize)++;
                 break;
           }
           else 
           {
               queue[tail++] = NULL;
               
               ret[*returnSize]= (double)(sum)/(double)(count);
               sum = 0;
               count = 0;
               (*returnSize)++;
            }
        }
    }
    
}



double* averageOfLevels(struct TreeNode* root, int* returnSize){
    
    *returnSize= 0;
    
    double* ret = (double*)calloc(SIZE, sizeof(double));
    
     if(root == NULL|| ret == NULL)
        return NULL;
    
     levelOrderAverage(root, returnSize, ret);
    
    return ret;
}
