#include <pthread.h> // for pthread_create, pthread_join, pthread_exit
#include <stdio.h>   // for printf 
#include <stdlib.h>  // for exit
#include <semaphore.h>
#include <unistd.h> 

#define NITER 1000000

int cnt = 0;
sem_t mutex; 

void* Count(void* a)
{
    int i, tmp, x = 0; 
  
    sem_getvalue(&mutex, &x);
    printf("Semaphore value %d\n", x); 

   sem_wait(&mutex);

   printf("Thread %d acquired semaphore\n", pthread_self());
 
    for(i = 0; i < NITER; i++)   
    {
        tmp = cnt;      /* copy the global cnt locally */
        tmp = tmp+1;    /* increment the local copy */
        cnt = tmp;      /* store the local value into the global cnt */ 
    }
   
   sem_post(&mutex);
   
   printf("Thread %d released semaphore\n", pthread_self());
}

int main()
{
   pthread_t tid1, tid2; 
   pthread_attr_t attr1, attr2; 

   pthread_attr_init(&attr1);
   pthread_attr_init(&attr2); 

//Initialized Semaphore with 1 count (Much like mutex)
  sem_init(&mutex,0, 1); 



   printf("Creating threads\n");
  
    if(pthread_create(&tid1,&attr1, Count, NULL))
    {
        printf("\n ERROR creating thread 1");
        exit(1);
    }

    //Sleep else non of the thread would be able to give favorable result
    sleep(2); 

    if(pthread_create(&tid2,&attr2, Count, NULL)) 
    {
        printf("\n ERROR creating thread 2");
        exit(1);
    }

    if(pthread_join(tid1,NULL))
    {
        printf("\n ERROR joining thread 1");
        exit(1);
    }
   if(pthread_join(tid2, NULL))
   {
        printf("\n ERROR joining thread 1");
        exit(1);
    }


   if(cnt < 2*NITER)
    printf("Threads not synchronized\n");
   else
     printf("Threads are synchronized\n");

   sem_destroy(&mutex);
  
   pthread_mutexattr_destroy(&attr1);
  
   pthread_mutexattr_destroy(&attr2);
   pthread_exit(NULL); ///This is used for 

}
