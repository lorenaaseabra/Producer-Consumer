# Producer-Consumer Code
This is a C code that implements a producer-consumer problem using pthreads and semaphores. The producer-consumer problem involves two processes, a producer and a consumer, who share a common buffer. The producer produces data items and inserts them into the buffer, while the consumer consumes the data items from the buffer.

## Requirements
To compile and run this code, you need to have the following libraries installed:

* pthread.h
* semapore.h
* stdio.h
* stdlib.h

## Code Explanation
The code initializes and uses the following variables:

* empty: Semaphore to track the number of empty slots in the buffer.
* full: Semaphore to track the number of filled slots in the buffer.
* mutex: Mutex to ensure mutual exclusion while accessing the buffer.
* in: Index to insert elements into the buffer.
* out: Index to remove elements from the buffer.
* buffer: Array to store the data items.
* N: Number of iterations for the producer to produce items.
* B: Size of the buffer.
* C: Number of consumer threads.
* P: Number of producer threads.
* pro: Array of producer threads.
* con: Array of consumer threads.
* size: Maximum size between P and C, used for the index array.
* index: Array to store the thread IDs.
The main function initializes the semaphores, mutex, and memory for the buffer, producer threads, consumer threads, and index array. Then it creates and joins the producer and consumer threads.

The producer and consumer functions are executed by each producer and consumer thread, respectively. The producer function generates an input value based on the iteration number and adds it to the buffer. It waits for an empty slot in the buffer, acquires the mutex lock, adds the item to the buffer, updates the in index, releases the mutex lock, and signals a full slot in the buffer. The consumer function retrieves an output value from the buffer. It waits for a filled slot in the buffer, acquires the mutex lock, retrieves the item from the buffer, updates the out index, releases the mutex lock, and signals an empty slot in the buffer.

## Usage
1. Compile the code using a C compiler:

```
gcc -o producer_consumer producer_consumer.c -lpthread
``` 

2.Run the compiled executable:

```
./producer_consumer
```

3. Enter the required input values when prompted:

```
Number of producers
Number of consumers
Size of the buffer
Number of iterations (N)
```
The program will then start running with the specified number of producer and consumer threads, producing and consuming items from the shared buffer.

Please note that the code provided assumes correct usage and does not include error handling or input validation.
