bool isSign(char* s) {
    if(s== NULL)
        return false; 
    if(s[0] == '+' || s[0] == '-' )
        return true; 
    
    return false;
}

bool isExponent(char* s) {
  if(s== NULL)
        return false; 
  if(s[0]== 'e' || s[0] == 'E')
    return true; 
 return false; 
}

bool isNumber(char * s){
    
    if( s == NULL  )
        return false; 

    bool first_decimal_seen = false, number_seen = false, first_sign_seen = false, second_sign_seen = false, exp_seen = false, exp_digit_seen = false; 
    
    int len = strlen(s), idx  = 0;
    
    if(len == 0)
        return false; 
    
    if(isalpha(s[0]))
        return false; 
    
    if(isSign(&s[0]) ){
       first_sign_seen = true;
        idx++;
    }
    
    if(first_sign_seen == false && isdigit(s[0])){
        first_sign_seen = true; 
        number_seen = true; 
        idx++;
    }
    
    while(idx< len){
        
       if(isSign(&s[idx])){
           
           if((second_sign_seen) || 
              (first_sign_seen && exp_seen == false) || number_seen == false)
                return false; 
           if(exp_seen){
               if(exp_digit_seen)
                   return false; 
                second_sign_seen = true; 
           }
           else if(exp_seen == false)
           {
                second_sign_seen = false;
                return false; 
           }
        }
        
       else if(isExponent(&s[idx])){
              if(number_seen == false || exp_seen )
                  return false; 
              exp_seen = true; 
          }
        
        else if(s[idx]== '.'){
            if(first_decimal_seen || (exp_seen && first_decimal_seen == false) )
                return false; 
            first_decimal_seen = true; 
        }
        else if(isdigit(s[idx])){
            
            number_seen = true; 
            if(exp_seen){
                exp_digit_seen = true; 
            }
        }
        else if(isalpha(s[idx])){
            
            if(!isExponent(&s[idx]))
                return false; 
            else 
            {
                if(number_seen && !exp_seen)
                {
                    exp_seen = true;
                }
            }
        }
         idx++;
        
    }
     if(exp_seen && exp_digit_seen == false )
        return false; 
    
return (number_seen); 
}
