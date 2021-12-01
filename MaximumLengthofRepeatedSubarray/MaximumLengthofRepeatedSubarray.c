//I got the concept but couldnt solve this in reverse order
//Point to note is that I had to fill from bottom...

int findLength(int* nums1, int nums1Size, int* nums2, int nums2Size){
    
    int** dp = (int**)calloc(nums1Size+1, sizeof(int*));
    for(int i = 0; i <=nums1Size; i++)
        dp[i] = (int*)calloc(nums2Size+1, sizeof(int));
    
    
    
      int result = INT_MIN;
        for (int i = 1; i <= nums1Size; i++) {
            for (int j = 1; j <= nums2Size; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    result = (dp[i][j] > result? dp[i][j]: result); 
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        return result == INT_MIN ? 0 : result;

}
