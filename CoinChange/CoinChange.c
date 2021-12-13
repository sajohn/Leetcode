
// void Subset(int* coins, int idx, int coinSize, int amount, long curSum, int* minsofar, int count)
// {
//     if(curSum >=amount)
//     {
//         if(curSum == amount){
//             *minsofar = (*minsofar>count? count: *minsofar);
//             return ; 
//         }
//         else{
//             return ; 
//         }
        
//     }
//     else if (curSum < 0)
//         return; 
    
//     for(int i = idx; i< coinSize; i++)
//     {
//         curSum += coins[i];
//         if(curSum > amount)
//         {
//              curSum -= coins[i];
//              continue; 
//         }
//         Subset(coins, i, coinSize, amount, curSum, minsofar, count+1);
//         curSum -= coins[i];
//     }
    
    
//    return ;  
// }



// int coinChange(int* coins, int coinsSize, int amount){
    
    
//      if(coins == NULL || coinsSize == 0 || amount <=0)
//          return 0; 
    
//     long curSum =0, min = INT_MAX; 
    
    
//     Subset(coins, 0, coinsSize, amount, curSum, &min, 0);

//     return (min!=INT_MAX? min: -1);
// }

int coinChange(int* coins, int coinsSize, int amount){
    
int i, j, dp[amount+1], c= 0, diff, extra;
    memset(dp, amount+1 , sizeof(dp));
    dp[0] = 0;
    
    for(i = 1; i<amount+1; i++)
        dp[i] = amount+1;
    
    //Ammount 
    for(i = 1; i< amount+1; i++ ){
        //coin
        for(j = 0; j<coinsSize; j++){   
            
            if(i - coins[j] >= 0){                
                diff = i - coins[j];
                extra = 1 + dp[diff];
                dp[i] = dp[i] < extra ? dp[i] : extra;              
            }                
        }      
        
    }
   
    if( dp[amount] == amount+1)
        return -1;
    else
        return dp[amount];
    
}

