
///Please make a diagram for this approach to see how increment and decrement is happening for each row..

char * convert(char * s, int numRows){
    
    
    if(s == NULL || numRows == 0)
        return NULL; 
    
    int len = strlen(s);
    if(len == 0)
        return "";
  if(numRows == 1)
      return s; 
    
    char* res = (char*)calloc(len+1, sizeof(char));
    if(res == NULL)
        return NULL; 
   int k= 0;  
   for(int r= 0; r < numRows; r++){
       int increment = 2*(numRows -1);
       for(int j = r; j < len ; j+=increment ){
           res[k++] = s[j];
          
           if(r > 0 && r < numRows -1){
               if(j+(increment -2*r) < len)
                     res[k++] = s[j+(increment -2*r)];
           }

       }
       
   }

    return res; 
}
