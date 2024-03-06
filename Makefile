NAME	= philo
CC		= gcc
INC		= philosophers.h
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

SRCS	= main.c \
		srcs/init.c \
		srcs/utils.c \
		srcs/life.c \
		srcs/check.c \

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
