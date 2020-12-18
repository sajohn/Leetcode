

typedef struct {
    int front;
    int rear;
    int size; 
    int* array;
    int* timestamp;
    int capacity; 
} HitCounter;

/** Initialize your data structure here. */
bool myHitCounterQueueEnQueue(HitCounter* obj, int value);
bool myHitCounterQueueDeQueue(HitCounter* obj);
bool myHitCounterQueueIsEmpty(HitCounter* obj);
bool myHitCounterQueueIsFull(HitCounter* obj);

HitCounter* hitCounterCreate() 
{
    HitCounter* obj = (HitCounter*)calloc(1, sizeof(HitCounter));
    if(obj == NULL)
        return NULL;
    
    obj->front = obj->rear =-1;
    obj->size =0;
    obj->capacity = 300;
    obj->array = (int*)calloc(300, sizeof(int));
    if(obj->array == NULL)
        return NULL;
    return obj;
}

/** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
void hitCounterHit(HitCounter* obj, int timestamp) {
  if(obj == NULL || timestamp<0)
      return;
 
     myHitCounterQueueEnQueue(obj, timestamp);  

}

/** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
int hitCounterGetHits(HitCounter* obj, int timestamp) 
{
      //Based on timestamp if time > capacity return diff 
    while(!myHitCounterQueueIsEmpty(obj))
    {
        if(timestamp - obj->array[obj->front]>=300)
            myHitCounterQueueDeQueue(obj);     
        else 
            break;
    }
    return obj->size;
}

void hitCounterFree(HitCounter* obj) {
    
    if(obj == NULL)
        return;
    free(obj);
}

/** Initialize your data structure here. Set the size of the queue to be k. */


/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myHitCounterQueueEnQueue(HitCounter* obj, int value) 
{
  if(obj == NULL)
         return false;
    
        obj->rear = (obj->rear+1) % obj->capacity; 
        obj->array[obj->rear] = value;
        if( obj->front == -1)
             obj->front = obj->rear;
       
        if(obj->size != obj->capacity)
             obj->size++;
   
    return true;  
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myHitCounterQueueDeQueue(HitCounter* obj) 
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
        
        obj->size--;
        
        return true;
    }
    return false;  
}

/** Get the front item from the queue. */
int myHitCounterQueueFront(HitCounter* obj) 
{
  if(obj == NULL)
         return -1;
    
   if(obj->front !=-1) 
        return obj->array[obj->front];  
    
    return -1;
}

/** Get the last item from the queue. */
int myHitCounterQueueRear(HitCounter* obj) 
{
 if(obj == NULL)
         return -1;
    
 if(obj->front !=-1)
        return obj->array[obj->rear];  
    
    return -1;
}

/** Checks whether the circular queue is empty or not. */
bool myHitCounterQueueIsEmpty(HitCounter* obj) 
{
    if(obj == NULL)
         return false;
    
   if(obj->front == -1 )
       return true;
      
      return false;
}

/** Checks whether the circular queue is full or not. */
bool myHitCounterQueueIsFull(HitCounter* obj) 
{
   if(obj == NULL)
         return false;
    
   if( (obj->rear +1 )% obj->capacity == obj->front)
       return true;
    
    return false;
}

void myHitCounterQueueFree(HitCounter* obj) 
{
      if(obj== NULL)
        return;
    
    free(obj->array);
    
    free(obj);    
}




/**
 * Your HitCounter struct will be instantiated and called as such:
 * HitCounter* obj = hitCounterCreate();
 * hitCounterHit(obj, timestamp);
 
 * int param_2 = hitCounterGetHits(obj, timestamp);
 
 * hitCounterFree(obj);
*/
