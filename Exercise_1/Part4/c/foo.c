#include <pthread.h>
#include <stdio.h>

int i = 0;

// Note the return type: void*
void* incrementingThreadFunction(){
    for (int j = 0; j < 999999; j++) {
        i++; 
    }
    return NULL;
}

void* decrementingThreadFunction(){
    for (int j = 0; j < 999999; j++) {
        i--; 
    }
    return NULL;
}


int main(){
    //This works as pthread_join are blocking the calling thread 
    //until the thread with identifier equal to the first argument terminates, thus making the decrement
    //wait for the increment to finish.
    pthread_t incrementingThread; 
    pthread_t decrementingThread; 

    pthread_create(&incrementingThread, NULL, incrementingThreadFunction, NULL);
    pthread_join(incrementingThread, NULL);
    pthread_create(&decrementingThread, NULL, decrementingThreadFunction, NULL);
    pthread_join(decrementingThread, NULL);
    
    printf("The magic number is: %d\n", i);
    return 0;
}