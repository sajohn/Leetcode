

int findUnsortedSubarray(int* nums, int numsSize) {
    
    if(nums == NULL || numsSize <=1)
        return 0; 
    
    int leftmin = 0, min = INT_MAX, max = INT_MIN, rightmax = numsSize-1, left =0, right= numsSize -1; 
    bool foundleft =false, foundright =false;
    for(int i = 1, j = numsSize-2; i < numsSize && j>=0; i++, j--)
    {
        if(nums[i-1] > nums[i]){
            
            if(nums[i] < min){
                min = nums[i];
                leftmin = i;
            }
        }
        
        if(nums[j] > nums[j+1]){
            if(nums[j] >max){
            max = nums[j];
            rightmax = j;
            }
        }           
    }

   for(int i = 0; i < numsSize; i++)
   {
       if(nums[leftmin] < nums[i] && foundleft == false)
       {    left = i; 
           foundleft = true;
       }
       
        if(nums[rightmax] > nums[numsSize-1-i] && foundright == false)
       {    right = numsSize-1-i; 
            foundright = true; 
    
       }
       if(foundleft == true && foundright == true)
           break; 
       
   }

  
     if(rightmax == numsSize-1 && leftmin ==0)
        return 0; 
    
    //Below condition is to check if nothing needed to be changed when left and right points of inflections were detected. 
    //Or if there were no inflections found. 
    
    if(right == numsSize -1 && left == 0 && (nums[left] == nums[leftmin] &&  nums[right] == nums[rightmax]))
        return 0; 
   
    
    return right -left+1; 
    
    
}
