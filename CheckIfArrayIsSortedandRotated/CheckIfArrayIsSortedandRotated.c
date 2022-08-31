/*
1. There should be a inflection
2. Can you do a binary search
3. if( mid-1 && mid && mid+1 )
4. Condition 3 didn't work so somebody suggested just count inflection...
             
*/

bool check(int* nums, int numsSize){
    
    
    if(nums == NULL || numsSize ==0)
        return false; 
    int i = 0, count =0;
 for( i = 1; i <numsSize; i++)
 {
     if(nums[i-1] > nums[(i)%numsSize])
          count++; 
 
 }
    
    if(count > 1)
        return false; 
    
    return true; 
}
