

bool canJump(int* nums, int numsSize){

    if(nums == NULL || numsSize ==0)
        return false; 
    
    
    int maxreachable = 0, reachable=0; 
    
    if(nums[0] == 0 )
        if(numsSize >1 )
            return false; 
        else 
            return true; 
    

    for(int i =0; i < numsSize; i++)
    {
        reachable = i+ nums[i];
        if(reachable > maxreachable)
        {
            maxreachable = reachable; 
            
            if(maxreachable >= numsSize -1)
                return true; 
        }
        else if(reachable <=i && maxreachable <=reachable )
            return false;
        else if(reachable < i)
            return false; 
                
    }
    
    return false; 
}
