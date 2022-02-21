NAME		:=	push_swap

SRCS		:=	srcs/main.c

OBJS		:=	srcs/main.o

CC			:=	gcc

CFLAGS		:=	-Wall -Wextra -Werror

INCLUDES	:=	./includes

all:		${NAME}

${NAME}:	${SRCS}
		@make -C ./ft_printf
		${CC} ${CFLAGS} ${SRCS} -Lft_printf -lftprintf -o ${NAME}

clean:
		@make -C ./ft_printf clean
		rm -f ${OBJS}

fclean:		clean
		@make -C ./ft_printf fclean
		rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re