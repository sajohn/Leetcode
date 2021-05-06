

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){

    if(cost == NULL || gas == NULL || costSize == 0)
        return -1; 
    
    int curgas = 0, cur=0, total =0; 
    int i =0;
    for(i = 0; i < gasSize; ){
        total = gas[i] - cost[i] ;
        
        if(total < 0){
            i++;
            total = 0; 
        }
        else{
            cur = i;
            while((cur+1)%gasSize != i){
                cur = (cur+1)%gasSize;
                total+=(gas[cur] - cost[cur]);
                if(total< 0){
                    break;
                }
              
            }
            if(total >=0)
                return i;
            else if(total <=0 && i == gasSize -1)
                return -1;
            else{
              i++;
             total = 0; 
            }
        }
    }
    
    return (total < 0 ? -1: (i==gasSize && total<=0 ? -1: i)); 

}

