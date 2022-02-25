/* The knows API is defined for you.
      bool knows(int a, int b); */

int findCelebrity(int n) {
    
    
    //Find a potential candidate .
    //If this candidate is found check his array for all connections
    int candidate = 0; 
    
    for(int i =1; i < n; i++)
    {
        if(knows(candidate, i) )
            candidate = i;
    }
    
    
    for(int i =0; i < n; i++)
    {
          if(i != candidate && knows(candidate, i) || !knows(i, candidate))
              return -1;
    }
    
    
    return candidate; 
}
