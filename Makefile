NAME    := push_swap
CC      := cc
CFLAGS  := -Wall -Wextra -Werror
RM      := rm -f

SRCS    := main.c calc_price.c put_to.c move_a.c move_b.c moves_a.c moves_b.c moves_both.c utils.c utils_two.c utils_three.c helper.c split.c
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
