int thirdMax(int* nums, int numsSize)
{
  if(nums == NULL || numsSize ==0)
      return 0;
 
    
    int threeNum[3] = {INT_MIN, INT_MIN, INT_MIN}, count =0;
    
  if(numsSize < 3)
  {
      return (nums[0] > nums[1]?nums[0]:nums[1] );
  }
    //this is frustration
    if(numsSize == 3)
    {

      if(nums[0] == nums[1] && nums[2]<nums[1])
          return nums[1];
     else if(nums[0] == nums[1] && nums[2]>nums[1])
         return nums[2];
    else if(nums[0] == nums[2] && nums[2]<nums[1])
        return nums[1];
    else if(nums[0] == nums[2] && nums[2]>nums[1])
        return nums[2];
    else if(nums[1] == nums[2] && nums[0]<nums[1])
          return nums[1];
    else   if(nums[1] == nums[2] && nums[0]>nums[1])
          return nums[0];
    else if(nums[0] == nums[1]== nums[2])
        return nums[0];
    else if(nums[0] != nums[1] && nums[0]!= nums[2] && nums[1]!= nums[2])
    {
        if(nums[0]< nums[1] && nums[0]< nums[2])
            return nums[0];
        if(nums[1]< nums[0] && nums[1]< nums[2])
            return nums[1];
        if(nums[2]<nums[0] && nums[2]<nums[1])
            return nums[2];     
     }

    }
    
    for(int i = 0; i < numsSize; i ++)
    {
        if(threeNum[2] == nums[i] || threeNum[1] == nums[i] || threeNum[0] == nums[i])
        continue;
        
       if(threeNum[2] < nums[i])
       {   threeNum[0] = threeNum[1];
           threeNum[1] = threeNum[2];
           threeNum[2] = nums[i];
       }

      else if (threeNum[1]  <nums[i] && nums[i]< threeNum[2])
      {
          threeNum[0] = threeNum[1];
          threeNum[1] = nums[i];
      }
  
      else if (threeNum[0]  <nums[i] && nums[i]< threeNum[1] )
      {
           threeNum[0] = nums[i];
        
           count++;
      }
     
    }
    
     
    if(count == 0 )
    {
         if(threeNum[0]!=threeNum[1] && threeNum[0]!= threeNum[2] && threeNum[1]!=threeNum[2] && 
           (threeNum[0]==INT_MIN || threeNum[1]==INT_MIN || threeNum[2]==INT_MIN))
              return threeNum[2];
        else  if(threeNum[0]!=threeNum[1] && threeNum[0]!= threeNum[2] && threeNum[1]!=threeNum[2] && 
           (threeNum[0]!=INT_MIN || threeNum[1]!=INT_MIN || threeNum[2]!=INT_MIN))
              return threeNum[0];
        else 
            return threeNum[2];
   
    }
    
    return threeNum[0];
    
}
