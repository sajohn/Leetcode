bool IsPrime(int n)
{
    
    if(n <= 1)
        return false;
    
    for(int i = 2; i*i <= n; i++)
        if(n%i == 0)
            return false; 

    return true; 
}

int countPrimes(int n)
{
   if(n == 0)
       return 0; 
    
    int count =0; 
    
   for(int i = 1; i <n; i++)
   if(IsPrime(i))
       count++;
   
    return count;
    
}
