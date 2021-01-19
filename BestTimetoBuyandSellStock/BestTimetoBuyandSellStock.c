

int maxProfit(int* prices, int pricesSize){
//bought at ith day 
//sold at jth day j>i && Find Maxdiff (P[j], P[i]) 
    if(!prices || pricesSize<=1)
        return 0;
    
    int min = prices[0], idxMin=0, idxMax=0, diff =0, max=0;
    
    for(int i =0; i< pricesSize; i++)
    {
        
       if(prices[i]<= min)
       {
            min = prices[i];
             idxMin = i;
        
            for(int j = idxMin+1; j<pricesSize; j++)
            {
                if(prices[j]<prices[idxMin])
                    continue;
                diff = prices[j]-prices[idxMin];
                if(diff >max)
                {
                    max = diff;
                    idxMax = j;
                }
            }  

        }
    }
    
    return max;
}


