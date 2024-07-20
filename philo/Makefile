NAME = philo

SRCS = philosophers.c arg_check.c Utils/ft_atoi.c init_env.c Utils/get_time.c init_philos.c \

CC = cc

CFLAGS = -Wall -Wextra -Werror  -fsanitize=address,undefined -g3

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lpthread -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re