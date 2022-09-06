#include <semaphore.h>
typedef struct {
    int n;
    sem_t zero; 
    sem_t even; 
    sem_t odd;
    
} ZeroEvenOdd;

ZeroEvenOdd* zeroEvenOddCreate(int n) {
    ZeroEvenOdd* obj = (ZeroEvenOdd*) malloc(sizeof(ZeroEvenOdd));
    obj->n = n;

    sem_init(&obj->zero, 0, 1);
    sem_init(&obj->even, 0, 0);
    sem_init(&obj->odd, 0, 0);
    
    return obj;
}

// You may call global function `void printNumber(int x)`
// to output "x", where x is an integer.

void zero(ZeroEvenOdd* obj) {
    
    for (int i = 1;  i <= obj->n; i++) {
        sem_wait(&obj->zero);
       printNumber(0);
        
    if(i & 1 )
        sem_post(&obj->odd);
    else 
        sem_post(&obj->even);
      
    }
}

void even(ZeroEvenOdd* obj) {
    
   for (int i = 2; i <= obj->n; i+=2) {
    
     sem_wait(&obj->even);
        
      printNumber(i);
  
      sem_post(&obj->zero);
    }  
  
}

void odd(ZeroEvenOdd* obj) {
        
   for (int i = 1; i <= obj->n; i+=2) {
    
     sem_wait(&obj->odd);
     printNumber(i);

     sem_post(&obj->zero);
   }  
}

void zeroEvenOddFree(ZeroEvenOdd* obj) {
    
    if(obj){
        sem_destroy(&obj->zero);
        sem_destroy(&obj->even); 
        sem_destroy(&obj->odd); 
        free(obj);
    }
    
}
