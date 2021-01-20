

//If I bought stock then I need to sell it on next increase since its not allowed to buy before selling
//A simple for loop would do since i-1 comes before i and 

int maxProfit(int* prices, int pricesSize){
//bought at ith day 
//sold at jth day j>i && Find Maxdiff (P[j], P[i]) 
    if(!prices || pricesSize<=1)
        return 0;
    
    int min = prices[0], idxMin=0, idxMax=0, diff =0, max=0;
    
    for(int i =1; i< pricesSize; i++)
    {
       if(prices[i] > prices[i-1])
       {
        max += (prices[i] - prices[i-1]);
       }
    }
    return max;
}
