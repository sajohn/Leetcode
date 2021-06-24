
typedef struct Stack{
    
    int top; 
    int* arr; 
}Stack;

typedef struct {
    
    Stack Spush;
    Stack Spop;

} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*)calloc(1, sizeof(MyQueue));
    if(q == NULL)
        return NULL; 
    
    q->Spush.top = -1; 
    q->Spop.top = -1; 
    
    return q; 
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    
    if(obj == NULL)
        return ; 
    
    if(obj->Spop.top == -1 ) {
        
        if(obj->Spush.top == -1) {
            
            obj->Spop.arr = (int*)realloc(obj->Spop.arr, (++(obj->Spop.top) +1)*sizeof(int));
            obj->Spop.arr[obj->Spop.top] = x; 
            
            return; 
        
        } else {
            
            //Pop is empty but Push is not to add to push then pop all element to Pop stach
            
             obj->Spush.arr = (int*)realloc( obj->Spush.arr, (++(obj->Spush.top) +1) *sizeof(int));
             obj->Spush.arr[obj->Spush.top] = x; 
            
            while(obj->Spush.top != -1)
            {
              obj->Spop.arr = (int*)realloc(obj->Spop.arr, (++(obj->Spop.top) +1)*sizeof(int));
              obj->Spop.arr[obj->Spop.top] =  obj->Spush.arr[obj->Spush.top--] ; 
                
               //obj->Spush.top--; 
            }
            
        }
        
     } else {
          
             obj->Spush.arr = (int*)realloc( obj->Spush.arr, (++(obj->Spush.top) +1) *sizeof(int));
             obj->Spush.arr[obj->Spush.top] = x; 
    }
  
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    
      if(obj == NULL)
        return INT_MIN;
    
   if(obj->Spop.top == -1 && obj->Spush.top == -1) {
       return INT_MIN; 
   }
    else if(obj->Spop.top == -1 && obj->Spush.top != -1)
    {
       while(obj->Spush.top != -1)
       {
           
        obj->Spop.arr = (int*)realloc( obj->Spop.arr, (++(obj->Spop.top) +1)* sizeof(int));
        obj->Spop.arr[obj->Spop.top] = obj->Spush.arr[(obj->Spush.top)--]; 
           //printf("%d", obj->Spop.arr[obj->Spop.top]);
       }
        return  obj->Spop.arr[obj->Spop.top--];
        
    } else if(obj->Spop.top != -1 ) {
         return  obj->Spop.arr[obj->Spop.top--];
    }
      
    return INT_MIN; 
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
  
    if(obj)
    {
         if(obj->Spop.top == -1 )
         {
             if(obj->Spush.top == -1 )
             {
                 return INT_MIN;
             } else {
               
                while(obj->Spush.top != -1)
               {

                obj->Spop.arr = (int*)realloc( obj->Spop.arr, (++(obj->Spop.top) +1)* sizeof(int));
                obj->Spop.arr[obj->Spop.top] = obj->Spush.arr[(obj->Spush.top)--]; 

               }
                 
             return   obj->Spop.arr[obj->Spop.top];
                 
             }
         } else {
            return obj->Spop.arr[obj->Spop.top];
        }
    }
    
    return INT_MIN; 
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
  if(obj->Spush.top == -1 && obj->Spop.top == -1)
      return true; 
    
    return false;
}

void myQueueFree(MyQueue* obj) {
 
    if(obj )
    {
        if(obj->Spush.arr)
            free(obj->Spush.arr); 
        
        if(obj->Spush.arr)
             free(obj->Spop.arr); 
        
        free(obj);
    }
    
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
