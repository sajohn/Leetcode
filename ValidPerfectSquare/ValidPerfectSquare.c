

bool isPerfectSquare(int num){

    if(num<0)
        return false;
    
    if(num == 0 || num ==1)
        return true;
    
    long first = 1;
    long last = num;
    long mid = first + (last-first)/2;
        
     while(first <=last)
     {
          mid = first + (last-first)/2;
         if(mid*mid == num )
         {
             return true;
         }
         else if(mid*mid<num)
         {
             first = mid+1;
         }
         else if(mid*mid > num)
         {
             last = mid-1;
         }
     }
   
    return false;
}
