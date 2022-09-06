typedef struct {
    // User defined data may be declared here.
// bool firstDone ;
// bool secondDone ;
// bool thirdDone ; 
sem_t first;     
sem_t second; 
sem_t third;
    
} Foo;

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    
   //obj->firstDone = obj->secondDone = obj->thirdDone = false; 
   sem_init(&obj->first, 0, 0);
   sem_init(&obj->second, 0, 0);
   sem_init(&obj->third, 0, 0);
    return obj;
}

void first(Foo* obj) {
    
    
    if(obj == NULL)
        return; 

    //sem_wait(&obj->first);
    // printFirst() outputs "first". Do not change or remove this line.
    //if(obj->firstDone == false)
    {
        printFirst();
      //  obj->firstDone = true; 
        sem_post(&obj->second);
    }
        
}

void second(Foo* obj) {
     if(obj == NULL)
        return; 
    //while(obj->firstDone == false);
    // sem_post(&obj->first);
     sem_wait(&obj->second);
    
    //if(obj->firstDone == true)
    {
    // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        //obj->secondDone = true; 
        sem_post(&obj->third);
    }
}

void third(Foo* obj) {
     if(obj == NULL)
        return; 
    // printThird() outputs "third". Do not change or remove this line.
    //while(obj->secondDone == false);
  
    //sem_post(&obj->second);
   
    sem_wait(&obj->third);
   //if( obj->secondDone == true)
   {
        printThird();
        //obj->thirdDone = true;
       sem_post(&obj->first);
   }
}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
    
    
    if(obj){
     sem_destroy(&obj->first);  
     sem_destroy(&obj->second);
     sem_destroy(&obj->third);
        free(obj);
    
    }
    obj = NULL; 
}
