bool Find(int* nums, int numsSize, int target)
{
    int l=0, r=numsSize -1, mid=0, leftIdx=0, rightIdx =0, num =0;
    
    while(l<=r)
    {
        mid = (r-l)/2+l;
        
        if(nums[mid] > target)
           r = mid-1;
        else if(nums[mid] < target)
           l = mid+1;
        else if(nums[mid] == target)
            break;
        
    }
    
   if(mid-1>=0)
   {
     if(nums[mid]== nums[mid-1] )
     {
        for(leftIdx = mid-1; leftIdx>=0; )
              if(nums[mid]== nums[leftIdx])
                  leftIdx--;
              else 
                  break;
     }
     else
        leftIdx= mid;
   }
    else 
       leftIdx= mid;
    
    if(mid+1 <=numsSize-1 )
    {
         if(nums[mid]== nums[mid+1] )  
         {
            for(rightIdx = mid+1; rightIdx<numsSize; )
                  if(nums[mid]== nums[rightIdx] && rightIdx!=numsSize-1)
                      rightIdx++;
                  else 
                      break;
         }
         else
            rightIdx= mid;
    }
    else 
       rightIdx= mid;

 
    if(rightIdx -leftIdx+1 > numsSize/2)
        return true;
    
    
    return false;
  
}

bool isMajorityElement(int* nums, int numsSize, int target)
{

    if(nums == NULL || numsSize ==0 || (numsSize ==1 && nums[0]!=target))
        return false;
    
   return Find(nums, numsSize, target);
    
}



