#include <pthread.h>

struct param
{
	int start;
	int end;
	int key;
};

int cnt[10][1000];
pthread_t id[10];

void generateInput();
void HandleThread(int num);
void* search(struct param *parameters);
