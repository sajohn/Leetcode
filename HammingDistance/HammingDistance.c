

int hammingDistance(int x, int y){
    
  uint32_t xor = x^y, count = 0; 
    
    while(xor)
    {
        count++; 
        xor &= (xor-1);
    }
  
return count; 
}
