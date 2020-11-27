/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// Online C compiler to run C program online
/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
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
 
 #include <stdio.h>
#include <stdlib.h>
 struct Node {
     int val;
     int numChildren;
     struct Node** children;
 };
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
        q->front = NULL;
        q->rear= NULL;
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
            tmpNode = NULL;
         }
        
      }
     
 }
                
int** levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes) 
{
    
       if(root == NULL || returnSize == NULL )
       {
           *returnSize = 0;
           (*returnColumnSizes)[0] = 0;
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
        // *(*returnColumnSizes+*returnSize) = level[*returnSize];
        // level[*returnSize] =0;
         (*returnColumnSizes)[0] = 0;
         return NULL;
    }
    
    *returnSize = 0;  
  
    if(root->children == NULL)
     {       
         *returnSize = 1;
         (*returnColumnSizes)[0] = 1;
         level = (int*)root->val;
         ret[0][0] = *level;
         return ret;   
     }
     else if(root->children!=NULL )
     { 
         ret[*returnSize] = (int*)calloc(1, sizeof(int));
         ret[*returnSize][0] = root->val;
       //printf("Value is %d \n",    level[(*returnSize)] );
          level[(*returnSize)] = 1;
         (*returnColumnSizes)[*returnSize] = 1;//level[*returnSize];
        // printf("Value is %d %d\n",    level[(*returnSize)] , (*returnColumnSizes)[*returnSize]);

         (*returnSize)++;
         Enqueue(queue, root); 
         Enqueue(queue, NULL); 
         TraverseLevelOrder(root, returnSize, ret, returnColumnSizes, queue, level);
     }
    DeleteQueue(queue);
    (*returnSize)--;
    
    return ret;
}

int main()
{
    struct Node* root = (struct Node *)calloc(1, sizeof(struct Node ));
    if(root == NULL)
    return -1;
    root->val =1;
    root->children = (struct Node **)calloc(3, sizeof(struct Node *));
    if(root->children == NULL)
    return -1;
    root->numChildren = 3;
    
    for(int i =0; i <root->numChildren; i++ )
    { 
        root->children[i] = (struct Node *)calloc(1, sizeof(struct Node));
        if(root->children[i] == NULL)
        return -1;
         root->children[i]->val = 2+i;
         if(i >0)
         {
          root->children[i]->children = NULL;
          root->children[i]->numChildren = 0;
         }
    }
    root->children[0]->numChildren = 2;
    
     for(int i =0; i <root->children[0]->numChildren; i++ )
    { 
        root->children[0]->children[i] = (struct Node *)calloc(1, sizeof(struct Node));
        if( root->children[0]->children[i] == NULL)
        return -1;
         root->children[0]->children[i]->val = 5+i;
        
           root->children[0]->children[i]->children = NULL;
    }
    int** returnColumnSizes; 
    int* returnSize = (int*)calloc(1, sizeof(int));
    
    int**ret =  levelOrder( root, returnSize, returnColumnSizes);

    printf("Hello World");

    return 0;
}

