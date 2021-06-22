//Time limit exceed if no dp

int FinMinStep(int* nums, int idx, int numsSize, int* dp)
{
   
     if(nums == NULL)
        return 0;     
    if(idx >= numsSize-1)
        return 0; //No steps needed 
    
  if(dp[idx] >0)
      return dp[idx];
    
    
    int steps = 0; 
    int minSteps = INT_MAX-1;
    
    for(int i = idx+1; i <=idx+nums[idx]; i++)
    {
      
          steps = 1+ FinMinStep(nums,i, numsSize, dp);
          if(steps < minSteps){
            minSteps = steps; 
            dp[idx] = minSteps;
          }
    }
   
    return minSteps; 
}

int jump(int* nums, int numsSize){

    
    if(nums == NULL || numsSize == 0 )
        return 0; 
    
    
    if(nums[0]  == 0 || (nums[0] >=numsSize-1 && numsSize ==1) )
        return 0; 
    if(nums[0] >=numsSize-1)
        return 1; 
    int* dp = (int*)calloc(numsSize, sizeof(int));
    if(dp == NULL)
        return -1; 
    
    return  FinMinStep(nums,0, numsSize, dp );
    
}
