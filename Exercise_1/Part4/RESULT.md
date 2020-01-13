Part 4: result
--------------------

### GO: 
// Use `go run foo.go` to run your program

package main

import (
	. "fmt"
	"runtime"
	"time"
)

var i = 0

func incrementing() {
	for j := 0; j < 1000000; j++ {
		i++
	}
}

func decrementing() {
	for j := 0; j < 1000000; j++ {
		i--
	}
}

func main() {
	runtime.GOMAXPROCS(runtime.NumCPU()) // Begrenser antall CPU-er som kan kjøres på samtidig

	//This works as the sleep-functions are forcing the program to wait for the termination of the threads

	go incrementing()

	time.Sleep(10 * time.Millisecond)

	go decrementing()

	time.Sleep(10 * time.Millisecond)

	Println("The magic number is:", i)
}

### C: 
#include <pthread.h>
#include <stdio.h>

int i = 0;

// Note the return type: void*
void* incrementingThreadFunction(){
    for (int j = 0; j < 999999; j++) {
        i++; 
    }
    // TODO: increment i 1_000_000 times
    return NULL;
}

void* decrementingThreadFunction(){
    for (int j = 0; j < 999999; j++) {
        i--; 
    }
    // TODO: decrement i 1_000_000 times
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

### Python: 
# Python 3.3.3 and 2.7.6
# python fo.py

from threading import Thread

i = 0

def incrementingFunction():
    global i
    for j in range(1000000):
        i = i + 1

def decrementingFunction():
    global i
    for j in range(1000000):
        i = i - 1

def main():
    global i
    "This works basically for the same reasons as the two others"

    incrementing = Thread(target = incrementingFunction, args = (),)
    decrementing = Thread(target = decrementingFunction, args = (),)
    
    incrementing.start()
    incrementing.join()

    decrementing.start()
    decrementing.join(100)    
    
    print("The magic number is %d" % (i))


main()


