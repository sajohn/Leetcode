//If we sort by start of the interval
//To mimimize the overlap on right side with upcoming interval
//Remove the current interval which has larger right side
//This enables least collision with upcoming interval (why? because right sides are sorted )

int comp(const void*a,const void*b){
    int  x = ((int **)a)[0][0];
    int y = ((int **)b)[0][0];
    if(x > y)
        return 1;
    else if(x < y)
        return -1;
    return 0;
    
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize){    
    
    qsort(intervals, intervalsSize, sizeof(intervals[0]), comp);
    int end, number = 0; 
    end = intervals[0][1];
 
    for(int i = 1; i<intervalsSize; i++){
        
        if( intervals[i][0] < end ){
            number++;
            if(intervals[i][1] < end )
                 end = intervals[i][1]; 
            
        }else
            
            end = intervals[i][1];
        
    }
    
    return number;
}

  
