#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "threadHeader.h"

void generateInput()
{
	FILE *in;															//The File type pointer for opening a file
	
	int i = 0;  
	
	in = fopen("Input.txt", "w");										// Opens the text file with write access
	for(i=0;i<1000;i++)
	{
		int ranDom = rand()%1000; 										// Generates a random number between 0 and 1000
																
		fprintf(in, "%3d\n", ranDom);									// This will make sure no matter what the number is, it consists of exactly 3 bytes
	}																	// That helps the fseek() function later, as it searches byte by byte, uniform size of numbers helps
	fclose(in);
}
