 int map[10][2] = {{0, 0}, {1, 1}, {2, INT_MIN}, {3, INT_MIN}, {4, INT_MIN}, {5, INT_MIN}, {6, 9}, {7, INT_MIN}, {8, 8},{9, 6}};


int isValid(int i)
{
     int num = 0, rm = 0, tmp = i; 
    
    
    while(i!=0)
    {
        
        rm  = i%10; 
        if(map[rm][1] == INT_MIN)
            return 0; 
        num = num*10 + map[rm][1];
        i = i/10; 
    }
    
    return (num!= tmp? 1:0);
}
   



bool confusingNumber(int n){
    
    
      return isValid(n);
}
