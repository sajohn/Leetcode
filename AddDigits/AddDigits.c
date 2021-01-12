

int addDigits(int n)
{ 
    if(n <0)
        return; 

    if(n <=9)
        return n;
    int tmp =0;
    while(n)
    {
        tmp += n%10;
        n = n/10;
        
        if(n==0 && tmp >=10)
        {
            n = tmp;
            tmp =0;
        }
    
    }
    
    return tmp;
    
}
