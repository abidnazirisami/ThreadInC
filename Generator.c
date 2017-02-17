#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "threadHeader.h"

void generateInput()
{
	FILE *in;						//The File type pointer for opening a file
	
	int i = 0;  
	
	in = fopen("Input.txt", "w+");
	for(i=0;i<1000;i++)
	{
		int ranDom = rand()%1000; // Intializes random number generator 
		fprintf(in, "%3d\n", ranDom);		
	}
	fclose(in);
}
