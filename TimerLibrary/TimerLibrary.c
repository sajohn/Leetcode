#include <iostream>
#include <unistd.h>		/* For Sleep */
#include <pthread.h>	/* To acquire mutex */
#include <queue>		/*To hold all the tasks which needs to be executed */

using namespace std;

void Task1(void) { cout << "Task1 " << endl; }
void Task2(void) { cout << "Task2 " << endl; }
void Task3(void) { cout << "Task3 " << endl; }
void Task4(void) { cout << "Task4 " << endl; }
void Task5(void) { cout << "Task5 " << endl; }

typedef struct {
	bool timer_enable; 					/* Tells if timer is enabled or not */
	bool periodic;						/* Tells if timer is periodic or not */
	uint32_t reload_timeout_value;		/* Reload value of timer, used in case of periodic timer to reload curr timeout value*/
	uint32_t curr_timeout_value;		/* Curr value of timer */
	void (*Callback)(void);				/* Call Back Function to be called upon timeout */
} TASK_MAPPING;

#define MAX_TASK 5
TASK_MAPPING TimerTask[MAX_TASK];
queue <uint32_t> Task_queue;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

/* TimerInterrupt is called every 1 milli Sec */
void TimerInterrupt() {
	uint32_t timer_index;
	pthread_mutex_lock(&mutex);
	for(timer_index = 0; timer_index < MAX_TASK; timer_index++) {
		if(TimerTask[timer_index].timer_enable == true) {
			if(TimerTask[timer_index].curr_timeout_value == 0) {
				/* Stop the timer, if it is not periodic */
				if(TimerTask[timer_index].periodic == false) {
					TimerTask[timer_index].timer_enable = false;
				}
				else{
					/* Reload timer value */
					TimerTask[timer_index].curr_timeout_value = TimerTask[timer_index].reload_timeout_value;
				}
				/* Put this task into queue */
				Task_queue.push(timer_index);
			}
			else{
				TimerTask[timer_index].curr_timeout_value--;
			}
		}
	}
	pthread_mutex_unlock(&mutex);
}

void timer_start(uint32_t *timerId, void (*pCallback)(void), uint32_t timeout, bool periodic) {
	pthread_mutex_lock(&mutex);
	uint32_t timer_index;
	for(timer_index = 0; timer_index < MAX_TASK; timer_index++) {
		/* Find the empty slot where timer is not enabled */
		if(TimerTask[timer_index].timer_enable == false) {
			/* Enable the timer, with received parameters */
			TimerTask[timer_index].timer_enable = true;
			TimerTask[timer_index].reload_timeout_value = timeout;
			TimerTask[timer_index].curr_timeout_value = timeout;
			TimerTask[timer_index].periodic = periodic;
			TimerTask[timer_index].Callback = pCallback;
			/* Handler Id is used by caller to stop the timer */
			*timerId = timer_index;
			break;
		}
	}
	pthread_mutex_unlock(&mutex);
}

void timer_stop(uint32_t timerId) {
	pthread_mutex_lock(&mutex);
	if(timerId < MAX_TASK) {
		TimerTask[timerId].timer_enable = false;
		TimerTask[timerId].periodic = false;
		TimerTask[timerId].reload_timeout_value = 0xFFFFFFFF;
		TimerTask[timerId].curr_timeout_value = 0xFFFFFFFF;
		TimerTask[timerId].Callback = nullptr;
	}
	pthread_mutex_unlock(&mutex);
}

void *TimerInterrupt(void *arg) {
	/*Generate Timer Interrupt every 1sec */
	static uint32_t counter = 0;
	while(1) {
		cout << counter++ << endl;
		TimerInterrupt();
		sleep(1);
	}
	return nullptr;
}

void *RunTasks(void *arg) {
	while(1) {
		pthread_mutex_lock(&mutex);
		while(!Task_queue.empty()) {
			uint32_t timer_index = Task_queue.front();
			Task_queue.pop();
			TimerTask[timer_index].Callback();
		}
		pthread_mutex_unlock(&mutex);
	}
	return nullptr;
}

void InitTimerTask() {
	uint32_t task_index;
	for(task_index = 0; task_index < MAX_TASK; task_index++) {
		timer_stop(task_index);
	}
}

int main() {
	pthread_t thread_id1;
	pthread_t thread_id2;
	InitTimerTask();
	pthread_create(&thread_id1, NULL, &TimerInterrupt, NULL);
	pthread_create(&thread_id2, NULL, &RunTasks, NULL);

	uint32_t timerId1;
	timer_start(&timerId1, Task1, 3, true);

	uint32_t timerId2;
	timer_start(&timerId2, Task2, 10, true);

	uint32_t timerId3;
	timer_start(&timerId3, Task3, 15, false);

	sleep(60);

	timer_stop(timerId1);
	timer_stop(timerId2);

	pthread_cancel(thread_id1);
	pthread_cancel(thread_id2);

	return 0;
}

