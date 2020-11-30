

int mySqrt(int x)
{
    if(x < 2)
      return x;
    if(x ==2)
        return 1;
    
    int right = x/2, left = 2;
    long square = 0, mid = 0;
    
     while(left <=right )
    {
       mid = left + (right -left)/2;
       square = mid*mid;
     
     if(square == x)
           return mid;
     else if(square>x)
             right = mid -1;
     else if(square < x)
              left = mid+1;
        
    }
    //If I return mid and the sauare > x then its wrong so after right has been updated I shall return right;
    //If I find square < x left become mid+1 and if left > right loop terminates hence right is still the closest
    return right;
}
