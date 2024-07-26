NAME = philo

SRCS = philosophers.c arg_check.c init_all.c thread_helpers.c process.c fork_utils.c \
		Utils/ft_atoi.c Utils/get_time.c Utils/my_usleep.c Utils/print.c Utils/value_check.c \
		Utils/free_philos.c 

CC = @cc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address,undefined -g3

OBJS = $(SRCS:.c=.o)

# Define color codes
GREEN = \033[0;32m
CYAN = \033[0;36m
RESET = \033[0m

# Define silent command prefix
SILENT = @

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lpthread -o $(NAME)
	@echo "$(GREEN)$(NAME) successfully compiled!$(RESET)"

clean:
	@rm -f $(OBJS)
	@echo "$(CYAN)Object files removed!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(CYAN)$(NAME) removed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re