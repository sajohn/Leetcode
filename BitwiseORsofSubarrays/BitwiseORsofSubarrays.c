   long val = (long)((long)1<<(long)numsSize);  //Total size of set would be 2^N

    
    for(long i =1; i <val; i ++)
    {
        int count =0, prev = 0, result =0;
        bool flag = true;
        for(int j = 0; j < numsSize && ( (1<<j)<=i) ;  j++)
        {
            int y =0;
            if(i & (1<<j) && ( (1<<j)<=i) )
            {
                if((j -prev)>1 && j !=0 && count !=0)
                {
                 result = 0;
                   flag = false;
                  break;
                }
                prev = j;
                count++; 
                y = numsSize -1-log2(1<<j);
            
                result |= nums[y]; 

            }
          
        }

         if(flag){
            
               HASH_FIND_INT(guser, &result, element);
               if(element == NULL)
               {
                   element = (Unique*)calloc(1, sizeof(*element));
                   if(element == NULL)
                       return INT_MIN;
                   
                   element->xor = result;
                   HASH_ADD_INT(guser, xor, element);
                   total++;
               }
       
            returnSize++;
         }
    }
 
     
    return total; 
}
