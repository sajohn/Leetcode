typedef struct {
    int n;
    sem_t foo;
    sem_t bar;
} FooBar;

FooBar* fooBarCreate(int n) {
    FooBar* obj = (FooBar*) malloc(sizeof(FooBar));
    obj->n = n;
    sem_init(&obj->foo, 0, 1);
    sem_init(&obj->bar, 0, 0);
   
    return obj;
}

void foo(FooBar* obj) {
    
     //sem_wait(&obj->foo);
    
    for (int i = 0; i < obj->n; i++) {
        sem_wait(&obj->foo);
        // printFoo() outputs "foo". Do not change or remove this line.
        printFoo();
      
        sem_post(&obj->bar);

      
    }
}

void bar(FooBar* obj) {
     
    for (int i = 0; i < obj->n; i++) {
        sem_wait(&obj->bar);
        // printBar() outputs "bar". Do not change or remove this line.
        printBar();
 
        sem_post(&obj->foo);

    }
}

void fooBarFree(FooBar* obj) {
    
    if(obj){
        sem_destroy(&obj->foo);
        sem_destroy(&obj->bar);
        free(obj);
    }
    
}
