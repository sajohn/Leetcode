bool isLeap(int year){
    
    if(year == 0)
        return false; 
    
   if(year%400==0||year%4==0&&year%100!=0)
       return true; 
    return false; 
}

int dayOfYear(char * date){
    
    int calendar[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(date == NULL)
        return -1; 
    
    int len = strlen(date);
    
    char* token = NULL; 
    
    char delim[2] = "-";
    int params[3] = {0}, idx =0, count = 0; 
    
    token = strtok(date, delim);
    
    while(token != NULL){
        
        params[idx++] = atoi(token);
        
        token = strtok(NULL, delim);
        
    }

        count+= params[2];
    
    if(isLeap(params[0]))
        calendar[1]++; 
        
     for(int i = 0; i < params[1]-1;i++){
         
        count+=calendar[i];
       
        }
    
    
    return count; 
}


