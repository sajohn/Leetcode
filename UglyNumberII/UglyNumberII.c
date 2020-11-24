unsigned int FindMin(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int min = 0;
    min = (a<b? a:b);
    return (min = (min<c? min:c) );
}

int nthUglyNumber(int n)
{

    unsigned res[1690] = {0};
    int ugly =0, i2 =0, i3=0, i5=0;
    res[0] = 1;
  
  
    for(int i =1; i <1690; i++)
    {
        /*
        //How did you reach to find the ith ugly number
        if you found it by previous i2? increase i2 
        if you found it by previous i3? increase i3 
        if you found it by previous i5? increase i5 
        */
         ugly =   FindMin(2*res[i2], 3*res[i3], 5*res[i5]);
        
        res[i]  = ugly;
        
        if(ugly == 2*res[i2])
            i2++;
         if(ugly == 3*res[i3])
            i3++;
         if(ugly == 5*res[i5])
            i5++;
    
    }
    return res[n-1];
    
}


