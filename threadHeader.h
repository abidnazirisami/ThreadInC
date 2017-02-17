#include <pthread.h>

struct param															// Structure for the parameter
{
	int start;
	int end;
	int key;
	int choice;
};

int cnt[10][1000];														// Returning values

int found;																// Decides if any instances were found or not

pthread_t id[10];														// Thread ids

void generateInput();													// Function prototypes
void HandleThread(int num, int choice);
void* search(struct param *parameters);
