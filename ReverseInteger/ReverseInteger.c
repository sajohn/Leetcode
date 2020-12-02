

int reverse(int x){

    
    if(x ==0 || x ==1 || x ==-1)
        return x;
    
    if(x>0 && x>INT_MAX)
      return INT_MAX;
    
    if(x<0 && x<INT_MIN)
      return INT_MIN;
    
    long long modulo=0;
      
    while(x!=0)
    {
        modulo = modulo*10 + x%10;  //3
        x /=10;       //12
    }
    
    return (modulo >INT_MAX || modulo <INT_MIN? 0: modulo);
}
