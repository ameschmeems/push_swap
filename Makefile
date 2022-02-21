NAME		:=	push_swap

SRCS		:=	srcs/main.c

OBJS		:=	srcs/main.o

CC			:=	gcc

CFLAGS		:=	-Wall -Wextra -Werror

INCLUDES	:=	./includes

all:		${NAME}

${NAME}:	${SRCS}
		@make -C ./libft bonus
		@{CC} @{CFLAGS} -Llibft -lft -o ${NAME}

clean:
		@make -C ./libft clean
		rm -f ${OBJS}

fclean:		clean
		@make -C ./libft fclean
		rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
