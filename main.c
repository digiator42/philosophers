#include "philo.h"

void *routine()
{
	printf("\n");
	return NULL;
}

int main(int ac, char **av)
{
	pthread_t t1;
	t_philo philo;
	
	if(!args_error(ac, av, &philo))
		return (0);
	pthread_create(&t1, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	return 0;
}