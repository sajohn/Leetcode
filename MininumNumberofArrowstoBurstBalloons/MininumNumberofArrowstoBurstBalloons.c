int cmp(void* a, void* b){
     const int *aa = a;
    const int *bb = b;
    if (*aa < *bb)
        return -1;
    else if (*aa > *bb)
        return 1;
    else 
        return 0;
}

int cmpfunc (const void *a, const void * b) 
{
    int** aa = (int**) a; 
    int** bb = (int**) b; 
   
    if(aa[0][1] > bb[0][1])
        return 1; 
    else if(aa[0][1] < bb[0][1])
        return -1;
    else if(aa[0][1] == bb[0][1])
        return 0; 

    return -1; 
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize){

    if(points == NULL || pointsSize == 0 || pointsColSize == NULL)
        return 0; 
  
    qsort(points, pointsSize, sizeof(points[0]), cmpfunc);
    
    int* tmp = points[0];
    int count = 1; 
     
///Compare against the end of interval
///
    for(int  i =1; i < pointsSize; i++)
    {
       if(tmp[1] < points[i][0]){
           count++;
           tmp = points[i];
       }
      else if(tmp[0] > points[i][1]){
           count++;
       }
        
    }
    
    return count; 
}

