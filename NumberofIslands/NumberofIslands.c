int isValid(int r, int c, int gridSize, int gridColSize)
{
    if((r >=0 && r< gridSize)&& (c>=0 && c < gridColSize))
        return 1;
    
    return 0;
}

int dfs(char** grid,int i , int j, int gridSize, int gridColSize, int** visited)
{
    
    if(grid == NULL || gridSize == 0 || gridColSize == 0 && visited==NULL)
        return 0;

    int area = 0;
    
    if(grid[i][j] == '1' && isValid(i, j, gridSize, gridColSize))
    {
        
        if(isValid(i, j+1, gridSize, gridColSize) && visited[i][j+1]==0 && grid[i][j+1] =='1')
        {
            visited[i][j+1] =1;
            area = area+1+dfs(grid, i, j+1, gridSize, gridColSize, visited);
        }
         else
             area += 0;
            
         if(isValid(i, j-1, gridSize, gridColSize) && visited[i][j-1]==0 && grid[i][j-1] =='1')
        {
            visited[i][j-1] =1; 
            area = area+1+ dfs(grid, i, j-1, gridSize, gridColSize, visited);
        }
         else
             area += 0;
             
         if(isValid(i+1, j, gridSize, gridColSize) && visited[i+1][j]==0 && grid[i+1][j] =='1')
        {
            visited[i+1][j] =1;
            area =area+1+ dfs(grid, i+1, j, gridSize, gridColSize, visited);
        }
         else
             area += 0;
             
        if(isValid(i-1, j, gridSize, gridColSize) && visited[i-1][j]==0 && grid[i-1][j] =='1')
        {
            visited[i-1][j] =1;
            area =area+1+ dfs(grid, i-1, j, gridSize, gridColSize, visited);
        }
         else
             area += 0;
            
    }
    return area;
}

int numIslands(char** grid, int gridSize, int* gridColSize)
{

    if(grid == NULL || gridSize == 0 || *gridColSize == 0)
        return 0; 
  
    int count =0, area =0;
   
    int** visited = (int**)malloc(gridSize*sizeof(int*));
    if(visited == NULL)
        return 0;

    memset(visited, 0, sizeof(int*)*gridSize);
    
    for(int i =0; i < gridSize; i++){
        visited[i] = (int*)malloc(*gridColSize*sizeof(int));
        memset(visited[i], 0, (*gridColSize)*sizeof(int));
    }
   
    
    for(int i =0; i < gridSize; i++)
    {
        for(int j =0; j<*gridColSize; j++)
        { 
            if(visited[i][j]== 0 && grid[i][j] =='1')
            {

                visited[i][j] = 1; 
                area = 1 + dfs(grid, i, j, gridSize,*gridColSize, visited);
        ///If Area is coming out to be >0 then count is ++ else its regular already counted by doing 1+ dfs above
                if(area >=1)
                count += 1;
            }
        }
    }
        for(int i =0; i < gridSize; i++){
        free(visited[i]);
            
        }
    free(visited);
    visited = NULL;
    
    return count;
    
}


