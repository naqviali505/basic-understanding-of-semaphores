# basic-understanding-of-semaphores
Semaphore1.cpp

There are exactly 3 threads generate string a, b and c in an arbitrary order. In an absence of any synchronization mechanism there will be no order in generation of a, b and c.  Synchronize threads using semaphore in such a way that your printed string will be aaacbaaacbaaacb……

Semaphore2.cpp

Two Threads i.e. Producer and Consumer are sharing a buffer of size 100. Producer generates random number from 1 to 6, stores that number in the buffer and print the number. Consumer has to read values from the buffer added by the producer, perform the summation operation and display the result.  Producer will stop after adding 100 values. Both producer and consumer threads run simultaneously; hence, synchronize. 
You’re not allowed to use cout/printf statements
