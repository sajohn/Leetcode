

int minInsertions(char * s){
    
    if(s == NULL)
        return 0; 
    
    
    int len = strlen(s);
    if(len ==0 )
        return 0;
    
    
    char stack[len]; 
    int k = -1, result = 0; 
    
    for(int i=0; i < len; i++){
        
        if(s[i] == '('){
            stack[++k] = '(';
        } 
        else{
            if(k>=0){
                if(i+1<len){
                    
                    if(s[i+1] == ')'){
                        i++; 
                        //No need of insertion 
                    }
                    else{
                        result++; 
                    }
                    k--;
                }
                else{ //i+1>len
                    
                    result++; 
                    k--; 
                    break; 
                }
            }
            else{ //k<=0. no ( in stack
                
                if(i+1<len){
                    
                    if(s[i+1] == ')'){
                        i++; 
                       result++; 
                    }
                    else{
                        result+=2; //Two insertion
                    }
                }
                 else{ //i+1>len
                    
                    result+=2; 
                    break;
                    
                }
            }
        }
        
    }
    
    while(k>=0){
        result+=2; 
        k--;
    }
    return result;
    
}
