typedef struct {
   int* firstStack;
   int maxf;
   int* secondStack;
   int maxS;
} MaxStack;

/** initialize your data structure here. */

MaxStack* maxStackCreate() {
       
   MaxStack* max = (MaxStack*)calloc(1, sizeof(MaxStack));
    if(max == NULL)
        return NULL;
     max->firstStack = NULL;
     max->secondStack = NULL;
     max->maxf=-1;
     max->maxS =-1;
    return max;
}

void maxStackPush(MaxStack* obj, int x) {
   if(obj == NULL)
        return;
    
    if(obj->firstStack)
        obj->firstStack = (int*)realloc(obj->firstStack, (obj->maxf+2)*sizeof(int));
    else
        obj->firstStack = (int*)calloc(1, sizeof(int));
    
    obj->firstStack[++obj->maxf] = x;
    
    if(obj->secondStack)
        obj->secondStack = (int*)realloc(obj->secondStack, (obj->maxS+2)*sizeof(int));
    else
        obj->secondStack = (int*)calloc(obj->maxS+2, sizeof(int));
    
     if(obj->maxS == -1  || x>= obj->secondStack[obj->maxS])
          obj->secondStack[++obj->maxS]= x;

}

int maxStackPop(MaxStack* obj) {
   if(obj == NULL|| obj->maxf == -1)
        return -1;
    int val =0;  
    if(obj->firstStack[obj->maxf] == obj->secondStack[obj->maxS])
        obj->secondStack[obj->maxS--] = 0;
    
     val = obj->firstStack[obj->maxf];
     obj->firstStack[obj->maxf--] = 0;
    return val;
}

int maxStackTop(MaxStack* obj) {
   if(obj == NULL || obj->maxf == -1)
        return -1;    
    return obj->firstStack[obj->maxf];
}

int maxStackPeekMax(MaxStack* obj) {
   if(obj == NULL || obj->maxS == -1)
        return -1;
   return obj->secondStack[obj->maxS];
}

int maxStackPopMax(MaxStack* obj) {
   if(obj == NULL || obj->maxf == -1|| obj->maxS == -1)
        return -1;
    
    int val = 0, valmax=0;
    int* buffer = NULL;
    
    while(obj->firstStack[obj->maxf] != obj->secondStack[obj->maxS] && obj->maxf>=0)
    {
        if(buffer)
          buffer = (int*)realloc(buffer, (val+1)*sizeof(int));
        else
          buffer = (int*)calloc(val+1, sizeof(int));
    
        buffer[val++]  =  obj->firstStack[obj->maxf--];
    }
    
    if(obj->firstStack[obj->maxf] == obj->secondStack[obj->maxS])
    {
        valmax  =  obj->firstStack[obj->maxf];   
        obj->firstStack[obj->maxf--] = 0; 
        obj->secondStack[obj->maxS--] = 0;
       
       while(val>0)
       {
            obj->firstStack[++obj->maxf] = buffer[--val];
           
            if(obj->maxS == -1 )
              obj->secondStack[++obj->maxS] = obj->firstStack[obj->maxf];
           else if(obj->firstStack[obj->maxf] >= obj->secondStack[obj->maxS])
           {
                obj->secondStack = (int*)realloc(obj->secondStack, (obj->maxS+2)*sizeof(int));
                obj->secondStack[++obj->maxS]= obj->firstStack[obj->maxf];

           } 
       }
    }
  if(buffer)
      free(buffer);
    return valmax;
}

void maxStackFree(MaxStack* obj) {
      if(obj == NULL)
        return;
    free(obj->firstStack);
    free(obj->secondStack);
    
    free(obj);
}



/**
 * Your MaxStack struct will be instantiated and called as such:
 * MaxStack* obj = maxStackCreate();
 * maxStackPush(obj, x);
 
 * int param_2 = maxStackPop(obj);
 
 * int param_3 = maxStackTop(obj);
 
 * int param_4 = maxStackPeekMax(obj);
 
 * int param_5 = maxStackPopMax(obj);
 
 * maxStackFree(obj);
*/

