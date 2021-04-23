

bool isRobotBounded(char * instructions){
    
    if(instructions == NULL)
        return false;
    
    
   const int east = 0, west =1, north =2, south=3;
   
    int x = 0, y = 0,  k =0; 
    int  direction = north;
    
    while(instructions[k]!= '\0' )
    {
        if(instructions[k] == 'G')
        {
            switch(direction){
                case east :
                    x+=1; y+=0;break;
                case west  :
                    x-=1; y+=0;break;
                case north :
                    x+=0; y+=1;break;
                case south :x+=0; y-=1;break;
                }
        }
        else if(instructions[k] == 'L')
        {
            if(direction == east)
                direction = north;
            else  if(direction == west)
                direction = south;
            else if(direction == north)
                direction = west;
            else if(direction == south)
                direction = east;
        }
        else if(instructions[k] == 'R')
        {
            if(direction == east)
                direction = south;
            else  if(direction == west)
                direction = north;
            else if(direction == north)
                direction = east;
            else if(direction == south)
                direction = west;
            
        }
         
            
            k++;
    }
    
    
    
    return ((direction != north ) || (x ==0 && y ==0) ); 

}
