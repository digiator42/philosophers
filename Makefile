NAME = philo

SRCS =	parsing.c 		\
		philo_init.c 	\
		main.c 			\
		philo_utils.c 	\
		get_time.c		\
		philo_acts.c	\
		threads.c		\
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