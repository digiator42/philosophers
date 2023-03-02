NAME = philosophers

SRCS =	philo_acts.c \
		parsing.c \
		forks.c \
		threads.c \
		get_time.c \
		main.c \
		philo_utils.c \
		routine.c
		
OBJS = $(SRCS:.c=.o)

GCC = cc

CFLAGS = -g3 -Wall -Werror -Wextra

EXEC = philo

all : $(NAME)

$(NAME): $(OBJS) 
		$(GCC) $(CFLAGS) $(OBJS) -o $(EXEC) -lpthread

re : clean all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(EXEC)

re: clean all