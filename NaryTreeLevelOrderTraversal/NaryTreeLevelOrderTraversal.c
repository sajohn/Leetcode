/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct QNode
{
    struct Node* node;
    struct QNode* next;
}QNode;

typedef struct Queue
{
    struct QNode* front;
    struct QNode* rear;
    
}Queue;

Queue* CreateQueue()  
{
    Queue* q = (Queue*)calloc(1, sizeof(Queue));
    
    if(q)
    {
        q->front = q->rear= NULL;
        return q;
    }
    return NULL;
} 

int IsQueueEmpty(Queue* q)
{ 
    return (q == NULL || q->front == NULL);   
}

int IsQueueFull(Queue* q)
{
    return (q == NULL);
}

void Enqueue(Queue* q, struct Node* root)
{
    if(q == NULL)
        return;
    QNode* tmp = (QNode*)calloc(1, sizeof(QNode));
    if(tmp == NULL)
        return;
    tmp->node = root;
    tmp->next = NULL;
    
    if(q->rear == NULL)
        q->rear = tmp;
    
    else
    {
      q->rear->next = tmp;
      q->rear = tmp;
    }
    if(q->front == NULL)
        q->front = q->rear;
}

QNode* Dequeue(Queue* q)
{

    if( IsQueueEmpty(q))
        return NULL;
    
    QNode* tmp;
    
    tmp = q->front;
    q->front = q->front->next;

    return tmp;    
}

void DeleteQueue(Queue* queue)
{
    if(queue== NULL)
        return;
        
    while(!IsQueueEmpty(queue))
    {
       QNode* tmpQ = Dequeue(queue);
       if(tmpQ)
       { 
        tmpQ->node = NULL;
        tmpQ->next = NULL;
        free(tmpQ);
       }
    }
    free(queue);
}

int CalSize(struct Node* root)
{
     if(root == NULL)
         return 0;
    int size =0;
    for(int i =0; i < root->numChildren; i++)
      size+= CalSize(root->children[i]);
    
    return 1+size;
}

void TraverseLevelOrder(struct Node* root, int* returnSize, int** ret,int** returnColumnSizes, Queue* queue, int* level) 
{
    if(root == NULL)
        return;
    struct Node* tmpNode = NULL;
    int size =0;
    while(!IsQueueEmpty(queue))
    {
       QNode* tmpQ = Dequeue(queue);
        
        if(tmpQ)
        {
           tmpNode= tmpQ->node;
          if(tmpNode!= NULL && tmpNode->numChildren>0)
            {
                size+= tmpNode->numChildren;
             
               if(ret[*returnSize] )
                    ret[*returnSize] = (int*)realloc(ret[*returnSize] , size*sizeof(int));
                else
                    ret[*returnSize] = (int*)calloc(size, sizeof(int));
               
              for(int i = 0; i < tmpNode->numChildren; i++)
              {
                Enqueue(queue, tmpNode->children[i]);  
                
                ret[*returnSize][size+i-tmpNode->numChildren] = tmpNode->children[i]->val;
              }
                
               level[(*returnSize)] = size;
                 *(*returnColumnSizes+*returnSize) =level[*returnSize];
   
            }
            else if(tmpNode == NULL)
            {
                if(!IsQueueEmpty(queue))
                     Enqueue(queue, NULL); 
                (*returnSize)++;
                size =0;
            }
            tmpQ->node = NULL;
            tmpQ->next = NULL;
            free(tmpQ);
            tmpNode = NULL;
         }
        
      }
     
 }
                
int** levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes) 
{
    
       if(root == NULL || returnSize == NULL )
       {
           *returnSize = 0;
           int* level = (int*)calloc(1, sizeof(int));
           *returnColumnSizes = level;
           *level =0;
          (*returnColumnSizes)[0] = *level;
          return NULL;   
       }
    
    int size = CalSize(root);
    int**ret = (int**)calloc(size, sizeof(int*));
    int* level = (int*)calloc(size, sizeof(int));
    Queue* queue = CreateQueue();
    
    *returnColumnSizes = level;
    if(queue == NULL || ret == NULL || level == NULL)
    {
        *returnSize = 0;
        *(*returnColumnSizes+*returnSize) = level[*returnSize];
        level[*returnSize] =0;
         return NULL;
    }
    
    *returnSize = 0;  
  
    if(root->children == NULL)
     {       
         *returnSize = 1;
         returnColumnSizes[0][0] = 1;
         level = root->val;
         ret[0][0] = *level;
         return ret;   
     }
     else if(root->children!=NULL )
     { 
         ret[*returnSize] = (int*)calloc(1, sizeof(int));
         ret[*returnSize][0] = root->val;
         *(*returnColumnSizes+*returnSize) = level[*returnSize];
         level[(*returnSize)++] = 1;
         Enqueue(queue, root); 
         Enqueue(queue, NULL); 
         TraverseLevelOrder(root, returnSize, ret, returnColumnSizes, queue, level);
     }
     DeleteQueue(queue);
    (*returnSize)--;
    
    return ret;
}
