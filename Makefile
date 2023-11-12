NAME	= philo
CC		= gcc
INC		= philosophers.h
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

SRCS	= main.c \
		srcs/init.c \
		srcs/ft_atol.c \

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c $(INC)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
