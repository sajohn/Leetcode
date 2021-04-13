int Max(int a, int b)
{
    return (a>b? a: b);
}
int Min(int a, int b)
{
    return (a<b? a: b);
}

int maxArea(int* height, int heightSize)
{
  if(heightSize == 0 || !height || heightSize==1)
   {
      return 0; 
   }
    
   int left = 0, right= heightSize-1, maxarea=0; 

    while(left <=right)
    {
        
        maxarea = Max(maxarea, Min(height[left], height[right])*abs(left-right));
        
        height[left]< height[right]? left++:   right--;
    
    }
    
    return maxarea;
    
}
