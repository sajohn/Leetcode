    
   /* 
    []-->
    []-->
    []-->
    
    */

bool Dfs(int** adj, int* visited, int idx, int* course ){           
 
    if(adj == NULL || visited == NULL || course == NULL || )
        return false; 
    
      if(visited[idx] == 2) //This was causing delay and timelimit exceed since it was also a necessary condition to check. 
         return true;  
    
    if(visited[idx] == 1) 
        return false; 
          
    visited[idx] = 1;  //Processing
    
    for(int i = 0; i< course[idx]; i++)
    {
        if(!Dfs(adj, visited, adj[idx][i], course))
            return false; 
    }
    visited[idx] = 2;  //Processed
    
    return true; 
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
    
    if(prerequisites == NULL || prerequisitesSize < 0 || prerequisitesColSize == NULL)
        return false; 
    
    if(numCourses == 0 || prerequisitesSize ==0)
        return true; 
    
    int** adj = (int**)calloc(numCourses, sizeof(int*));
    if(adj == NULL)
        return false; 

    int* course = (int*) calloc(numCourses, sizeof(int));
    if(course == NULL)
        return false; 
    
      for(int i =0; i < prerequisitesSize; i++)
      {
        int size = 0, index = prerequisites[i][0]; 
          
        if(adj[index] != NULL)
            {
                adj[index] = realloc(adj[index], (course[index]+1)*sizeof(int));
            
            }else {
                adj[index] = calloc( 1,sizeof(int)); 
  
        }
          adj[index][ course[index]++] = prerequisites[i][1];
      }
     
    
    //if number of visited courses are not done keep checking via dfs is cycle is there? 
    int* visited = (int*)calloc(numCourses, sizeof(int));
    if(visited == NULL)
        return false; 
    
    for(int i = 0; i< numCourses; i++)
    {
        if(adj[i] != NULL && visited[i] == 0)  //Not processed then process it 
        {

            if(!Dfs(adj, visited, i, course) )
                return false; 
        }
     }
    
return true; 
    
}
