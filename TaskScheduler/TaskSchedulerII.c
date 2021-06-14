
inline int Min(int a , int b)
{
        return (a<b? a:b);    
}
inline int Max(int a , int b)
{
        return (a>b? a:b);    
}

int leastInterval(char* tasks, int tasksSize, int n) {    
    
    if(tasks == NULL || tasksSize == 0)
        return -1; 
    if(n == 0)
        return tasksSize; 
 
    int frequency[26] = {0};
    int maxFrequency = INT_MIN, index =0;
    for(int i =0; i < tasksSize; i++){
            frequency[tasks[i] - 'A']++;
        
       if( maxFrequency<  frequency[tasks[i] - 'A']){
            maxFrequency =  frequency[tasks[i] - 'A'];
            index = tasks[i] - 'A'; 
       }
    }
     
   int idleSlots = (maxFrequency -1) * (n);
 
       for(int i =25; i >=0 && idleSlots >0 ; i--){
       
          if(i != index)
           idleSlots -= Min(maxFrequency-1, frequency[i] );
       }
    
    return tasksSize+Max(0, idleSlots);
    
}
