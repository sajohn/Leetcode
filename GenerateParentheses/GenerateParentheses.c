

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
//n = 3
((()))
(()())
(())()
()(())
()()()

n = 4 (Both 3 and 4 are not complete)

(((())))
((()()))
(()()())
()()()()
*/

int fact(int n)
{
    if(n == 0 || n ==1 )
        return 1; 
    return (n*fact(n-1));
}
    
void Helper(char** ret, int* returnSize, int capacity, char** curstr, int curstrlen, int open, int close)
{
  if(ret == NULL)
      return ; 
    
    if(curstrlen == 2*capacity){
        
        ret[(*returnSize)] = (char*)calloc((2*capacity) +1, sizeof(char));
            if(  ret[(*returnSize)]  == NULL)
                return; 
        
        strncpy(ret[(*returnSize)++] , (*curstr), 2*capacity);
        
     return; 
        
    }
    
    if(open < capacity){
        if((*curstr) == NULL){
        
            (*curstr) = (char*)calloc(1, sizeof(char));
            if((*curstr) == NULL)
                return ; 
            }else{
            (*curstr) = (char*)realloc((*curstr), (curstrlen+1)*sizeof(char));
              if((*curstr) == NULL)
                return ; 
        }
      
       (*curstr)[curstrlen] = '(';
       Helper(ret, returnSize, capacity, curstr, curstrlen+1, open+1, close);
         (*curstr) = (char*)realloc((*curstr), (curstrlen)*sizeof(char));
    }
        
    
   if(close < open)  {
       if(curstr == NULL){
        
           (*curstr)= (char*)calloc(1, sizeof(char));
            if(*curstr == NULL)
                return ; 
            }else{
            (*curstr) = (char*)realloc((*curstr), (curstrlen+1)*sizeof(char));
              if((*curstr) == NULL)
                return ; 
        }
      
       (*curstr)[curstrlen] = ')';
       Helper(ret, returnSize, capacity, curstr, curstrlen+1, open, close+1);
         (*curstr) = (char*)realloc((*curstr), (curstrlen)*sizeof(char));
    }  
    
    
            
}

char ** generateParenthesis(int n, int* returnSize) {

    *returnSize = 0; 
    
    if(n == 0)
        return NULL; 
    
    char** ret = (char**)calloc(fact(n), sizeof(char*));
    if(ret == NULL)
        return NULL; 
    char** curstr = (char**)calloc(1, sizeof(char*));
    if(curstr == NULL)
        return NULL; 
    
    Helper( ret, returnSize, n, curstr, 0, 0, 0);
    
    return ret; 
}
