

int maxLength(int* ribbons, int ribbonsSize, int k){
    
    if(ribbons == NULL || ribbonsSize == 0 || k <=0)
        return 0; 
    
    int min = 1, max = INT_MIN, mid =0, count = 0; 
    
    for(int i = 0; i < ribbonsSize; i++)
        if(ribbons[i] > max)
            max = ribbons[i];
    
    
    while(min <=max){
        
        mid = min + (max-min)/2;
        count = 0; 
        for(int i =0; i< ribbonsSize; i++)
            count+= ribbons[i]/mid; 
        
        if(count < k)
            max = mid-1; //mid is not a solution
        else 
            min = mid+1; //min is not a solution
    }

    return (max<0? 0:max); 
}
