bool isValid(int data) {
    
      if((data & (0x80)) == 0x0)
           return true;
          
   return false; 
}

bool isValid0(int data) {
    
      if((data & (0xC0)) == 0x80)
           return true;
          
   return false; 
}
    
bool isValid1(int data) {
      if((data & 0xE0) == 0xC0 )
           return true;
    return false;
}
bool isValid2(int data)
{
     if( ((data & 0xF0) == 0xE0))
           return true;
    return false;
}
bool isValid3(int data)
{
     if( (data & (0xF8)) == 0xF0)
           return true;
  return false;
}

bool validUtf8(int* data, int dataSize) {
      if(data == NULL || dataSize == 0)
        return true; 

    
    for(int i =0; i < dataSize; ) {
            
                
       if(isValid3(data[i])) {
            
             if(i+3< dataSize){

                 for(int j =0; j< 3; j++)
                    if(!isValid0(data[i+1+j]))
                         return false;
                i+=4; 
                 continue; 
             } else {
                    return false;
                }
         }   
                 
        else  if(isValid2(data[i])) {
            
             if(i+2< dataSize){

                 for(int j =0; j< 2; j++)
                    if(!isValid0(data[i+1+j]))
                         return false;
                i+=3; 
                 continue; 
             } else {
                    return false;
                }
         }   
            
         else if(isValid1(data[i])) {
            
             if(i+1< dataSize){

                 for(int j =0; j< 1; j++)
                     if(!isValid0(data[i+1+j]))
                         return false;
                i+=2; 
                 continue; 
             } else {
                    return false;
                }
         }
    
            
        else if(isValid(data[i])){
               i++;
             continue; 
           }
           else
               return false;
            
    }
                
        
    return true;
}
