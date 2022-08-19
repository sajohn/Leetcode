

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize){
    
    //So n is the number of bits... 
    //Total numbers == 2^n

//Every single bit except first is 
    *returnSize = 0; 
    int count = (1<< n);
    
     int* ret = ( int*)calloc(count, sizeof(int));
    if(ret == NULL)
        return NULL;  
    
    
    for(int i =0; i < count; i++)
       ret[(*returnSize)++] = i^ (i>>1);
    
    return ret; 
    
}
