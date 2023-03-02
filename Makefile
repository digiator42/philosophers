NAME = philosophers

SRCS =	philo_acts.c 	\
		parsing.c 		\
		forks.c 		\
		threads.c 		\
		get_time.c 		\
		main.c 			\
		philo_utils.c 	\
		routine.c
		
OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -g3 -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lpthread

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all