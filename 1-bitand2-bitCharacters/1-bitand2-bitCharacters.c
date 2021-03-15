bool CheckValid(int* bits, int bitsSize)
{
    
    if(bits == NULL || bitsSize == 0 )
        return false; 
    
    if(bitsSize == 2){
        if((bits[bitsSize-1] == 0 || bits[bitsSize-1] == 1) && bits[bitsSize-2] == 1 || ( bits[bitsSize-1] == 0 &&  bits[bitsSize-2] == 0))
            return true; 
        else
            return false;
    }
    
    else if(bitsSize == 1)
    {
      if(bits[bitsSize -1] == 0)
        return true;
      else 
        return false; 
    }
    else
    {
      bool valid1 =false, valid2 =false; 
        
        if((bits[bitsSize-1] == 0  || bits[bitsSize-1] == 1 ) && (bits[bitsSize-2] == 1 ))
          valid1 = CheckValid(bits, bitsSize -2);
        
        if(bits[bitsSize-1] == 0 )
          valid2 = CheckValid(bits, bitsSize -1);
        
       return (valid1 || valid2);
    }
    
    return false;
}

bool isOneBitCharacter(int* bits, int bitsSize){
   
    if(bits == NULL)
        return false;
        
    if(bits[bitsSize-1] == 0)
    {
      if(bitsSize ==1 && bits[bitsSize-1] == 0)
         return true; 
     if(bitsSize ==1 && bits[bitsSize-1] == 1)
         return false; 
        
        return CheckValid(bits, bitsSize -1);
    }
        
 return false; 
}
