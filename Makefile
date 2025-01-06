NAME = get_next_line.a

SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c

BONUS = $(BONUS:.c=.o)
CC = CC
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)
$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean: rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re