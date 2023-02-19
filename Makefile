NAME = philosophers

SRCS = main.c

OBJS = $(SRCS:.c=.o)

GCC = cc

CFLAGS = -g3 -Wall -Werror -Wextra -fsanitize=address

EXEC = philo

all : $(NAME)

$(NAME): $(OBJS) 
		$(GCC) $(CFLAGS) $(OBJS) -o $(EXEC)