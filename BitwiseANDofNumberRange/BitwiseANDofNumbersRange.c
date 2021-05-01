///When two numbers by MSB remain equal keep compairing else break; and return 

int rangeBitwiseAnd(int left, int right){
    
    if(left == 0 || right == 0)
        return 0; 
    if( (left == right) || (abs(right -left) == 1))
        return right & left; 
    
   uint32_t msb =  log2(right), ret =0;
    
    for(uint32_t i= msb; i>=0 & i < 32; i--) {
        
       if( (right & 1U<<i) == (left & 1U<<i)){
           if((right & 1U<<i))
              ret |= (1U<<i);
       }
        else{
            break;
        }
    }
        
return ret; 
}



