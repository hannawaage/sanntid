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
	runtime.GOMAXPROCS(runtime.NumCPU())

	//This works as the sleep-functions are forcing the program to wait for the termination of the threads

	go incrementing()

	time.Sleep(10 * time.Millisecond)

	go decrementing()

	time.Sleep(10 * time.Millisecond)

	Println("The magic number is:", i)
}
