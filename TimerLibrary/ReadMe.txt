This program adds the timer task to queue upon expiration of timer interrupt which checks if timer task has expired

    - If timer task is not periodic the timer is done with its enabled state and is put to queue for callback execution for that timer related task
    - If timer task is not periodic the timer is reloaded with value and put to queue for callback execution for that timer related task
