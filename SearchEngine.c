#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "threadHeader.h"

void* search(struct param *parameters)
{
	int i=0, ind=0,c=0;
	pthread_t pid = pthread_self();
	for(i=0;i<10;i++)
	{
		if(pthread_equal(pid, id[i])) ind=i;
	}
	FILE *write = fopen("Input.txt", "r");
	int error = fseek(write, parameters->start*4, SEEK_SET);
	if(error) printf("There was a problem while opening the file\n");
	int range=parameters->end - parameters->start;
	//printf("Range: %d\n", range);
	for(i=0;i<=range;i++)
	{
		int num;
		fscanf(write, "%d", &num);
		//printf("%d\n", num);
		if(num==parameters->key) cnt[ind][c++]=i;
	}
	//printf("\nBhitor: %d\n", cnt[ind]);
	fclose(write);
	cnt[ind][c]=-1;
	pthread_exit(&cnt[ind]);
	
	return NULL;
}
