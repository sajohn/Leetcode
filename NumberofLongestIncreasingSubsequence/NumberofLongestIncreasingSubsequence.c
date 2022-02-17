

int findNumberOfLIS(int* nums, int numsSize){

    if(nums == NULL || numsSize == 0)
        return 0; 
    
    int  max =1, res =0;
  
    int length[numsSize], count[numsSize]; 
    
     for(int i = 0; i < numsSize; i++) {
         length[i] = 1; 
         count[i] = 1;
     }

    for(int i = 1; i < numsSize; i++)
    {
        for(int j = 0; j < i; j++)
         {
            if(nums[j] < nums[i]){
                if(length[j] >= length[i]) {
                     length[i] = length[j]+1; //You can add it to length
                     count[i] = count[j]; //count doesn't change since count is not increasing only length has increased. 
                } else if(length[i] == length[j]+1)
                         count[i] +=count[j];     
            }
         }
        if(length[i] >= max)
            max = length[i];
    }

 for(int i = 0; i < numsSize; i++)
    if(length[i] == max)
        res += count[i];// all 2's are counted with length 1 so total becomes 5 in second example
    
    return res; 
}

//{

// 1  3  5  4  7
    
// 1. 2. 3. 3. 4  
    
// 1  1. 1. 1. 2

//}

// 2  2  2  2
    
// 1. 1. 1. 3

// 1. 1. 1. 1    
