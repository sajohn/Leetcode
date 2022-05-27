

int maxSubarraySumCircular(int* nums, int numsSize){

    if(nums == NULL || numsSize ==0)
        return 0; 
 
    int cur_max_sum = nums[0],  cur_min_sum = nums[0], max_sum = nums[0], min_sum = nums[0], total_sum = nums[0]; 
    
    int start = 0, end = numsSize; 
    
   for(int start = 1;  start < end; start++) {

       cur_max_sum = ( nums[start] < cur_max_sum + nums[start] ? cur_max_sum + nums[start]: nums[start] );
        if(cur_max_sum > max_sum)
            max_sum = cur_max_sum; 

        cur_min_sum = ( nums[start] > cur_min_sum + nums[start] ? cur_min_sum + nums[start]: nums[start]);
        if(cur_min_sum < min_sum)
            min_sum = cur_min_sum; 

       total_sum += nums[start];

    }
    
    return (max_sum> 0 ? (total_sum -min_sum > max_sum? total_sum-min_sum : max_sum):max_sum);
}



/*
           |---------------------------Total Sum ----------------------------------|

           |========================<===Negative Chunk===>=========================| 
           |--------Partial Sum-----|                    |--------Partial Sum------|
           
                        |-----------------Partial Sum ----------|
                                      |-----------------Partial Sum ----------|
           So now we are checking if
           
                      TotalSum - Negative Chunk is bigger or Partial Sum is bigger
                      
                      Partial sum could be anywhere like what Kadane's algorighm gives.....
*/
