bool isPowerOfFour(int n)
{
   /*If power of 4   
     only 1 bit is set and rest should be zero
     no. of zeros should be even
     set bit is always at even bit position
     number and -number == number 
     number && odd bit position must all give zero
   */

     if((n>0)&& (n & (n-1))==0 && (n-1)%3 ==0)
           return true;
     

  return false;
