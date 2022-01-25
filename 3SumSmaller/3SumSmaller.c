int cmpfunc(void* a, void* b)
{
    int aa = (*(int*)a);    
     int bb = (*(int*)b);  
    
    return (aa - bb);
}  

int FindCouplet(int* nums, int numsSize, int target, int idx)
{
     
    if(idx >numsSize -1)
        return 0; 
    
    int low = idx, high = numsSize -1,count = 0, sum = 0;

        while(low < high) {
           
            sum = nums[low]+nums[high]; 

            if(sum < target)
            {
              count += high -low;
              low++;   
            }
            else if(sum >= target)
            {
                high--;
            }
            
        }
    return count; 
}

int threeSumSmaller(int* nums, int numsSize, int target){
    
    if(nums == NULL || numsSize == 0)
        return 0; 
    
  
    int count = 0; 
    qsort(nums, numsSize, sizeof(int), cmpfunc);  
    
    
    for(int i = 0; i < numsSize-2; i++)
    {
        count +=FindCouplet(nums, numsSize, target - nums[i], i+1);
    }

    return count; 
}
