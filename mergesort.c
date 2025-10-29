/**
 * This file implements parallel mergesort.
 */

#include <stdio.h>
#include <string.h> /* for memcpy */
#include <stdlib.h> /* for malloc */
#include "mergesort.h"

/* Global Vars*/

 //array going to sort
 extern int *A;
 //extra storage
 extern int *B; 
 //when stop creating threads
 extern int cutoff;


/* this function will be called by mergesort() and also by parallel_mergesort(). */
void merge(int leftstart, int leftend, int rightstart, int rightend){
	//Get sizes
	int leftsize = leftend - leftstart + 1;
	int rightsize = rightend - rightstart + 1;
	
	//Copy array A into B
    memcpy(&B[leftstart],&A[leftstart],(leftsize+rightsize) * sizeof(int));
	
	// Sorting
	int i = leftstart; //left index
	int j = rightstart;// right index
	int k = leftstart;// merge pointer
	while (i <= leftend && j <= rightend){
		//left is smaller or equal
		if (B[i] <= B[j]){
			A[k] = B[i];
			i++;
		}
		//right is smaller
		else{
			A[k] = B[j];
            j++;
		}
		k++;
	}

	//make sure all arrays are empty after loop is done
	while(i<=leftend){
		A[k]=B[i];
		i++;
		k++;
	}
	while(j<=rightend){
		A[k]=B[j];
		j++;
		k++;
	}
}

/* this function will be called by parallel_mergesort() as its base case. */
void my_mergesort(int left, int right){
	//Base case for recursion(checking for 0 or 1 elements)
	if(left >= right){
		return;
	}
	//Find middle
	int mid = left + (right - left )/2;

	//Recursively sort
	my_mergesort(left,mid);
	my_mergesort(mid+1,right);
	//Merge
	//printf("Merging sequentially for indices %d to %d and %d to %d\n", left, mid, mid + 1,  right);
	merge(left,mid,mid+1,right);
}

/* this function will be called by the testing program. */
void * parallel_mergesort(void *arg){
		struct argument *args = (struct argument *) arg;
		if (args->level >= cutoff) {
			my_mergesort(args->left, args->right);
		} else {
			int left = args->left;
			int right = args->right;
			int mid = left + (right - left) / 2;
			//printf("Creating threads at level %d for indices %d to %d and %d to %d\n", args->level + 1, left, mid, mid + 1,  right);
			struct argument *argA = buildArgs(left, mid, args->level + 1);
			struct argument *argB = buildArgs(mid + 1, right, args->level + 1);
			pthread_t threadID_A, threadID_B;
			pthread_create(&threadID_A, NULL, parallel_mergesort, (void *) argA);
			pthread_create(&threadID_B, NULL, parallel_mergesort, (void *) argB);
			pthread_join(threadID_A, NULL);
			pthread_join(threadID_B, NULL);
			//printf("Merging at level %d for indices %d to %d and %d to %d\n", args->level, left, mid, mid + 1,  right);
			merge(left, mid, mid + 1, right);
        
        	// Free the allocated memory
			free(argA);
			free(argB);
		}
		return NULL;
}



/* we build the argument for the parallel_mergesort function. */
struct argument * buildArgs(int left, int right, int level){
	struct argument *arg = (struct argument *) malloc(sizeof(struct argument));
	arg->left = left;
	arg->right = right;
	arg->level = level;
	return arg;
}
