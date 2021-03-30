/******************************************************************************

   This function is basic function creating pthread
   Thread is created and main thread joins after pthread call finishes
*******************************************************************************/
#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 

void* calls(void* ptr) 
{
   // To exit the current thread 
   // pthread_self() return the particular thread id 
    int count =0; 
    while(count < 10)
    {
        printf("Thead handle running %d \n", count); 
        count++;
        
    }
       printf("Cancelling thread\n");
       pthread_cancel(pthread_self()); 
    return NULL; 
} 

int main() 
{ 
	// NULL when no attribute 
	pthread_t thread; 

	// Calls is a function name 
	pthread_create(&thread, NULL, calls, NULL); 

	// Waiting for when thread is completed 
	pthread_join(thread, NULL); 

	return 0; 
}
