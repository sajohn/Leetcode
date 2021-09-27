

void swap(int* a, int* b)
{
    int tmp = *a; 
    *a = *b; 
    *b = tmp; 
}

void wiggleSort(int* nums, int numsSize){

if(nums == NULL || numsSize ==0)
    return;
    int flip = 1; 

      for(int i =1; i < numsSize; i++){
          
          if(flip && nums[i-1]> nums[i])
              swap(&nums[i-1], &nums[i]);
          else if(!flip && nums[i-1] < nums[i])
              swap(&nums[i-1], &nums[i]);
      
          flip = !flip;
      }
      
         
}
