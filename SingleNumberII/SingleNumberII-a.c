#define INT_MAX 0xFFFFFFFF

int singleNumber(int* nums, int numsSize){

    if(!nums || numsSize == 0)
        return 0;
    
    int i=0, j=0, firstIndex = 0, secondIndex =0, prev=INT_MAX, count =0;
    
    while(i < numsSize )
    {
        if(nums[i] == prev || nums[i] == INT_MAX){
            i++;
            continue;
        }
        firstIndex = 0; secondIndex =0; count = 0;
        j = i+1;
        while(j> i && j< numsSize){   
           if(nums[i] == nums[j])
           {
               if(firstIndex == 0)
               {
                  firstIndex = j;
                   nums[j] = INT_MAX;
               }
               else
               {
                  secondIndex = j;
                   nums[j] = INT_MAX;
               }
               
               count++;
           }
            if(count == 2)
                break;
          j++;
        }
        if(count == 2){
            prev = nums[i];
            nums[i] = INT_MAX;
            i++;
        }
        else{
            prev = nums[i];
            break;
        }
    }
    
    return prev;
}
