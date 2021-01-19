int maxProfit(int* prices, int pricesSize){
//bought at ith day 
//sold at jth day j>i && Find Maxdiff (P[j], P[i]) 
    if(!prices || pricesSize<=1)
        return 0;
    int minprice = INT_MAX;
        int maxprofit = 0;
        for (int i = 0; i < pricesSize; i++) {
            if (prices[i] < minprice)
                minprice = prices[i];
            else if (prices[i] - minprice > maxprofit)
                maxprofit = prices[i] - minprice;
        }
        return maxprofit;
}
