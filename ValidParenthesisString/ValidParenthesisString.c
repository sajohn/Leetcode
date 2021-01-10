

bool checkValidString(char * s){
    if(s == NULL)
        return true;
    
    
    int len = strlen(s);
   int  countopenstar =0,   countclosestar= 0;

    
    if(len == 0  || (len == 1 &&  s[0] == '*'))
        return true;
       
       
    for(int i = 0; i < len; i ++)
     {
         if( s[i] == '(' || s[i] == '*') 
            countopenstar++;
         else  
            countopenstar--;
        //This is becase you don't have enough * or ( to balance more of )
        // if((countopen +   countstar <  countclose)
       if(countopenstar <0)
           return false;
     }
    
        
    for(int i = len-1; i >=0; i--)
     {
         if( s[i] == ')' || s[i] == '*') 
            countclosestar++;
         else  
            countclosestar--;
        //This is becase you don't have enough * or ( to balance more of )
        // if((countopen +   countstar <  countclose)
       if(countclosestar <0)
           return false;
     }
             
          
    return true;
}
