typedef struct Point{
    
    int row;
    int col; 
    struct Point* next; 
}Point;

bool isValid(int i, int j, int roomSize, int roomColSize)
{
    if((i>=0 && i< roomSize) && (j>=0 && j< roomColSize))
        return true; 
    
    return false;
}


void wallsAndGates(int** rooms, int roomsSize, int* roomsColSize){

    
    if(rooms == NULL || roomsSize == 0 || roomsColSize == 0)
        return ; 
    
    Point fake; 
    fake.next = NULL; 
    Point *ret = NULL,*end = NULL, *tmp = NULL;
    ret = &fake; 
    
    //Basically enque gates..
    for(int i =0; i < roomsSize; i++){
        for(int j = 0; j < *roomsColSize; j++){
              if(rooms[i][j] == 0){
                  ret->next = calloc(1,sizeof(Point));
                  ret->next->row = i; 
                  ret->next->col = j; 
                  ret = ret->next; 
              }
        }
    }
   end = ret;
   ret = fake.next; 
    
    while(ret != NULL){
    
        int r = ret->row;
        int c = ret->col; 
        
    //Check around this gate for any path 
        
    if(isValid(r, c+1, roomsSize, *roomsColSize)){
            if(rooms[r][c+1] == INT_MAX){
                 rooms[r][c+1] = rooms[r][c] +1; 
                 end->next = calloc(1,sizeof(Point));
                  end->next->row = r; 
                  end->next->col = c+1; 
                  end = end->next; 
            }
    }
     if(isValid(r, c-1, roomsSize, *roomsColSize)){
            if(rooms[r][c-1] == INT_MAX){
                 rooms[r][c-1] = rooms[r][c] +1; 
                  end->next = calloc(1,sizeof(Point));
                  end->next->row = r; 
                  end->next->col = c-1; 
                  end = end->next; 
            }
    }  
     if(isValid(r+1, c, roomsSize, *roomsColSize)){
            if(rooms[r+1][c] == INT_MAX){
                 rooms[r+1][c] = rooms[r][c] +1; 
                 end->next = calloc(1,sizeof(Point));
                 end->next->row = r+1; 
                 end->next->col = c; 
                 end = end->next; 
            }
    }
        
     if(isValid(r-1, c, roomsSize, *roomsColSize)){
            if(rooms[r-1][c] == INT_MAX){
                 rooms[r-1][c] = rooms[r][c] +1;
                 end->next = calloc(1,sizeof(Point));
                 end->next->row = r-1; 
                 end->next->col = c; 
                 end = end->next; 
            }
    }
        tmp = ret; 
        ret = ret->next;
        free(tmp);
        
        }
    
    
}
