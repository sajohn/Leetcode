
int trap(int* height, int heightSize){
    
    if(height == NULL || heightSize == 0)
        return 0; 
    
    
    
    int left=1, right = heightSize-2, max_left = height[0], max_right = height[heightSize-1], trappedwater = 0; 
    
    
    while(left <=right){
        
        if(max_left < max_right)
        {
             if(height[left]>=max_left)
                max_left = height[left];
            else
                trappedwater += max_left-height[left];
            
            left++;
        }
        else
        {
            if(height[right]>=max_right)
                max_right = height[right];
            else
                trappedwater += max_right-height[right];
            right--;
        }
        
    }
    
return trappedwater;
}
