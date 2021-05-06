typedef struct {
    int i; 
    int j; 
    int val;
}Queue;


bool isValid(int i, int j, int gridSize, int gridColSize)
{
    if((i>=0 && i<gridSize) && (j>=0 && j < gridColSize))
        return true; 
    
    return false;
}


void markRotten(int** grid, int gridSize, int* gridColSize, Queue* q, int k, int* val, int* freshOranges) {
     if( grid== NULL || gridSize==0 ||gridColSize == NULL || q == NULL)
        return ;
    
    int i = q[k].i; 
    int j = q[k].j; 
    int size = *val; 
    if(grid[i][j] == -2)
    {
        if(isValid(i, j+1, gridSize, *gridColSize) && grid[i][j+1] == 1)
        {
           grid[i][j+1] = -2;
           q[size].i = i; 
           q[size].j = j+1; 
           q[size].val = q[k].val +1; 
           (*freshOranges)--;
           size++; 
        }
            
        if(isValid(i, j-1, gridSize, *gridColSize) && grid[i][j-1] == 1){
           grid[i][j-1] = -2;

           q[size].i = i; 
           q[size].j = j-1; 
           q[size].val = q[k].val +1; 
            (*freshOranges)--;
           size++; 
        }
            
        if(isValid(i+1, j, gridSize, *gridColSize) && grid[i+1][j] == 1){
            grid[i+1][j] = -2;
         
           q[size].i = i+1; 
           q[size].j = j; 
           q[size].val = q[k].val +1; 
             (*freshOranges)--;
            size++; 
        }
            
        if(isValid(i-1, j, gridSize, *gridColSize) && grid[i-1][j] == 1){
           grid[i-1][j] = -2;
           q[size].i = i-1; 
           q[size].j = j; 
           q[size].val = q[k].val+1; 
             (*freshOranges)--;
           size++; 
        }
        
        *val = size; 
    }
}



int orangesRotting(int** grid, int gridSize, int* gridColSize){
   
    if( grid== NULL || gridSize==0 ||gridColSize == NULL)
        return -1; 
    
    int size = 0, k = 0, freshOranges=0; 
     
    Queue q[gridSize*(*gridColSize)];
    memset(q, 0, sizeof(Queue)*gridSize*(*gridColSize));
    
    for(int i = 0; i < gridSize; i++)
    {
        for(int j =0; j< *gridColSize; j++)
        {
            if(grid[i][j] == 2)
            {   
                if(q){
                     q[size].i = i; 
                     q[size].j = j;
                     q[size].val = 0;
                     size++; 
                }
                grid[i][j] = -2;
            }
            else  if(grid[i][j] == 1)
                freshOranges++; 
        }
    }

    k = 0; 
 
    while(k<size) {
        markRotten(grid, gridSize, gridColSize, q, k, &size, &freshOranges);
         k++; 
    }
    
    if( freshOranges >0)
        return -1; 
    else
        return (size>0? q[size-1].val: 0); 

}
