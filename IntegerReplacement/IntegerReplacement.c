
int integerReplacement(int n)
{
    if(n == 0 || n == 1)
        return 0;
    if(n == INT_MAX)
        return 32;
     if(n ==3)
        return 2;
    
   //Base case is 3
    if(n&1)
    {
        if(((n&3)^3) ==0)
            return 1+ integerReplacement(n+1);
         else
           return 1+integerReplacement(n-1);

    }
    else 
    {
        if((n&(n-1)) == 0 & n!=0)
            return log2(n);
        
        return 1+ integerReplacement(n>>1);
    }
}


