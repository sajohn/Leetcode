


typedef struct {

    int* orig;
    int* lastset;
    int size;
} Solution;


Solution* solutionCreate(int* nums, int numsSize) {
    if(nums == NULL || numsSize == 0)
        return NULL; 
    
    Solution* obj = (Solution*)calloc(1, sizeof(Solution));
    if(obj == NULL)
        return NULL; 
    obj->orig = nums;
    
     obj->lastset = (int*)calloc(numsSize, sizeof(int));
    if( obj->orig == NULL)
        return NULL; 
    obj->size = numsSize;
      srand(time(0)); // callng srand per call will not give random result to seed needs to be initialized onece. 
    return obj; 
}

/** Resets the array to its original configuration and return it. */
int* solutionReset(Solution* obj, int* retSize) {
  if(obj != NULL )
  {
      *retSize = obj->size;
      return obj->orig; 
  }
    return NULL; 
}

int GetRandom(int min , int max)
{
      return (rand() % (max -min)) + min ;
}
/** Returns a random shuffling of the array. */
int* solutionShuffle(Solution* obj, int* retSize) {
  
  if(obj != NULL )
  {
      *retSize = obj->size;
       memcpy(obj->lastset, obj->orig, obj->size*sizeof(int)); 
      
      for(int i = 0; i < obj->size; i++) {
      
            int tmpidx1 = GetRandom(i, obj->size);  //rand() % (obj->size - i) + i;
      
            int swap = obj->lastset[tmpidx1];

            obj->lastset[tmpidx1] = obj->lastset[i];
            obj->lastset[i] = swap;
        }
  
      return obj->lastset; 
  }
    return NULL; 
}

void solutionFree(Solution* obj) {
    
    if(obj == NULL)
        return; 
    if(obj->orig)
        free(obj->orig);
     if(obj->lastset)
        free(obj->lastset);
    obj->size = 0; 
    
    free(obj);
    
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int* param_1 = solutionReset(obj, retSize);
 
 * int* param_2 = solutionShuffle(obj, retSize);
 
 * solutionFree(obj);
*/
