# Assignment-3-Concurrency

## Group 130's members:  

Elijah Daquinag  a181958 

Yuxuan Wu         a1898143

Mitchell Pratt      a1885118

## Overview  
This program implements parallel merge sort using pthreads. It recursively partitions arrays through a divide-and-conquer strategy, with different threads concurrently sorting subarrays.  

It allows users to specify the desired level of parallelism. Once reached, it switches to serial merge sort while utilizing global arrays A (original) and B (temporary) to enhance merge efficiency.  

Compared to sequential merge sort, this program delivers significant performance gains, often achieving over 2x speedup with multiple threads. It supports both sequential and parallel sorting, with performance improving as the thread level increases until reaching an optimal value.  

## Manifest  






## Building the project  




## Features and usage  



## Testing  



## Known Bugs  





## Reflection and Self Assessment  




## Sources Used  




