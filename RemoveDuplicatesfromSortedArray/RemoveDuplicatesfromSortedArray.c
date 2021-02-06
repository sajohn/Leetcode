

int removeDuplicates(int* nums, int numsSize){

    if( nums == NULL || numsSize ==0 )
        return 0;
    
    int j=0, i =0;
    
    for( i =0; i < numsSize; )
    {   
        if(nums[j]==nums[i])
            i++;
        else
            nums[++j] = nums[i++];
        
    }
    
    return j+1;
}
