
int cmp(void* a, void* b){
    return ( *(int*)b - *(int*)a );
}

int largestInteger(int num){

    if(num == 0)
        return 0;
    
    
    int even =-1, odd =-1, oddarr[10], evenarr[10], tmp =num, idx =0, final =0, val = 0;
    long  place = 1;
    bzero(oddarr, sizeof(oddarr));
    bzero(evenarr, sizeof(evenarr));
    
    while(tmp){
        val = tmp%10;
    if(val%2 == 0)
        evenarr[++even] = val;
      else
        oddarr[++odd] = val;
        idx++; 
        tmp /=10;
        
    }
    
    qsort(evenarr, 10, sizeof(int), cmp);
    qsort(oddarr, 10, sizeof(int), cmp);
    idx--; 
    tmp = 0; 
    while(idx>=0)
    {
        val = num%10;
        if(val%2 == 0)
            tmp = evenarr[even--];
        else
            tmp = oddarr[odd--]; 
        
        final = final + tmp*place;
        place *= 10; 
        
        num /=10;
        idx--;
    }
    
    return final;
}
