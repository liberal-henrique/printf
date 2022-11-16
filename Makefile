CFLAGS = -Wall -Wextra -Werror

SRCS	= ft_printf.c \
		  ft_printf_utils.c \
		  main.c

PROG	= printfTest
PROG_OBJ = main.o
OBJS	= $(SRCS:.c=.o)
NAME	= libftprintf.a
NAME_PATH = ./
LIB		= ar rc
RL		= ranlib
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(LIB) $(NAME) $(OBJS)
	$(RL) $(NAME)

$(PROG): $(NAME)
		$(CC) $(CFLAGS) $(PROG_OBJ) -L $(NAME_PATH) -l:$(NAME) -o $(PROG)

all: $(NAME) $(PROG)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) printfTest

re: fclean all

norm :
	norminette -R CheckForbiddenSourceHeader $(SRCS)
	norminette -R CheckDefine $(INS)

.PHONY: all re clean fclean
