#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void *routine()
{
	printf("hi from routine\n");
	return NULL;
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	pthread_t t1;

	pthread_create(&t1, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	return 0;
}