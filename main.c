#include "philo.h"

void *routine()
{
	printf("");
	return NULL;
}

int main(int ac, char **av)
{
	pthread_t t1;
	t_philo philo;
	
	if(!args_error(ac, av, &philo))
		return (1);
	pthread_create(&t1, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	return 0;
}