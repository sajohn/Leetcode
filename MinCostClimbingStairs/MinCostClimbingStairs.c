//First calculate the last cost
//cost of itslef + min(step1, step2)
//If you move back to previous position
//Cost = cost at curr position + min of next two (i and i+1) 
//so we keep updating backward. 


int min(int a , int b)
{
   return (a<b?a:b);    
}

int minCostClimbingStairs(int* cost, int costSize)
{

    if(costSize <= 2)
        return min(cost[0], cost[1]);
    
    int step1 =0, step2 =0, curcost=0;
    
      for(int i = costSize-1; i >=0; i--)
      {
         curcost = cost[i]+ min(step1, step2);
          step1 = step2;
          step2 = curcost;
          //printf("%d %d %d \n", step1, step2, curcost);
      }

return min(step1, step2);
}
