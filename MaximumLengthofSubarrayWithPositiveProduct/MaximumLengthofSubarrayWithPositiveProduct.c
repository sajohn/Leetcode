

int getMaxLen(int* nums, int numsSize){
    
    
    
if(nums == NULL || numsSize == 0)
    return 0; 
    
    int maxlen = 0, curlen =0, negative = 0, firstneg = 0; 
    
    
    for(int i = 0; i < numsSize; i++)
    {
        //if num is  zero reset
        
        if(nums[i] == 0){
            curlen = 0; 
            negative = 0; 
        }
        else{
            
            curlen++; 
           
             //if num is no zero continue (curlen should increase and check if pivot needs update (i.e. 0 value ))
              if(nums[i] < 0){
               if( negative == 0)
                   firstneg = curlen;
                negative++; 
              }
      
        }
        
        
        if(negative %2 !=0) //This is not going to update lenght when product is < 0 (i.e. negative %2 !=0)
            maxlen = maxlen > curlen -firstneg? maxlen: curlen-firstneg;  
        else
            maxlen = maxlen > curlen? maxlen:curlen; 
       
        
    }

    
    
    return maxlen; 
}
