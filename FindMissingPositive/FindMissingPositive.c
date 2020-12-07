/*First of all let's get rid of negative numbers and zeros since there is no need of them. 
One could get rid of all numbers larger than n as well, since the first missing positive is for sure smaller or equal to 
n + 1. The case when the first missing positive is equal to n + 1 will be treated separately. 

After doing this numbers must be in the range of [1 n] just sort them via counting sort 
Iterate to get the first positive at index 0 

*/

int firstMissingPositive(int* nums, int numsSize){
 
    
    if(!nums || numsSize ==0)
        return 1;
    //Since changing to 1 means we will never find if there was a one earlier 
    //Track 1 (1 happens to be smallest positive integer)
    int hasMissingOne =1;
    
    for(int i =0; i< numsSize; i++)
    {
        if(nums[i] ==1)
            hasMissingOne =0;
         else if(nums[i] >= numsSize+1 || nums[i]<= 0)
             nums[i] = 1;
    }
    
   //Smallest positive is one no need to run loop simply return if you didn't find one
    if(hasMissingOne == 1 )
        return 1;
    
    int count[numsSize+1];
    int results[numsSize];
    memset(count, 0, sizeof(count));
    memset(results, 0, sizeof(results));
    
     for(int i =0; i< numsSize; i++)
       count[nums[i]] = count[nums[i]]+1;
     for(int i =1; i<=numsSize; i++)
       count[i] = count[i]+count[i-1];
    
     for(int i =0; i<numsSize; ++i)
     {
         results[(count[nums[i]])-1] = nums[i];
         --count[nums[i]];
     }
    for(int i =0; i < numsSize-1; i++)
    {
        if(results[i]> i+1 )
            return i;
        else if(results[i+1] -results[i]>1)
            return results[i]+1;       
    }
    return results[numsSize-1]+1;
}
