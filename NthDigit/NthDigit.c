typedef struct Counter{
    int min;
    int max; 
    int count; 
    int width; 
    
}Counter;

#define MAX 9
int findNthDigit(int n){
    /*
        //max a number gets is 10^9 (actually 2*10^9)
       
        1-9 -----> 1    ----->9------->        n/10  -----> Digits 1*9
        10-99 -----> 2   ----->90------->        n/100 -----> Digits 2*90
        100-999 -----> 3   ----->900------->      n/1000 -----> Digits 3*900
        1000-9999 ----->4    ----->9000------->   n/10000 -----> Digits 4*9000
        10000-99999 ----->5    ----->90000------->   n/100000 -----> Digits 5*90000
       
    */ 
    
 int min = 1, max =9, mult = 10, count =0;
 Counter c[MAX] = {0};
    for(int i = 0; i < MAX; i++)
    {
        c[i].min = (int)(pow(10, i)); 
        c[i].max = (int)(pow(10, i)*9 + (i>0? c[i-1].max:0) ); 
        c[i].count = (int)pow(10, i)*9; 
        c[i].width = i+1; 
    }
    
   //nth digit of a sequence....
  
    
    for(int i =0;  i< MAX; i++)
    {
        
        if(n-count <= (long)c[i].count * c[i].width){
           
            //What is the number then
            
            int offset = (n-count)/c[i].width;
            int remainder = (n-count)%c[i].width;
            
            if(remainder)
                offset++; 
            
            int number = c[i].min + (offset -1 >=0 ? (offset-1): 0); 
          
            if(remainder)
            {
                int loop = c[i].width -remainder; 
                
                while(loop>0 ){
                    number/=10; 
                    loop--; 
                }
                return number%10; //Return the only left (leftmost) digit 
            }
            else        
              return number % 10; //Return the only left (leftmost) digit 
            
        }else{

             count+= c[i].count* c[i].width; 
        }
        
        
    }
    
    return -1; 
}


