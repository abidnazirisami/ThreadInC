#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "threadHeader.h"


void HandleThread(int num, int choice)
{
	int bonusAnswer;
	int *ptr[10];																	// Pointer array
	int i;
	struct param *parameters[10];													// The parameters are taken in a structure
	for(i=0;i<10;i++)
	{
		ptr[i] = malloc(1000*sizeof(int*));											// Memory allocation for each pointer
		parameters[i] = malloc(sizeof(struct param*));
		parameters[i]->key = num;													// They key to search with is assigned
		parameters[i]->choice = choice;
	}
	int range=0;
	for(i=0;i<10;i++)
	{
		parameters[i]->start = range;												// The beginning of the search range
		printf("Enter the range for Thread no. %d: From %d To ",i+1, range+1);
		int tempR;
		do
		{
			scanf("%d", &tempR);
			if(tempR>1000)
			printf("The range can't exceed 1000. Please insert again.\n");			
			else if(tempR<=range)
			printf("Please insert a valid range\n");								// If the range ends before the beginning of the range, that's an invalid input
			else continue;
			printf("Enter the range for Thread no. %d: From %d To ",i+1, range+1);
		} while(tempR <= range || tempR>1000);
		range=tempR;
		printf("\n");
		parameters[i]->end = range-1;												// The end of the the search range
		
	}
	for(i=0;i<10;i++)																// The ten threads ar being created with the parameters pushed in structures
	{
		void* temp = (void*) parameters[i];											// The structure type variable is type cast into void pointers
		
		int state = pthread_create(&(id[i]), NULL, &search, temp); 					// Creating the thread, a successful creation would return 0
		if(state) printf("There was a problem while creating the thread\n");
	}
	
	if(found) {
		if(parameters[0]->choice == 1)
			printf("The number %d was found on line no.", num);
		for(i=0; i<10; i++)
		{
			pthread_join(id[i], (void**)&(ptr[i]));									// The main thread waits for the threads to finish
			int j;
			if(parameters[0]->choice == 1) {
				for(j=0;ptr[i][j]!=-1;j++) 
				{														
					printf(" %d,", parameters[i]->start+ptr[i][j]+1);				// The search operation has returned the location
				}
			}
			else
			{
				if(ptr[i][0]!=-1) bonusAnswer = parameters[i]->start+ptr[i][0]+1;	// Saving the only position for the bonus part 
			}
		}
		if(parameters[0]->choice == 1)
			printf("\b.\n");
		else
			printf("The number %d was found on line no. %d.\n", num, bonusAnswer);	// For the bonus part
	}
	else printf("The number %d wasn't found\n", num);
}
