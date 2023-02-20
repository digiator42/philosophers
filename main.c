#include "philo.h"

int main(int ac, char **av)
{
	pthread_t t1;
	t_input input;
	
	if(!args_error(ac, av, &input))
		return (1);
	return 0;
}