


typedef struct {
    int start;
    int end;
    int* arr;
    double sum;
    int size;
} MovingAverage;

/** Initialize your data structure here. */
bool isEmpty(MovingAverage* obj)
{
    if(obj)
    {
       if (obj->start == obj->end && (obj->start == obj->end && obj->start!= 0))
           return true; 
    }
    
    return false; 
}

bool isFull(MovingAverage* obj)
{
    if(obj)
    {
       if ((obj->end+1) %obj->size  == obj->start)
           return true; 
    }
    
    return false; 
}


MovingAverage* movingAverageCreate(int size) {
    MovingAverage* obj= (MovingAverage*)calloc(1, sizeof(MovingAverage));
    if(obj == NULL)
        return NULL;
    if(size == 0)
        return NULL;
    
    obj->start = obj->end = -1;
    obj->size = size; 
    obj->arr = (int*)calloc(size, sizeof(int));
    if( obj->arr == NULL)
        return NULL;

    return obj;
}

double movingAverageNext(MovingAverage* obj, int val) {
  if(obj == NULL)
      return (double)INT_MIN;
    
    if(!isEmpty(obj) || (obj->start == obj->end ==0))
    {
        if(isFull(obj))
        {
            obj->sum -= obj->arr[obj->start];
            obj->start = (++obj->start) % obj->size; 
            obj->arr[(++obj->end)% obj->size] = val; 
            
            obj->sum +=  obj->arr[(obj->end )% obj->size];
            return (obj->sum / obj->size);

        } else {
            
            obj->sum += val; 
            obj->arr[(++obj->end )% obj->size] = val; 

            if(obj->end < obj->start)
                   return obj->sum /(obj->end -obj->start + obj->size +1 );
            else
                return obj->sum / (obj->end -obj->start +1 );
        }
    }
    else{
        
        obj->end = (++obj->end) % obj->size; 
        obj->start = obj->end; 
        
        obj->arr[obj->end] = val;
        obj->sum = 0;
        obj->sum += obj->arr[obj->end]; 
         return  obj->sum; 
        
    }
    
    return -1; 
}

void movingAverageFree(MovingAverage* obj) {
    
    if(obj)
    {
        free(obj->arr);
        
        free(obj);
    }
    
}

/**
 * Your MovingAverage struct will be instantiated and called as such:
 * MovingAverage* obj = movingAverageCreate(size);
 * double param_1 = movingAverageNext(obj, val);
 
 * movingAverageFree(obj);
*/
