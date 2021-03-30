/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <math.h>
#include <sys/types.h>
#include <unistd.h>

#define bool int
#define true 1
#define false 0

/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <math.h>
#include <sys/types.h>

#define bool int
#define true 1
#define false 0

 typedef struct Timer {
        void (*fn)(void); //You can call this function in a thread untill thread  elapses the time.
        bool (*timer_delegate)(pthread_t, time_t, time_t ,  unsigned int); //This is delegate which works on a thread and exits once done. 
        unsigned int seconds; //Preempt as fast as you can for other threads (Otherwise use timer)
        unsigned int total;
 } Timer;

void* timer_run(void *t) {

    time_t start_time, end_time;
    time(&start_time);
    while(1) {
        Timer tmr = *((Timer *) t);
         time(&end_time);
        bool should_kill_thread = tmr.timer_delegate(pthread_self(), start_time, end_time, tmr.total);
        if (should_kill_thread) 
            pthread_cancel(pthread_self());
        tmr.fn();
        //Sleep this thread for others to get scheduled. 
        //This is where the resolution of time comes into picture
        sleep(tmr.seconds);
    }
}

bool should_kill_thread(pthread_t t, time_t start_time, time_t utime_new,  unsigned int interval) {
    struct tm *startinfo, *endinfo;
    startinfo = localtime(&start_time);
    endinfo = localtime(&utime_new);
    printf("Thread %p Start %s End %s \n", pthread_self(), asctime(startinfo), asctime(endinfo));

    if (utime_new - start_time >= interval) {
        return true;
    }
    return false;
}

void Callee() {
    
    printf("%s\n", "Callee's worker function!\n");
    //sleep(1);
}

int main(int argc, char const *argv[])
{
    pthread_t t1, t2;
    Timer args1;
    args1.fn = &Callee;
    args1.timer_delegate = should_kill_thread;
    args1.seconds = 1; // call every 1 second
    args1.total = 5; 
    
    Timer args2;
    args2.fn = &Callee;
    args2.timer_delegate = should_kill_thread;
    args2.seconds = 3; // call every 3 second
    args2.total = 12;

    int id= pthread_create(&t1, NULL, timer_run, &args1);
    printf("Thread creation time %d \n", time(NULL));
    if (id) 
    {
       printf("ERROR; return code from pthread_create() is %d\n", id);
      exit(EXIT_FAILURE);
    }
    sleep(1);
    int id2 = pthread_create(&t2, NULL, timer_run, &args2);
    printf("Thread creation time %d \n", time(NULL));
    if (id2) {
       printf("ERROR; return code from pthread_create() is %d\n", id2);
       exit(EXIT_FAILURE);
    }
    
    pthread_join(t1, NULL); // blocks main thread
    pthread_join(t2, NULL); // blocks main thread
    
    printf("%s\n", "DONE"); // never reached until t1 & t2 is killed
    return 0;
}

