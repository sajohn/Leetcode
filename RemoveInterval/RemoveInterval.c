

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */



/*
Three cases of overlap: 

1. 

       int_start             int_end
       |-----------------------------|

             rem_start             rem_end
             |-----------------------|
             |-------------------------------------|   { add [int_start rem_start] }
             
             rem_start    rem_end
             |----------------|                       { add [int_start rem_start] , [rem_end int_end] }


2. 
       int_start             int_end
       |-----------------------------|
 rem_start             rem_end                
 |-----------------------------|               {add [rem_end int_end] }
 
 
 |-----------------------------------|        {>= dont' add anything}
 |-------------------------------------------|   {>= dont' add anything}    
       
*/



int cmp(void* a, void* b){
    
    int x = ((int**)a)[0][0];
    int y = ((int**)b)[0][0];
    
    if(x > y)
        return 1; 
    else if(x < y)
        return -1; 
    else return 0; 
    
}
int** removeInterval(int** intervals, int intervalsSize, int* intervalsColSize, int* toBeRemoved, int toBeRemovedSize, int* returnSize, int** returnColumnSizes){

    
      *returnSize = 0; 
       
     if(intervals == NULL || intervalsSize == 0 || intervalsColSize == NULL)
         return NULL; 

      if(toBeRemoved == NULL || toBeRemovedSize == 0)
          return intervals; 
          

    qsort(intervals, intervalsSize, sizeof(intervals[0]), cmp);
    
    
    (*returnColumnSizes) = calloc(intervalsSize+2, sizeof(int));
    int** ret = (int**)calloc(intervalsSize+2, sizeof(int*));
    if(ret == NULL || (*returnColumnSizes ) == NULL)
        return NULL; 
    
    for(int i = 0; i < intervalsSize; i++)
    {
        
        if( (intervals[i][1] < toBeRemoved[0])  || 
            (toBeRemoved[1] < intervals[i][0])) {  //Not overlapping
            
            ret[*returnSize] = calloc(2, sizeof(int));
            ret[*returnSize][0] = intervals[i][0];
            ret[*returnSize][1] = intervals[i][1];
            (*returnColumnSizes)[*returnSize] = 2; 
            (*returnSize)++; 
        }
        else{
                 if(toBeRemoved[0] > intervals[i][0]){
                    if( toBeRemoved[1] >= intervals[i][1] ){
                        ret[*returnSize] = calloc(2, sizeof( int));
                        ret[*returnSize][0] = intervals[i][0];
                        ret[*returnSize][1] = toBeRemoved[0];
                        (*returnColumnSizes)[*returnSize] = 2; 
                        (*returnSize)++; 
                    }
                    else if( toBeRemoved[1] <intervals[i][1] ){
                        ret[*returnSize] = calloc(2, sizeof( int));
                        ret[*returnSize][0] = intervals[i][0];
                        ret[*returnSize][1] = toBeRemoved[0];
                        (*returnColumnSizes)[*returnSize] = 2; 
                        (*returnSize)++; 

                        ret[*returnSize] = calloc(2, sizeof( int));
                        ret[*returnSize][0] = toBeRemoved[1];
                        ret[*returnSize][1] = intervals[i][1];
                        (*returnColumnSizes)[*returnSize] = 2; 
                        (*returnSize)++; 

                    } 
                 }else  if(toBeRemoved[0] <= intervals[i][0]){
                     
                      if( toBeRemoved[1] < intervals[i][1] ){
                            ret[*returnSize] = calloc(2, sizeof( int));
                            ret[*returnSize][0] = toBeRemoved[1];
                            ret[*returnSize][1] = intervals[i][1];
                            (*returnColumnSizes)[*returnSize] = 2; 
                            (*returnSize)++; 
                          
                      }
                }
             }
         }
    
    return ret; 
}

