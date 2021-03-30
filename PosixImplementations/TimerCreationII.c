#include <signal.h>
#include <time.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#if !defined __timer_t_defined && \
((defined _TIME_H && defined __USE_POSIX199309) || defined __need_timer_t)
#define __timer_t_defined      1

#include <bits/types.h>

/* Timer ID returned by `timer_create'.  */
typedef __timer_t timer_t;

#endif

#define A_DESCRIPTIVE_NAME 13
	
int main()
{
	int err;
	struct sigevent signal_specification;
	timer_t created_timer; /* Contains the ID of the created timer */ 

	/* What signal should be generated when this timer expires ? */

	signal_specification.sigev_signo= RTL_SIGUSR1;
	signal_specification.sigev_value.sival_int = A_DESCRIPTIVE_NAME;

	err=timer_create(CLOCK_REALTIME, &signal_specification, &created_timer);

       
      struct itimerspec new_setting, old_setting;
      new_setting.it_value.tv_sec=1;
      new_setting.it_value.tv_nsec=0;
      new_setting.it_interval.tv_sec=0;
      new_setting.it_interval.tv_nsec=100*1000;


return 0;
}
