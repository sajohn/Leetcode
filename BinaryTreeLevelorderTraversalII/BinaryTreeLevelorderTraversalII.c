
void Reverse(int** ret, int* returnSize, int** returnColumnSizes)
{
     
     int l=0, r = (*returnSize)-1, size = 0;
    int* tmp = NULL;
    while(l<=r)
    {
        tmp = ret[l];
        size =   (*returnColumnSizes)[l]; 
        (*returnColumnSizes)[l] =  (*returnColumnSizes)[r]; 
        ret[l++] = ret[r];
        (*returnColumnSizes)[r] = size;
        ret[r--] = tmp;
        
    }
    
}


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

#define SIZE 2000

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
        *returnSize =0;
       if(root==NULL) 
           return NULL;
    
    
    struct TreeNode* queue[SIZE] = {0};
    int** ret = (int**) calloc(SIZE, sizeof(int*));
     *returnColumnSizes = (int*)calloc(SIZE, sizeof(int));
    if(ret== NULL)
        return NULL;
    
     if(root!= NULL && (root->left == NULL && root->right == NULL))
     {
           ret[*returnSize] = (int*)calloc(1, sizeof(int));
           (*returnColumnSizes)[*returnSize] = 1;
           ret[*returnSize][*returnSize] = root->val;
            *returnSize =1;
           return ret;
     }
    
    int head =0, tail = 0; 
    
    tail = head;
    queue[head] = root;
    tail++;
    queue[tail++] = NULL;
    
    
    while(head<tail)
    {
        root = queue[head];
       
        head++;
        if(root!= NULL)
        {
           if( ret[*returnSize] == NULL)
           {
               ret[*returnSize] = (int*)calloc(1, sizeof(int));
              
                (*returnColumnSizes)[*returnSize] = 1;
 
           }
           else
           {
              ret[*returnSize] = (int*)realloc(ret[*returnSize],  ((*returnColumnSizes)[*returnSize]+1)*sizeof(int) );
              (*returnColumnSizes)[*returnSize] += 1;
            }
             ret[*returnSize][((*returnColumnSizes)[*returnSize])-1 ] = root->val;
             if(root->left)
                queue[tail++] = root->left;
              if(root->right)
                queue[tail++] = root->right;
    
        }
        else
        {
            
           if(head == tail) //Queue is empty 
               break;
           else 
           {
               queue[tail++] = NULL;
               (*returnSize)++;
            }
        }
    }
    (*returnSize)++;
    
    Reverse(ret, returnSize, returnColumnSizes);
  
    return ret;
}
