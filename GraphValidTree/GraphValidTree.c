// You can create a tree from Graph if there is no cycle. 

bool Dfs(int** adj, int* visited, int idx, int* course, int prev, int* count ){           
 
    if(adj == NULL || visited == NULL || course == NULL )
        return false; 
    
    if(visited[idx] == 1 ) //This was causing delay and timelimit exceed since it was also a necessary condition to check. 
         return false;  
 
    visited[idx] = 1;  //Processed 
    (*count)++;
    for(int i = 0; i< course[idx]; i++ ) {
        if( adj[idx][i] == prev)
            continue; 
        if(!Dfs(adj, visited, adj[idx][i], course, idx, count))
            return false; 
    }
 
    return true; 
}

bool validTree(int n, int** edges, int edgesSize, int* edgesColSize){

    if(edges == NULL || edgesColSize == 0  )
        return false; 
  if(edgesSize == 0 && n == 1)
      return true; 
  if(edgesSize == 0 && n > 1)
      return false; 
    
    int** adj = (int**)calloc(n, sizeof(int*));
    if(adj == NULL)
        return false; 
    int* course = (int*)calloc(n, sizeof(int));
    int* visited = (int*)calloc(n, sizeof(int));
    if(visited == NULL || course == NULL)
        return false; 
    
    //Create adjacency list
    for(int i =0; i < edgesSize; i++) {
         int indexu = edges[i][0]; 
         int indexv = edges[i][1]; 
          if(adj[indexu] != NULL) {
                adj[indexu] = realloc(adj[indexu], (course[indexu]+1)*sizeof(int));
            } else {
                adj[indexu] = calloc( 1,sizeof(int)); 
            }
        
          if(adj[indexv] != NULL) {
                adj[indexv] = realloc(adj[indexv], (course[indexv]+1)*sizeof(int));
            } else {
                adj[indexv] = calloc( 1,sizeof(int)); 
            }
        
        adj[indexu][course[indexu]++] = edges[i][1];
        
        adj[indexv][course[indexv]++] = edges[i][0];
    }
 //Do DFS
     int count = 0; 
             if(edgesSize !=0 && !Dfs(adj, visited,edges[0][0], course,-1, &count ) )
                return false; 
 //If all not visited (i.e. not connected return false)

    if(count != n)
        return false; 
    
    return true; 
}
