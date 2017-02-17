#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "threadHeader.h"


void HandleThread(int num)
{
	
	int *ptr[10];
	
	int i;
	struct param *parameters[10];
	for(i=0;i<10;i++)
	{
		ptr[i] = malloc(1000*sizeof(int*));
		parameters[i] = malloc(sizeof(struct param*));
		parameters[i]->key = num;
	
	}
	int range=0;
	for(i=0;i<10;i++)
	{
		parameters[i]->start = range;
		//printf("Range: %d\n", range);
		printf("Enter the range for Thread no. %d: From %d To ",i+1, range+1);
		int tempR;
		do
		{
			scanf("%d", &tempR);
			if(tempR>1000)
			printf("The range can't exceed 1000. Please insert again.\n");
			else if(tempR<=range)
			printf("Please insert a valid range\n");
			else continue;
			printf("Enter the range for Thread no. %d: From %d To ",i+1, range+1);
		} while(tempR <= range || tempR>1000);
		range=tempR;
		printf("\n");
		parameters[i]->end = range-1;
		//printf("Range: %d\n", range);
		void* temp = (void*) parameters[i];
		int state = pthread_create(&(id[i]), NULL, &search, temp); 
		if(state) printf("There was a problem while creating the thread\n");
	}
	
	for(i=0; i<10; i++)
	{
		pthread_join(id[i], (void**)&(ptr[i]));
		int j;
		for(j=0;ptr[i][j]!=-1;j++) {
			printf("Thread no. %d has found %d in line no. %d\n", i+1, num, parameters[i]->start+ptr[i][j]+1);
		}
	}
	
}
