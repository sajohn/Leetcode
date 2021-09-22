
/*

*/

typedef struct {
    int* Push;
    int PushSize; 
    int* Pop;
    int PopSize; 
    
} MyStack;
///** Initialize your data structure here. */

bool myStackEmpty(MyStack* obj);
MyStack* myStackCreate();
void myStackPush(MyStack* obj, int x);
int myStackPop(MyStack* obj);
int myStackTop(MyStack* obj);
bool myStackEmpty(MyStack* obj);
void myStackFree(MyStack* obj);


MyStack* myStackCreate() {
    
    MyStack* s = (MyStack*)calloc(1, sizeof(MyStack));
    if(s== NULL)
        return NULL; 
    
    s->Push = NULL;
    s->PushSize = 0;
    s->Pop = NULL;
    s->PopSize = 0;
    
  return s; 
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    
    if(obj != NULL){
        if(obj->Push == NULL || obj->PushSize == 0) {
            if(obj->Pop == NULL || obj->PopSize == 0) {
                obj->Push = (int*)calloc(obj->PushSize+1, sizeof(int));
                if(obj->Push == NULL)
                    return ; 
                obj->Push[obj->PushSize++] = x; 
            }else{

                  obj->Pop = (int*)realloc(obj->Pop, (obj->PopSize+1 )*sizeof(int));
                if(obj->Pop == NULL)
                    return ; 
                obj->Pop[obj->PopSize++] = x; 
            }
        }else{
               obj->Push = (int*)realloc(obj->Push, (obj->PushSize+1 )*sizeof(int));
                if(obj->Push == NULL)
                    return ; 
                obj->Push[obj->PushSize++] = x; 
        }
    }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
 if(obj != NULL){
      if(myStackEmpty(obj))
          return -1; 
  
        if(obj->Push == NULL || obj->PushSize == 0) {
            if(obj->Pop == NULL || obj->PopSize == 0) {
               return -1; 
            }else{

            
                int tmp =  obj->Pop[obj->PopSize-1];
                 obj->Pop = (int*)realloc(obj->Pop, (--obj->PopSize)*sizeof(int));
                if(obj->Pop == NULL)
                    return tmp;
                
               return tmp; 
            }
        }else{
                 if(obj->Pop == NULL || obj->PopSize == 0) {
                    int tmp =  obj->Push[obj->PushSize-1];
                      obj->PushSize--; 
                  
                     obj->Push = (int*)realloc(obj->Push, (obj->PushSize)*sizeof(int));
                    if(obj->Push == NULL)
                        return tmp;
                      obj->PopSize = obj->PushSize; 
                      obj->Pop = (int*)calloc( (obj->PopSize), sizeof(int));
                      memcpy(obj->Pop, obj->Push, (obj->PopSize)*sizeof(int));
                      free(obj->Push); 
                      obj->PushSize = 0; 
                     
                     
                     return tmp; 
                     
                 }else{
                     
                     int tmp = obj->Pop[obj->PopSize -1];
                     obj->PopSize--; 
                     
                     if(obj->Push !=NULL || obj->PushSize !=0){
                          obj->Pop = (int*)realloc(obj->Pop, (obj->PopSize + obj->PushSize)*sizeof(int));
                         if(obj->Pop == NULL)
                             return tmp;
                         
                       
                         memmove(obj->Pop[obj->PushSize], obj->Pop, obj->PopSize*sizeof(int));
                         memcpy(obj->Pop, obj->Push, obj->PushSize*sizeof(int));
                         
                           obj->PopSize=  obj->PopSize + obj->PushSize;
                          obj->PushSize = 0; 
                          free(obj->Push);
                         
                         
                     }else{
                          obj->Pop = (int*)realloc(obj->Pop, (obj->PopSize)*sizeof(int));
                         if(obj->Pop == NULL)
                             return -1;
                     }
                     
                     
                      return tmp; 
                     
                 }
            }  
    }  
  return -1;    
 }

/** Get the top element. */
int myStackTop(MyStack* obj) {
 
   if(myStackEmpty(obj) == true)
       return -1; 
    
    if((obj->Pop != NULL )){
        
       return obj->Pop[obj->PopSize -1];

    }
     
    if((obj->Push !=NULL || obj->PushSize !=0)){
        int tmp = obj->Push[ obj->PushSize-1];
        
        obj->Pop = (int*)calloc(obj->PushSize, sizeof(int));
        if(obj->Pop == NULL)
            return -1; 
        obj->PopSize = obj->PushSize;
        memcpy(obj->Pop, obj->Push,  obj->PopSize*sizeof(int));
        obj->PushSize = 0; 
        free(obj->Push);
        
        return tmp; 
    }
    
    return -1; 
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    
    if(obj==NULL)
        return false; 
    if((obj->Pop == NULL && obj->Push ==NULL )    ||
       (obj->PushSize == 0 && obj->PopSize == 0 ) ||
       (obj->Push == NULL && obj->PopSize == 0 )  ||
       (obj->Pop == NULL && obj->PushSize == 0 ))
        return true; 
    
    return false; 
  
}

void myStackFree(MyStack* obj) {
    if(obj == NULL)
        return; 
    if(obj->Push && obj->PushSize !=0){
      obj->PushSize = 0;
     free(obj->Push);
    }
   if(obj->Pop && obj->PopSize !=0) {
     free(obj->Pop);
     obj->PopSize= 0 ;
   }
    
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
