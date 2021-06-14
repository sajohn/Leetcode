
#define SIZE 2000
struct TreeNode* queue[SIZE] = {0};


int* rightSideView(struct TreeNode* root, int* returnSize){
    
     *returnSize =0;
       if(root==NULL) 
           return NULL;
    
    struct TreeNode *pre = NULL;
    int* ret = NULL; //= (int*) calloc(1, sizeof(int*));
    
     if(root!= NULL && (root->left == NULL && root->right == NULL))
     {
           *returnSize =1;
           ret = (int*) calloc(1, sizeof(int));
           ret[0] = root->val;
           return ret;
     }
    
    int head =0, tail = 0; 
    
    tail = head;
    queue[head] = root;
    tail++;
    queue[tail++] = NULL;
    
    while(head<tail)
    {
        root = queue[head++];
       
        if(root!= NULL)
        {
              pre =  root;
       
             if(root->left)
                queue[tail++] = root->left;
              if(root->right)
                queue[tail++] = root->right;
        }
        else
        {
               ret = (int*)realloc(ret, ((*returnSize) +1)*sizeof(int));
               if(ret == NULL)
                   return NULL;  
           if(head == tail) //Because tail is always pointing to write index and this is last entry so stop
           {
               
               ret[(*returnSize)++] = pre->val;
               // printf("%d ",  ret[(*returnSize) -1]);
               break;
           }
           else 
           {
               ret[(*returnSize)++] = pre->val; 
              // printf("%d ",  ret[(*returnSize) -1]);
               queue[tail++] = NULL;
              
            }
        }
    }

    return ret;


