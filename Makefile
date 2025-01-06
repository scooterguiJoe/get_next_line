NAME = get_next_line.a

SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c

BONUS_OBJ = $(BONUS:.c=.o)
CC = CC
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)
$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus : $(BONUS) $(BONUS_OBJ)
			ar rcs $(NAME) $(BONUS_OBJ)

clean:
		rm -f $(OBJS) $(BONUS_OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus