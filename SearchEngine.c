#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "threadHeader.h"

void* search(struct param *parameters)									// Parameters are passed in this function
{
	int i=0, ind=0,c=0;
	pthread_t pid = pthread_self();										// Getting the id of the current thread
	for(i=0;i<10;i++)
	{
		if(pthread_equal(pid, id[i])) ind=i;							// Determining the serial of the current thread
	}
	FILE *write = fopen("Input.txt", "r");								// Opening the file to read from it
	
	int error = fseek(write, parameters->start*4, SEEK_SET);			// Starts reading the file from the beginning of the specified range
	if(error) printf("There was a problem while opening the file\n");
	int range=parameters->end - parameters->start;						// Calculating the search range
	for(i=0;i<=range;i++)
	{
		int num;
		fscanf(write, "%d", &num);										// Detecting if the key of the search is found or not
		if(num==parameters->key) {
			cnt[ind][c++]=i;
			found=1;													// Signifying at least one instance has been found
		}
		if(parameters->choice==2 && found==1)
		{
			printf("Thread no. %d stopped just after searching until line no. %d\n", ind+1, i+1);	// For the Bonus part, the thread closes when a match has been found
			break;
		}
	}
	fclose(write);														// Closing the file
	
	cnt[ind][c]=-1;														// Pointing out the end of the occurances
	
	pthread_exit(&cnt[ind]);											// Returning the array of the search result
	
	return NULL;
}
