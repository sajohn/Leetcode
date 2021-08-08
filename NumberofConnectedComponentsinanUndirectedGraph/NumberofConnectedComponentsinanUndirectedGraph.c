// You can create a tree from Graph if there is no cycle. 

void Dfs(int** adj, int* visited, int idx, int* course){           
 
    if(adj == NULL || visited == NULL || course == NULL )
        return ; 
   
    if(visited[idx] == 1)
        return; 
    
    visited[idx] = 1;  //Processed 

    for(int i = 0; i< course[idx]; i++ ) {
       if(visited[adj[idx][i]] == 0){
         Dfs(adj, visited, adj[idx][i], course);
       }
    }
 
}


int countComponents(int n, int** edges, int edgesSize, int* edgesColSize){

     if(edges == NULL || edgesColSize == 0  )
        return 0; 
  if(edgesSize == 0 && n == 1)
      return 1; 
  if(edgesSize == 0 && n > 1)
      return n; 
    
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
     int connected  =0; 
    
    for(int i =0; i < n; i++)
    {
           if(visited[i] == 0  ){
              connected++; 
              Dfs(adj, visited, i, course);
                 
           }
        
    }
    
 //If all  visited (i.e. connected return 0)

   return connected; 
    
}
