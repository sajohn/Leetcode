//1 2 3 4 5 6 7 8 9 10 11 12 13
//LCM * GCD = N
//If number is M and divisor is A, count of numbers divisible by A is M/A

long gcd(long a, long b)
{
//     if(a == 0 )
//         return b; 
//     if(b== 0)
//         return a; 
//     if(a == b)
//         return a;
    
//     return ((a>b)? gcd((a-b), b): gcd((b-a), a));
    
    if(b == 0)
        return a; 
    return gcd(b, a%b);
    
}
long lcm(long a, long b)
{
    return ((a*b)/gcd(a, b));
}
int nthMagicalNumber(int n, int a, int b){
    
    if(n == 0)
        return 0;
    if(n == 1 )
        return a; 
  
   
  // long counta = n/a; //Tell count of numbers divisible by a in range of n
   //long countb = n/b; //Tell count of numbers divisible by b in range of n
    
//upper limit = 10e9+7
    
    long end = 1e14; 
    long mod = 1e9+7; 
    long start = 1, mid =0, target=0; 
    long lcmval = lcm(a, b);
    
    while(start < end){
        
        mid = start + (end -start)/2; 
        
        target = mid/a + mid/b - mid/lcmval;
        
        if(target < n)
        {
            start = mid+1; 
        }
        else{
            end = mid; 
        }
        
    }
    
    return end%mod; 
    
}
