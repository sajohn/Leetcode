

bool hasAlternatingBits(int n)
{

    while(n!=0)
    {

        if((n&(1<<1)) ^ ((n&1)<<1))
            n = n>>1;
        else
            return false;
    }
    
    return true;
}
 
