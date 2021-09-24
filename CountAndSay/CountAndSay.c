
void Read(char* arr, char* output, char* buff)
{
    
   if(arr == NULL)
       return ; 
    
    int len = strlen(arr);
    
    int count = 0; 
    char tmp = arr[0];
 
    for(int i = 0; i < len;i++ ){
         
       if( tmp == arr[i]) {
           count++;
       }else{
           
          sprintf(buff, "%d%c", count, tmp);
          strcat(output, buff);
           tmp = arr[i];
           count = 1; 
           memset(buff, 0, 6000);
       }
    }
      sprintf(buff, "%d%d", count, tmp-'0');
      strcat(output, buff);
      memset(buff, 0, 6000);
    
}


char* countAndSay(int n){
    
    if(n ==1)
        return "1"; 


    char* input = (char*)calloc(6000, sizeof(char));
    char* output = (char*)calloc(6000, sizeof(char));
    char* buff = (char*)calloc(6000, sizeof(char));

    if(input == NULL || output == NULL || buff == NULL)
        return NULL; 
    
    sprintf(input, "%d", 1);
    
    for(int i = 1; i < n; i++) {
        
        Read(input, output, buff);
        strcpy(input, output);
        memset(output, 0, strlen(output)*sizeof(char));
    }
    free(output);
    free(buff);
    return input; 
}
