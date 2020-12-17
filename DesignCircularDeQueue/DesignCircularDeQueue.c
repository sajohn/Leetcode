

typedef struct {
    int front;
    int rear;
    int size; 
    int* array;
    int capacity; 
    
} MyCircularDeque;

/** Initialize your data structure here. Set the size of the deque to be k. */
bool myCircularDequeIsEmpty(MyCircularDeque* obj);
bool myCircularDequeIsFull(MyCircularDeque* obj);

MyCircularDeque* myCircularDequeCreate(int k) 
{
  if(k == 0)
        return NULL;
    
    MyCircularDeque* queue = (MyCircularDeque*) calloc(1, sizeof(MyCircularDeque));
    
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

/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) 
{
  if(obj == NULL || myCircularDequeIsFull(obj)) 
        return false;
    
    if(myCircularDequeIsEmpty(obj) || obj->front == -1)
    {
        obj->front =  (obj->front +1) % obj->capacity; 
        obj->array[obj->front] = value;  
        obj->rear = obj->front;
        obj->size++;
        return true;
    }
    else if(!myCircularDequeIsFull(obj))
    {
           obj->front =  (obj->front -1 +obj->capacity) % obj->capacity; 
            obj->array[obj->front] = value;  
            obj->size++;
            return true;
        
    }
    
    return false;
}

/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) 
{
     if(obj == NULL|| myCircularDequeIsFull(obj)) 
        return false;
    
    if(myCircularDequeIsEmpty(obj))
    {
        obj->front =  (obj->front +1) % obj->capacity; 
        obj->array[obj->front] = value;
        obj->rear = obj->front;
        obj->size++;
        return true;
    }
    else if(!myCircularDequeIsFull(obj))
    {
         obj->rear =  (obj->rear +1) % obj->capacity; 
         obj->array[ obj->rear] = value;
        obj->size++;
        return true;
    }
    
    return false; 
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteFront(MyCircularDeque* obj) 
{
   if(obj == NULL || myCircularDequeIsEmpty(obj))
        return false;

    int value = obj->array[obj->front % obj->capacity]; 
    obj->front = (obj->front +1 + obj->capacity )% obj->capacity; 
    obj->size--;
    return  true;
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteLast(MyCircularDeque* obj) 
{

     if(obj == NULL || myCircularDequeIsEmpty(obj))
        return false;
    
    int value = obj->array[obj->rear%obj->capacity]; 
    obj->rear = (obj->rear -1 + obj->capacity )% obj->capacity; 
    obj->size--;
    return  true;
}

/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque* obj) 
{
    if(obj == NULL|| myCircularDequeIsEmpty(obj))
        return -1;
    
    return obj->array[obj->front%obj->capacity];
    
}

/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque* obj) 
{
  if(obj == NULL || myCircularDequeIsEmpty(obj))
        return -1;
    return obj->array[obj->rear%obj->capacity]; 
}

/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque* obj) 
{
   if(obj == NULL)
         return false;
    
  if(obj->size == 0)
       return true;
    
    return false;
}

/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque* obj) 
{
    if(obj == NULL)
         return false;
    
   if(obj->capacity == obj->size)
       return true;
    
    return false;
  
}

void myCircularDequeFree(MyCircularDeque* obj) 
{
    if(obj)
    {
     free(obj->array);
     free(obj);
    }
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/

