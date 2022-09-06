typedef struct {
    int n;
    sem_t fizz;
    sem_t buzz;
    sem_t fizzbuzz;
    sem_t num;
} FizzBuzz;

FizzBuzz* fizzBuzzCreate(int n) {
    FizzBuzz* obj = (FizzBuzz*) malloc(sizeof(FizzBuzz));
    obj->n = n;
    sem_init(&obj->num, 0, 1);
    sem_init(&obj->fizz, 0, 0);
    sem_init(&obj->buzz, 0, 0);
    sem_init(&obj->fizzbuzz, 0, 0);
    
    return obj;
}

// printFizz() outputs "fizz".
void fizz(FizzBuzz* obj) {
    
     for(int i =1; i <=obj->n; i++){
      
         if(i%3 == 0 && i%5 !=0){
             sem_wait(&obj->fizz);
             printFizz();
             sem_post(&obj->num);
         }
         
     }
}

// printBuzz() outputs "buzz".
void buzz(FizzBuzz* obj) {
    
         for(int i =1; i <=obj->n; i++){

         if(i%3 != 0  && i%5 ==0){
            sem_wait(&obj->buzz);
             printBuzz();
             sem_post(&obj->num);
         }
         
     }
}

// printFizzBuzz() outputs "fizzbuzz".
void fizzbuzz(FizzBuzz* obj) {
    
    for(int i =1; i <=obj->n; i++){
      
         if(i%3 == 0  && i%5 ==0){
            sem_wait(&obj->fizzbuzz);
            printFizzBuzz();
            sem_post(&obj->num);
         }
         
     }
}

// You may call global function `void printNumber(int x)`
// to output "x", where x is an integer.
void number(FizzBuzz* obj) {
    
    for(int i =1; i <=obj->n; i++)
    {
      
         sem_wait(&obj->num);
        if(i% 3 !=0 && i%5 !=0)
        {
            printNumber(i);
            sem_post(&obj->num);
        }
        else if(i% 3 ==0 && i%5 !=0){
            sem_post(&obj->fizz);
        }
        else if(i% 3 !=0 && i%5 ==0){
            sem_post(&obj->buzz);
        }
        else if(i% 3 ==0 && i%5 ==0){
            sem_post(&obj->fizzbuzz);
        }
        
        
    }
    
}

void fizzBuzzFree(FizzBuzz* obj) {
    
    if(obj)
    {
        sem_destroy(&obj->num);
        sem_destroy(&obj->fizz);
        sem_destroy(&obj->buzz);
        sem_destroy(&obj->fizzbuzz); 
        free(obj);
    }
    
}
