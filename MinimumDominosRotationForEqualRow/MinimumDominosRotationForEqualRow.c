

int minDominoRotations(int* tops, int topsSize, int* bottoms, int bottomsSize){
    
    if(tops == NULL || bottoms  == NULL || (bottomsSize = 0 || topsSize == 0))
        return 0; 
    
    int min = INT_MAX, minsofar = 0, j =0, minsofarbottom =0, minb = INT_MAX, res = 0; 
    
    for(int i = 1; i <=6; i++)
    {
        minsofar = 0; minsofarbottom =0; j = 0; 
        while(j < topsSize){
        if(tops[j] == i || bottoms[j] == i){
            if(bottoms[j] == i && tops[j]!=i){
                minsofar+=1; 
            }
            else{
               /* 
                1: tops[j] == i
                2: tops[j] == i && bottoms[j] == i 
                3: tops[j] == i && bottoms[j] != i
               */
                if(bottoms[j]!= i)
                    minsofarbottom+=1; 
            }
        } else{
                break; 
            }
            j++; 
        }
        
          if(j == topsSize ){
            res=(minsofar < minsofarbottom? minsofar:minsofarbottom);
            min = (min < res? min:res);    
          }
    }
    
 
  
  return (min == INT_MAX? -1: min); 
}
