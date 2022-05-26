bool isPossible(int* nums, int numsSize, int m, int sum){
    
    int cursum = 0, idx = 0, count = 1; 
    
    while(idx < numsSize){
        
        cursum += nums[idx];

         if(cursum > sum){
            count++; 
            cursum = nums[idx]; 
        }
        
        if(count > m)
            return false; 
        
        idx++;
    }
    
    return true; 
}

int splitArray(int* nums, int numsSize, int m) {
    
    
    if(nums == NULL || numsSize == 0 || m <0)
        return -1; 
    
    //Largest minimum sum == max element in array
    //Largest maximum sum == sum of all element in array
    int min = INT_MIN, minsum = 0, maxsum = 0, final = INT_MIN, mid =0, count =0;
    
    int* presum = calloc(numsSize, sizeof(int));
    memset(presum, 0, numsSize*(sizeof(int)));
    
    for(int i = 0; i< numsSize; i++){
        if(nums[i] > min)
            min = nums[i];
        
       presum[i] = (i> 0 ? presum[i-1] +nums[i]: nums[i]);    
    }
    
    minsum = min; 
    maxsum = presum[numsSize-1];
    
    while(minsum < maxsum){
        
        mid = (minsum + (maxsum-minsum)/2);
        
      if(isPossible(nums, numsSize, m, mid))
            maxsum = mid;
        else
            minsum = mid+1;
        
    }
    
    
    
return minsum; 
}


// [7,2,5,10,8]
// [7,  9,  14, 24, 32]
// [32, 25, 23, 18,  8]


// [1, 2, 3, 4, 5]
// [ 1,  3,  5, 9, 14]
// [15, 14, 12, 9,  5]



//[5,     8,  10,  20, 900]
//[5,    13,  23,  43, 943]
//[943, 938, 930, 920, 900]



// bool isPossible(int* nums, int numsSize, int m, int* presum, int sum){
    
//     int cursum = 0, left = 0, right = numsSize -1, count = 1, mid =0; 
    
//     while(left <= right){
        
//         mid = left + (right -left)/2;
//         if(presum[mid] -cursum > sum){
//             count++; 
//             left = mid; 
//             cursum = presum[mid] - nums[mid];
//         }
//         else if(presum[mid] -cursum < sum){
//             left++; }
//         else {
//             right--;
//         }
 
    
//     }
//     return (count); 
// }



