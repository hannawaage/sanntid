# Reasons for concurrency and parallelism


To complete this exercise you will have to use git. Create one or several commits that adds answers to the following questions and push it to your groups repository to complete the task.

When answering the questions, remember to use all the resources at your disposal. Asking the internet isn't a form of "cheating", it's a way of learning.

 ### What is concurrency? What is parallelism? What's the difference?
 > *Concurrency describes a scenario where tasks can run in overlapping time periods, while parallellism describes the scenario where it is possible to run tasks simultanioulsy on multiple cores*
 
 ### Why have machines become increasingly multicore in the past decade?
 > *Because we are pushing the limits with regards to what one core can do, making it hard to improve a computer by only improving the existing core(s). Adding core(s) and succesfully coordinate leads to much better improvement.*
 
 ### What kinds of problems motivates the need for concurrent execution?
 (Or phrased differently: What problems do concurrency help in solving?)
 > *Specifically problems where the program needs to interact with multiple independent external agents.*
 
 ### Does creating concurrent programs make the programmer's life easier? Harder? Maybe both?
 (Come back to this after you have worked on part 4 of this exercise)
 > **
 
 ### What are the differences between processes, threads, green threads, and coroutines?
 > *A thread is in most cases a component of a process. Multiple threads can exist within one process, and they can execute concurrently. Threads share memory, while processes do not. Green threads are not OS-managed, thus enabling them to work in environments that do not have native thread support. Coroutines are similar to threads, but are cooperatively multitasked, whereas threads are preemptively multitasked, meaning that coroutines support concurrency but not parallellism.  *
 
 ### Which one of these do `pthread_create()` (C/POSIX), `threading.Thread()` (Python), `go` (Go) create?
 > *They create a thread *
 
 ### How does pythons Global Interpreter Lock (GIL) influence the way a python Thread behaves?
 > *The lock prevents execution of multiple threads at once in the Python Interpeter. This means that a multithreaded Python application is actually single threaded.*
 
 ### With this in mind: What is the workaround for the GIL (Hint: it's another module)?
 > *Your answer here*
 
 ### What does `func GOMAXPROCS(n int) int` change? 
 > *Your answer here*
