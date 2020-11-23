int min(int a , int b)
{
    return (a<b? a:b);
}
int max(int a , int b)
{
    return (a>b? a:b);
}
int FindMin(int** dp, int** dungeon, int dungeonSize, int dungeonColSize)
{     
    if(dungeon == NULL || dungeonSize == 0 || dungeonColSize == 0)
        return INT_MIN;
    
    for(int i = dungeonSize-1; i >=0; i--)
    {  
        for(int j = dungeonColSize-1; j >=0; j--)
        {
            if(i ==  dungeonSize-1 && j == dungeonColSize-1 )
                dp[i][j] = min(0, dungeon[i][j]);
            else if(i ==  dungeonSize-1 )
                dp[i][j] = min(0, dungeon[i][j]+dp[i][j+1]);
            else if(j ==  dungeonColSize-1 )
                dp[i][j] = min(0, dungeon[i][j]+dp[i+1][j]);
            else 
                dp[i][j] = min(0, (dungeon[i][j] +max(dp[i][j+1], dp[i+1][j])));
        }
    }
   return (1+abs(dp[0][0]));
}

int calculateMinimumHP(int** dungeon, int dungeonSize, int* dungeonColSize){
    
    if(dungeon == NULL || dungeonSize == 0 || dungeonColSize == NULL)
        return INT_MIN;
    
    int* dp[dungeonSize];
    for(int i = 0; i <dungeonSize; i++ )
        dp[i] = (int*)calloc(*dungeonColSize, sizeof(int));
    
    return  FindMin(dp, dungeon, dungeonSize,*dungeonColSize);
}
