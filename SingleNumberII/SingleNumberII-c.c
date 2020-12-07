

//When the third occurance comes the second appearance along with first appearance goes away. 
int singleNumber(int* nums, int numsSize)
{
    int firstAppearance = 0, secondAppearance =0;
    
    if(nums == NULL || numsSize ==0)
        return 0;
    
    for(int i =0; i < numsSize; i++)
    {
        firstAppearance = ~secondAppearance & (firstAppearance ^ nums[i]);
        secondAppearance = ~firstAppearance & (secondAppearance ^ nums[i]);
        
    }
    
   return firstAppearance;
}
