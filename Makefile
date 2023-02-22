NAME = philosophers

SRCS = main.c 			\
		parsing.c 		\
		philo_utils.c	\
		philos_init.c	\
		philo_threads.c \
		get_time.c
		
OBJS = $(SRCS:.c=.o)

GCC = cc

CFLAGS = -g3 -fsanitize=address

EXEC = philo

all : $(NAME)

$(NAME): $(OBJS) 
		$(GCC) $(CFLAGS) $(OBJS) -o $(EXEC)

re : clean all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(EXEC)

re: clean all