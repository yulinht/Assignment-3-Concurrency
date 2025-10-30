# Assignment-3-Concurrency

## Group 130's members:  

Elijah Daquinag  a181958 

Yuxuan Wu         a1898143

Mitchell Pratt      a1885118

## Overview  
1.This program implements parallel merge sort using pthreads. It recursively partitions arrays through a divide-and-conquer strategy, with different threads concurrently sorting subarrays.  

2.It allows users to specify the desired level of parallelism. Once reached, it switches to serial merge sort while utilizing global arrays A (original) and B (temporary) to enhance merge efficiency.  

3.Compared to sequential merge sort, this program delivers significant performance gains, often achieving over 2x speedup with multiple threads. It supports both sequential and parallel sorting, with performance improving as the thread level increases until reaching an optimal value.  

## Manifest  
1 README.md - Project Documentation and User Guide  
2 README.template - Template for README files  
3 .gitignore - Specifies which files should be ignored by Git  
4 Makefile - compiling and building projects  
5 mergesort.c - Source file implementing the parallel merge sort algorithm  
6 mergesort.h - Header file defining global variables and data structures  
7 test-mergesort.c - Test program for evaluating sorting algorithms  

## Building the project  
To build the project
1.Download the project folder
2.Run the make file
 



## Features and usage   
### Key Features  
1.Parallel Merge Sort: Implements merge sort using multithreading to enhance performance  
2.Configurable Parallelism: Users can specify branch depth thresholds to control thread creation levels  
3.Performance Timing: Measures and records sorting execution duration  
4.Input Validation: Checks array sorting correctness post-execution  
5.Memory Management: Efficiently allocates and releases memory for arrays and thread parameters  

### Usage  
To use this code
1.Then use the command ./test-mergesort x y x
    1.1 where x is number of elements
    1.2 where y is the cut off level
    1.3 an example being ./test-mergesort 100000000 0 1234
2. Read the output in terminal






## Testing  
The code was ran numerous times with 100000000 elements and different cut off points. 


## Known Bugs  





## Reflection and Self Assessment  
During development, we realized that the two memcpy operations copying the left and right subarrays could be merged into a single operation, since array segments are stored contiguously in memory. We therefore modified the code.  

Turn:  
 ```memcpy(&B[leftstart],&A[leftstart],(leftsize) * sizeof(int));
 ```memcpy(&B[rightstart],&A[rightstart],(rightsize) * sizeof(int));

 into  
```memcpy(&B[leftstart], &A[leftstart], (leftsize + rightsize) * sizeof(int));

This action simplified the code and improved efficiency. Initially, we were uncertain whether the two parts were necessarily contiguous, so we researched the principles of array memory layout in C. After confirming that arrays are stored sequentially, this modification was correctly implemented without affecting the merge logic. This process helped us gain a deeper understanding of memory management and array copying mechanisms in C.  



## Sources Used  
https://www.geeksforgeeks.org/dsa/merge-sort/



