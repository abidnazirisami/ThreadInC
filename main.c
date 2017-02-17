#include <stdio.h>
#include <stdlib.h>
#include "threadHeader.h"

int main(void)
{
	int num, choice;
	
	printf("Do you want to check the regular or the bonus part?\n\t- For the regular part, enter 1\n\t- For the bonus part, enter 2\n");
	scanf("%d", &choice);
	
	if(choice==1) {
		generateInput(); 												// Random number generator, also writes them to a file
		
	}																	// Divides the workload among the threads
	
	else
	{																	// Bonus Part
		char *filename = malloc(1000*sizeof(char));						
		printf("Enter the filename: ");
		scanf("%s", filename);											// Taking the filename as input
		FILE *givenFile = fopen(filename, "r");
		FILE *newlyMadeFile = fopen("Input.txt", "w");					
		int i, tempnumb;
		for(i=0;i<1000;i++)
		{
			fscanf(givenFile, "%d", &tempnumb);
			fprintf(newlyMadeFile, "%3d\n", tempnumb);					// Taking the inputs from the given file and dumping them on another file in a formatted form
		}																// This format is necessary to use fseek as the size of each number stays 3 bytes + 1 byte for the newline
																		// constantly
		fclose(givenFile);
		fclose(newlyMadeFile);
	}
	
	printf("Enter the number you want to search: ");
	scanf("%d", &num);
	HandleThread(num, choice);
	
	return 0;
}
