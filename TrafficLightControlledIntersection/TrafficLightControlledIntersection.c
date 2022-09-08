#include <semaphore.h>
class TrafficLight {
public:
         sem_t m; 
         int green; 
    TrafficLight() {
      green = 1; 
      sem_init(&m, 0,1 );
    }

    void carArrived(
        int carId,                   // ID of the car
        int roadId,                  // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        int direction,               // Direction of the car
        function<void()> turnGreen,  // Use turnGreen() to turn light to green on current road
        function<void()> crossCar    // Use crossCar() to make car cross the intersection
    ) {
        
        
        sem_wait(&m);
        if(green!=roadId){
            turnGreen();
        }
        green=roadId;
        crossCar();
        sem_post(&m);
    }
        
    
};
