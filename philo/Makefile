NAME = philo

SRCS = philosophers.c arg_check.c init_all.c thread_helpers.c process.c fork_utils.c \
		Utils/ft_atoi.c Utils/get_time.c Utils/my_usleep.c Utils/print.c Utils/value_check.c

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