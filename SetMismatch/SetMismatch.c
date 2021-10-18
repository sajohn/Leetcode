

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize){
    
    *returnSize = 0; 
     int* ret = (int*)calloc(2, sizeof(int));
    
    if(nums == NULL || numsSize == 0 || ret == NULL)
        return NULL; 
    
    int xor = 0, xor0= 0, xor1 =0, right_most_bit =0; 
    
    for(int i = 0; i < numsSize; i++)
        xor ^= nums[i];
     for(int i = 1; i <=numsSize; i++)
        xor ^= i;
    
    right_most_bit = xor & ~(xor-1);
    
     for(int i = 0; i <numsSize; i++)
     {
         if((nums[i] & right_most_bit) !=0)
             xor1 ^= nums[i];
         else
             xor0 ^= nums[i];
     }
    
    
     for(int i = 1; i <=numsSize; i++)
     {
         if((i & right_most_bit) !=0)
             xor1 ^= i;
         else
             xor0 ^= i;
     }
    
    
   *returnSize = 2;
    
       for(int i = 0; i < numsSize; i++)
       {
           if(xor0 == nums[i]){
               ret[0] = xor0;
               ret[1] = xor1; 
             
               return ret; 
           }
           
       }
    
     ret[0] = xor1;
     ret[1] = xor0; 

return ret; 
}


// public class Solution {
//     public int[] findErrorNums(int[] nums) {
//         int xor = 0, xor0 = 0, xor1 = 0;
//         for (int n: nums)
//             xor ^= n;
//         for (int i = 1; i <= nums.length; i++)
//             xor ^= i;
//         int rightmostbit = xor & ~(xor - 1);
//         for (int n: nums) {
//             if ((n & rightmostbit) != 0)
//                 xor1 ^= n;
//             else
//                 xor0 ^= n;
//         }
//         for (int i = 1; i <= nums.length; i++) {
//             if ((i & rightmostbit) != 0)
//                 xor1 ^= i;
//             else
//                 xor0 ^= i;
//         }
//         for (int i = 0; i < nums.length; i++) {
//             if (nums[i] == xor0)
//                 return new int[]{xor0, xor1};
//         }
//         return new int[]{xor1, xor0};
//     }
// }
