

int findTheWinner(int n, int k){
    
    if(n == 1)
        return 1; 
       
    return ((findTheWinner(n - 1, k) + k - 1) % n )+ 1;
 
}


//One tutorial tells if frame of reference for Gun initially is at index 0 
//In new reference it will be at (previous + k-1  % (n)) +1 
//+1 is done because we have index starging from 1. 
