bool isPossible(int* nums, int numsSize, int m, int sum){
    
    int cursum = 0, idx = 0, count = 0; 
    
    while(idx < numsSize){
        
        cursum += nums[idx];

         if(cursum >= sum){
            count++; 
            cursum = 0; //Letting go with extra than mid 
        }
        
        idx++;
    }
    
    return (count >= m+1?  true:false); 
}

int maximizeSweetness(int* nums, int numsSize, int m) {
    
    
    if(nums == NULL || numsSize == 0 || m <0)
        return -1; 
    
    //Largest minimum sum == max element in array
    //Largest maximum sum == sum of all element in array
    int presum=0 , min = INT_MAX, minsum = 0, maxsum = 0, final = INT_MIN, mid =0, count =0, minval = INT_MAX;
    
 
    for(int i = 0; i< numsSize; i++){
        if(nums[i] < min)
            min = nums[i];
        
       presum += nums[i];    
    }
    
    minsum = min; 
    maxsum = presum/(m+1);
    
    while(minsum < maxsum){
        
        mid = (minsum + maxsum +1)/2;
        
      if(isPossible(nums, numsSize, m, mid)){

             minsum = mid;
           
      }
        else{
             maxsum = mid-1;
       
        }
        
    }
     
return maxsum; 
}



// int maximizeSweetness(int* sweetness, int sweetnessSize, int k){

// }
