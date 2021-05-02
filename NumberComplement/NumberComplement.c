int findMsb(int num)
{
   num |= num>>1; 
   num |= num>>2; 
   num |= num>>4; 
   num |= num>>8; 
   num |= num>>16; 
    
    num +=1; 
    
    return num>>1;
}

int findComplement(int num){

    int mask = 0, msb =0;
    
    if(num == 0)
        return 0; 

    msb = log2(num);
    
    mask = (1U<<msb+1) -1;

 return (num^mask);
}
