

bool isPowerOfTwo(int n){
 if (n==0 || n <= INT_MIN || n>= INT_MAX )
     return false;
    
    if(n & (n-1))
        return false;
    
    return true;
}
