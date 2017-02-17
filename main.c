#include <stdio.h>
#include <stdlib.h>
#include "threadHeader.h"

int main(void)
{
	int num;
	generateInput();
	printf("Enter the number you want to search: ");
	scanf("%d", &num);
	HandleThread(num);
	return 0;
}
