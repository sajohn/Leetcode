typedef struct Indx{
    int val;
    int idx; 
    
}Indx; 


void getMin(int* arr, int size, Indx* mins){
    
    int firstmin = INT_MAX;
    int secondmind = INT_MAX; 
    
    if(arr == NULL || size == 0)
        return; 
    mins[0].val =INT_MAX;
    mins[0].idx = 0;
    mins[1].val = INT_MAX;
    mins[1].idx = 0;
    
    for(int i =0; i < size; i++)
    {
        if(arr[i] <= mins[0].val){
            mins[1].val = mins[0].val;
            mins[1].idx = mins[0].idx;
            mins[0].val = arr[i];
            mins[0].idx = i;
        }
        else if(arr[i] < mins[1].val){
            mins[1].val = arr[i];
            mins[1].idx = i;
        }
    }
    
    return ;
}


int minCostII(int** costs, int costsSize, int* costsColSize){
    
    if(costs == NULL || costsSize == 0)
        return 0; 
    
   // int min = INT_MAX; 
    Indx mins[2] = {{INT_MAX, 0}, {INT_MAX, 0}};
    //Achiving O(Nk) was something I couldn't think 
    //But observation is when you are at row i the two min values from previous row are needed to update ith row
    //
     getMin(costs[0], *costsColSize, &mins);
    
    for(int i =1; i< costsSize; i++){
        for(int j =0; j< *costsColSize; j++){

          costs[i][j] += (mins[0].idx != j? mins[0].val: mins[1].val);
    }
        getMin(costs[i], *costsColSize, &mins); 
  }

    return (mins[0].val < mins[1].val?  mins[0].val : mins[1].val);
}
