int hammingWeight(uint32_t n) 
{
    int count =0;
    
    if(n ==0)
        return 0;
    if(n ==1)
        return 1;

    while(n)
    {
        count++;
        n &=(n-1);
    }
    return count;
}
