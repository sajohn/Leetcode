
typedef struct {
   int* firstStack;
   int minf;
   int* secondStack;
   int minS;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    
   MinStack* min = (MinStack*)calloc(1, sizeof(MinStack));
    if(min == NULL)
        return NULL;
     min->firstStack = NULL;
     min->secondStack = NULL;
     min->minf=-1;
     min->minS =-1;
    return min;
}

void minStackPush(MinStack* obj, int x) {
    if(obj == NULL)
        return;
    
    if(obj->firstStack)
        obj->firstStack = (int*)realloc(obj->firstStack, (obj->minf+2)*sizeof(int));
    else
        obj->firstStack = (int*)calloc(1, sizeof(int));
    
    obj->firstStack[++obj->minf] = x;
    
 if(obj->secondStack)
    {
        if(obj->minS == -1 )
        {
          obj->secondStack = (int*)realloc(obj->secondStack, (obj->minS+2)*sizeof(int));
          obj->secondStack[++obj->minS]= x;
        }
        else if(x<= obj->secondStack[obj->minS])
        {
            obj->secondStack = (int*)realloc(obj->secondStack, (obj->minS+2)*sizeof(int));
            obj->secondStack[++obj->minS]= x;
        }
    }
   else
   {
        obj->secondStack = (int*)realloc(obj->secondStack, (obj->minS+2)*sizeof(int));
        obj->secondStack[++obj->minS]= x;
   }
}

void minStackPop(MinStack* obj) 
{
  if(obj == NULL)
      return;
    if(obj->minf == -1)
        return;
       
    
    if(obj->firstStack[obj->minf] == obj->secondStack[obj->minS])
    {
        obj->firstStack[obj->minf--] = 0; 
        obj->secondStack[obj->minS--] = 0;
    }
    else
         obj->firstStack[obj->minf--] = 0; 
    
}

int minStackTop(MinStack* obj) {
   if(obj == NULL)
      return -1;
    if(obj->minf == -1)
        return -1;
    
    return obj->firstStack[obj->minf];
}

int minStackGetMin(MinStack* obj) {
    if(obj == NULL)
      return -1;
    if(obj->minS == -1)
        return -1;
    
   return obj->secondStack[obj->minS];
}

void minStackFree(MinStack* obj) {
    if(obj == NULL)
        return;
    free(obj->firstStack);
    free(obj->secondStack);
    
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
