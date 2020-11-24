//Timelimit exceed 
int nthUglyNumber(int nn)
{
    
    if(nn < 7)
        return nn; 
    
   int val[7] = {0};
    val[0] = 1;
    val[1] = 2; 
    val[2] = 3;
    val[3] = 4; 
    val[4] = 5;
  
    int i=1, count =0; 
    
    while(count< nn)
    {
        int n = i;
        while(n)
        {
                if(n==1)
                {
                    count++;
                    break;
                }
               if(n%2 == 0 && count <nn)
                   n = n/2; 
                else if( n%3==0 && count <nn)
                    n = n/3; 
                 else if( n%5 == 0 && count <nn)   
                     n = n/5; 
                else
                    break;
            
        }
        if(count == nn)
            return i;
        i++;
    }
    
    return i;
}

