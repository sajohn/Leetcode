

    
void FindSum(int* nums, int numsSize, int idx, long S, int* count){
 
 
 if(idx == numsSize)
 { 
     //This condition when idx == numsSize-1 should be separate so that calculation continues
   
     if(S == 0)
        (*count)++;
     
 }
  else
  {
    FindSum(nums, numsSize, idx+1, S - nums[idx], count);
    FindSum(nums, numsSize, idx+1, S + nums[idx], count);
  
  }
 }
 


int findTargetSumWays(int* nums, int numsSize, int S){

    int count =0; 
    FindSum(nums, numsSize, 0, S, &count);
    
   return count;
}


