//Can use counting sort
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
 *returnSize =0; 
    
    if(nums == NULL || numsSize == 0)
        return NULL; 
    
    int* ret = (int*)calloc(numsSize, sizeof(int));
    if(ret == NULL)
        return NULL; 
     
 int tmp[101]= {0};
 memset(tmp, 0, sizeof(tmp));
    
   for(int i = 0; i < numsSize; i++){
       tmp[nums[i]]++;
   }

    for(int i = 1; i < 101; i++){   
            tmp[i] += tmp[i-1];
   }
   
     for(int i = 0; i < numsSize; i++){
       if(nums[i] == 0){
           ret[i] = 0;
           continue;
       }
           ret[i] = tmp[nums[i]-1];
     }
    
    *returnSize = numsSize;
    return ret;
}



