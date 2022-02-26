

int minCost(int** costs, int costsSize, int* costsColSize){
    
    if(costs == NULL || costsSize == 0 || costsColSize == NULL)
        return 0; 
    
    int  min = INT_MIN;

    for(int i = 1; i < costsSize; i++){
    
            costs[i][0] += (costs[i-1][1]>costs[i-1][2]? costs[i-1][2]: costs[i-1][1]);
            costs[i][1] += (costs[i-1][2]>costs[i-1][0]? costs[i-1][0]: costs[i-1][2]);
            costs[i][2] += (costs[i-1][1]>costs[i-1][0]? costs[i-1][0]: costs[i-1][1]);
        
    }
    min = costs[costsSize-1][0] < costs[costsSize-1][1]? costs[costsSize-1][0]:costs[costsSize-1][1];
    min = min < costs[costsSize-1][2]? min: costs[costsSize-1][2]; 
    
return min;
}
