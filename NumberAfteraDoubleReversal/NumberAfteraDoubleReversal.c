

int reverse(int x){

    
//     if(x ==0 || x ==1 || x ==-1)
//         return x;
    
    if((x>INT_MAX) ||( x<INT_MIN))
      return 0;
    
 int modulo=0;
      
    while(x!=0)
    {
        
       if(modulo > INT_MAX/10 || modulo < INT_MIN/10) //This is intercepting modulo becoming > INT_MAX or becoming < INT_MIN before next step
            return 0; 
        modulo = modulo*10 + x%10;  //3
        x /=10;       //12
    }
    
    return modulo;
}

bool isSameAfterReversals(int num){

    if(num == 0)
        return true; 
    
    if(num%10 == 0)
        return false; 
    
    int reverse1 = reverse(num);
    
    int reverse2 = reverse(reverse1);
    
    return (reverse2 == num);
    
}
