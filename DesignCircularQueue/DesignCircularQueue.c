


typedef struct 
{
    int front;
    int rear;
    int size; 
    int* array;
    int capacity; 
    
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);
/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) 
{
     if(k == 0)
        return NULL;
    
    MyCircularQueue* queue = (MyCircularQueue*) calloc(1, sizeof(MyCircularQueue));
    
    if(queue == NULL)
        return NULL;
    
    queue->front = queue->rear = -1;
    queue->capacity = k;
    queue->size = 0;
    queue->array = (int*)calloc(k, sizeof(int));
    if(queue->array == NULL)
        return NULL;
    
    return queue;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) 
{
  if(obj == NULL)
         return false;
    
    if(myCircularQueueIsFull(obj)) 
        return false;
    obj->rear =  (obj->rear +1) % obj->capacity; 
    obj->array[ obj->rear] = value;
    
    if(obj->front == -1)
        obj->front = obj->rear;
    
    return true;  
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) 
{
    if(obj == NULL)
         return false;
    
    if( obj->front != -1) 
    {  
        int val = obj->array[obj->front];
        
        if(obj->front == obj->rear)
            obj->front = obj->rear = -1;
        else
         obj->front = (obj->front +1) % obj->capacity;
        
        return true;
    }
    return false;  
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) 
{
  if(obj == NULL)
         return -1;
    
   if(obj->front !=-1) 
        return obj->array[obj->front];  
    
    return -1;
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) 
{
 if(obj == NULL)
         return -1;
    
 if(obj->front !=-1)
        return obj->array[obj->rear];  
    
    return -1;
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) 
{
    if(obj == NULL)
         return false;
    
   if(obj->front == -1 )
       return true;
      
      return false;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) 
{
   if(obj == NULL)
         return false;
    
   if( (obj->rear +1 )% obj->capacity == obj->front)
       return true;
    
    return false;
}

void myCircularQueueFree(MyCircularQueue* obj) 
{
      if(obj== NULL)
        return;
    
    free(obj->array);
    
    free(obj);    
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
