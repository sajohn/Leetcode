typedef struct Point{
    int row; 
    int col; 
    struct Point* next; 
}Point;


void setRowCol(int** matrix, int matrixSize, int matrixColSize, Point* head){
    
    if(head == NULL || matrix == NULL || matrixSize == 0 || matrixColSize ==0)
        return ; 
    
    
    while(head != NULL){
        int row = head->row;
        int col = head->col; 
        
        memset(matrix[row], 0, sizeof(int)*matrixColSize);
        
       for(int i =0; i <matrixSize; i++)
           matrix[i][col] = 0; 
       
        
        head = head->next; 
    }
       
}


void setZeroes(int** matrix, int matrixSize, int* matrixColSize){

    if(matrix == NULL ||  matrixSize == 0 || matrixColSize == NULL)
        return ; 
    Point dummy = {0};
    dummy.next = NULL; 
    Point* head = &dummy; 
    if(head == NULL)
        return; 
    
    for(int i =0; i <matrixSize; i++){
        for(int j =0; j < *matrixColSize; j++){
            
            if(matrix[i][j] == 0){
                head->next = (Point*)calloc(1, sizeof(Point));
                head->next->row = i; 
                head->next->col = j; 
                head = head->next; 
            }
            
        }
    }
    
    
    setRowCol(matrix,matrixSize, *matrixColSize, dummy.next);
}
