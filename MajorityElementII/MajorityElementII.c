
//Boyer Moore Voting algorithm is O(1)
//Probability of number is 1/3 so we need 2 variables since we need more than n/3

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//1,1,1,1,1,2,4,5,6,5
    
int* majorityElement(int* nums, int numsSize, int* returnSize)
{
    *returnSize = 0;
    if(nums ==NULL || numsSize ==0)
        return NULL;
    
    if(numsSize <2)
    {
        *returnSize = numsSize;
        return nums;
    }
        
    int count1 =0,count2 =0, num1=0, num2=0; 
    
    int* res = (int*)calloc(2, sizeof(int));
   
    if(res == NULL)
        return NULL;
    
   num1  = nums[0];
   num2 = nums[1];
   
    for(int i=0; i< numsSize; i++)
    {  
        if(num1 == nums[i])
            count1++;
        else if(num2 == nums[i])
            count2++;
        else if(count1 == 0)
        {
                num1 = nums[i];
                count1++;
        }
        else if(count2 == 0)
        {
                num2 = nums[i];
                count2++;
        }
        else
        {
            count1--;
            count2--;
        }
  
    }
 
     count1=count2 =0;
   for(int i=0; i< numsSize; i++)
   { 
       if(nums[i] == num1)
           count1++;
          else if(nums[i] == num2)
              count2++;
   }  
    
if(count1>round(numsSize/3))
{
    res[0] = num1;
    (*returnSize)++;}

if(count2>round(numsSize/3))
{  
    if(*returnSize)
        res[1] = num2;
    else
        res[0] = num2;
    (*returnSize)++;
}
    
    return res;
    
}
