NAME    := push_swap
CC      := cc
CFLAGS  := -Wall -Wextra -Werror
RM      := rm -f

SRCS    := calc_price.c main.c move.c move_b.c moves_a.c moves_b.c moves_both.c put_to.c utils.c utils_two.c utils_three.c
OBJS    := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c main.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
