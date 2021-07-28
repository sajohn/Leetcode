

int tribonacci(int n){
    
    if(n == 0 || n == 1)
        return n; 
 if(n== 2)
     return 1; 

    int T0 = 0, T1 = 1, T2 = 1, Tn= 0;
    //Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0
    
    for(int i = 3; i <=n; i++)
    {
        Tn = T0+T1+T2; 
        T0 = T1; 
        T1 = T2; 
        T2 = Tn; 
        
    }
    
    return Tn; 
}
