bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize){

    if(coordinates == NULL || coordinatesSize == 0 ||coordinatesColSize == NULL )
        return false; 
    
    if(coordinatesSize <=2)
        return true; 
    
    
    //Define line
    // y = ax + b

    
    int x0 = coordinates[0][0], y0 =  coordinates[0][1];
    int x1 = coordinates[1][0], y1 =  coordinates[1][1];
 
   
    
    for(int i = 2; i < coordinatesSize; i++)
    {
          int x3 = coordinates[i][0];
          int y3 = coordinates[i][1];

         if((x3- x1)*(y3-y0)  != (x3-x0)*(y3- y1))  
             return false; 
    }
    
    return true; 
}
