//Try bottoms up 

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    
    if(triangle == NULL || triangleSize == 0 || triangleColSize == NULL)
        return 0; 
    
    int min = 0, j =0; 
       
    for(int i = triangleSize-2; i >=0; i--)
    {
        j = 0; 
        while( j < (triangleColSize[i]))
        {
             
            triangle[i][j] = ( triangle[i+1][j] < triangle[i+1][j+1]? triangle[i+1][j]: triangle[i+1][j+1]) + triangle[i][j];
            j++;
        }
    }

    return triangle[0][0]; 
}
