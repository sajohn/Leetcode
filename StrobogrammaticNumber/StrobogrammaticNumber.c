 int map[10][2] = {{0, 0}, {1, 1}, {2, INT_MIN}, {3, INT_MIN}, {4, INT_MIN}, {5, INT_MIN}, {6, 9}, {7, INT_MIN}, {8, 8},{9, 6}};


bool isValid(char* str)
{
    if(str == NULL)
        return false; 
    
    int  rm = 0, i = 0, len = strlen(str); 
    char* res = (char*)calloc(len+1, sizeof(char));
    if(res == NULL)
        return false; 
    
    while(str !=NULL && i < len)
    {
        
        rm  = (str[i] -'0' )%10; 
        if(map[rm][1] == INT_MIN)
            return false; 
        
        res[len-i-1] =  map[rm][1]+'0';
        
        i++; 
    }
    
    res[len] = '\0';
    
    return (strcmp(str, res) == 0? true:false);
}
   



bool isStrobogrammatic(char * num){
    
    if(num == NULL)
        return false; 
    
    return isValid(num); 

}
