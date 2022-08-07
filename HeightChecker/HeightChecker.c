int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int heightChecker(int* heights, int heightsSize){
    
    if(heights == NULL || heightsSize == 0)
        return 0; 
    
    int count = 0; 
   int* tmp = (int*)calloc(heightsSize, sizeof(int));
     if(tmp== NULL)
        return 0; 
    
    memcpy(tmp,heights, heightsSize*sizeof(int));
    
    qsort(tmp, heightsSize, sizeof(int), cmpfunc);

    
    for(int i =0; i < heightsSize; i++)
        if(tmp[i] != heights[i])
            count++; 

    free(tmp);

    return count; 
}
