int min(int a, int b)
{
    return (a<b? a:b);
}

int mincostTickets(int* days, int daysSize, int* costs, int costsSize){
    
    
    if(days == NULL || daysSize == 0 || costs == NULL || costsSize == 0)
        return 0; 
    
    //DP array must be of length days only
    
   int dp[daysSize +1] , day7 =0 , day30 =0; 
    memset(dp, 0, sizeof(int)*daysSize);
    
    
    for(int i =0; i < daysSize; i++)
        dp[i] = costs[2];  ///Put the maximum cost
    
    dp[daysSize] = 0; 
    
    for(int i = daysSize -1; i >=0; i-- ){
        
        day7 = day30 =i; 
        
        while(day7 < daysSize && days[day7] < days[i]+7) 
            day7++; //Farthest day7 which satisfies constraint if we use 7 days pass
        while(day30 < daysSize && days[day30] < days[i]+30) 
            day30++; //Farthest day30 which satisfies constraint if we use 30 days pass
        
        
        //Answer is min of path coming to i from cost[0], from cost[1] or from cost[2]
        dp[i] = min(costs[0] + dp[i+1], min(dp[day7]+costs[1], dp[day30]+costs[2]));
        
        
    }
    
    
    return dp[0];

}
