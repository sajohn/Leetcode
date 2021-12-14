int change(int amount, int* coins, int coinsSize){
    

   int i, j, x, y; 

   if(coinsSize ==0  && amount ==0)
         return 1; 
    else if(amount >= 1 && coinsSize <=0)
         return 0;
     else if(amount == 0 && coinsSize <0)
        return 0;
   
    
    int table[amount + 1][coinsSize]; 

    for (i = 0; i < coinsSize; i++) 
        table[0][i] = 1; 

    for (i = 1; i < amount + 1; i++) 
    { 
        for (j = 0; j < coinsSize; j++) 
        { 
            x = (i-coins[j] >= 0) ? table[i - coins[j]][j] : 0; 
 
            y = (j >= 1) ? table[i][j - 1] : 0; 

            table[i][j] = x + y; 
        } 
    } 
    return table[amount][coinsSize - 1]; 
}
