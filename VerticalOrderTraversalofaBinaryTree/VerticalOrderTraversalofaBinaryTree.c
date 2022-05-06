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
typedef struct {
    int row; 
    int column; 
    int value; 
}Point;

struct hashNode {
    int key; 
    Point* val;
    int size;
    UT_hash_handle hh;
};

// struct hashNode *findUser(struct hashNode **g_users, int key) {
//     struct hashNode *s;
//     HASH_FIND_INT(*g_users, &key, s);
//     return s;
// }
// int* GetUserVal( struct hashNode **g_users, int key) {
//     struct hashNode *s;
//     HASH_FIND_INT(*g_users, &key, s);
//     return s->val;
// }
void AddUser(struct hashNode **g_users, int row, int column, int sum) {
    struct hashNode *s;
    HASH_FIND_INT(*g_users, &column, s);
    if (s == NULL) {
        struct hashNode *s = (struct hashNode *)calloc(1, sizeof(*s));
        s->key = column;
        s->size = 1;
        if(s->val== NULL)
            s->val = (Point*)realloc(s->val, sizeof(Point)*(s->size));
        
           s->val[s->size -1].value = sum;
         s->val[s->size -1].row = row; 
         s->val[s->size -1].column = column;
        HASH_ADD_INT(*g_users, key, s);
    } else {
      s->size +=1;  
      s->val = (Point*)realloc(s->val, sizeof(Point)*(s->size));
      s->val[s->size -1].value = sum;
      s->val[s->size -1].row = row; 
      s->val[s->size -1].column = column;
    }    
}
struct Enqueue
{
    struct TreeNode* root;
    int column;
    int row; 
};

void HelperLevelOrder(struct TreeNode* root, struct hashNode **g_users)
{
    
   struct Enqueue *queue;//[2000] = {0}; //(struct Enqueue*)calloc(1, sizeof( struct Enqueue));
    
    int head =0, tail = 0, row = 0, column =0, size =0; 
  
    tail = head;
    queue = (struct Enqueue*)calloc(1, sizeof( struct Enqueue));
    queue[tail].root = root;
    queue[tail].row = 0;
    queue[tail++].column = 0;

    while(head<tail)
    {
        root = queue[head].root;
        row = queue[head].row;
        column = queue[head++].column;
        
        if(root!= NULL)
        {
           AddUser(g_users, row, column, root->val);
  
             if(root->left)
             {
                queue =  (struct Enqueue*)realloc(queue,(tail+1)*sizeof( struct Enqueue));  
                queue[tail].root = root->left;
                queue[tail].row = row+1;
                queue[tail++].column = column-1; 

             }
              if(root->right)
              {
                queue =  (struct Enqueue*)realloc(queue,(tail+1)*sizeof( struct Enqueue));  
                queue[tail].root = root->right;
                queue[tail].row = row+1;  
                queue[tail++].column = column+1;
              }
        }
        else
        {
            
           if(head == tail)
               break;
         
        }
    }
    free(queue);
}


void Helper(struct TreeNode* root, int row, int column, struct hashNode **g_users)
{
    
   if(root == NULL)
       return;
    AddUser(g_users, row, column, root->val);
    Helper(root->left, row+1, column-1, g_users);
    Helper(root->right, row+1, column+1, g_users);
    
}
int sortFuncCol(struct hashNode *a, struct hashNode *b) {
    return (a->key- b->key);
}

int sortFuncRow( Point *a,  Point *b) {
    
   if(a->column == b->column){
       
       if(a->row == b->row)
       {
           return (a->value - b->value);
       }
   }
    
  return 0; 
}


int** verticalTraversal(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    *(returnSize) = 0;
     
    if(root== NULL){
        (*returnColumnSizes)[ *(returnSize)] = 0;
        return NULL;}
    
    int** ret = (int**)calloc(50, sizeof(int*));
    (*returnColumnSizes) =  (int*)calloc(50, sizeof(int));
    
      struct hashNode *g_users= NULL, *element; 
    
    
    HelperLevelOrder(root, &g_users);
    HASH_SORT(g_users, sortFuncCol);

    
     struct hashNode *current_user, *tmp;
     HASH_ITER(hh, g_users, current_user, tmp) {
         
         ret[*returnSize] = (int*)calloc(current_user->size, sizeof(int));
        
         qsort(current_user->val, current_user->size, sizeof(Point ), sortFuncRow );
         
         for(int i =0; i < current_user->size; i++)
             ret[*returnSize][i]= current_user->val[i].value;
              

          (*returnColumnSizes)[(*returnSize)++] = current_user->size;
    
          
    HASH_DEL(g_users, current_user);  /* delete it (users advances to next) */
    free(current_user);             /* free it */
  }
  
    return ret;
}
