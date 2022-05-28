bool isPossible(int* weights, int weightsSize, int sum, int D){
    if(weights == 0 || weightsSize == 0 || D == 0)
        return 0;
    
    int cur_sum = 0, count = 1;
    
    for(int i =0; i < weightsSize; i++){
        
        cur_sum += weights[i];
        
        if(cur_sum > sum){
            count++; 
            cur_sum =  weights[i]; 
        }
        
        if(count > D)
            return false; 
    }
    
        
    return true;    
}

int shipWithinDays(int* weights, int weightsSize, int D){
    
    if(weights == 0 || weightsSize == 0 || D == 0)
        return 0;
    
   int minweight = 0, lower = 0, upper =0, mid =0, totalweight = 0; 
    
    for(int i =0; i < weightsSize; i++){
        
        if(weights[i] > lower)
            lower = weights[i];
        
        totalweight+=weights[i];
           
    }

    upper = totalweight; 
    
    while(lower < upper) {
        
        mid = lower + (upper -lower)/2;    
        
        if(isPossible(weights, weightsSize, mid, D)){

            upper = mid;
        }
        else
             lower = mid+1;

    } 
    
    return upper; 
}

/*
[10,50,100,100,50,100,100,100]
5
[1,2,3,4,5,6,7,8,9,10]
5
[3,2,2,4,1,4]
3
[1,2,3,1,1]
4

*/
