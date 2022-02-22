NAME		:=	push_swap

SRCS		:=	srcs/main.c \
				srcs/init.c \
				srcs/push.c \
				srcs/pop.c \
				srcs/peek.c \
				srcs/swap.c \
				srcs/push_ab.c \
				srcs/rotate.c \
				srcs/reverse_rotate.c \
				srcs/error.c

OBJS		:=	${SRCS:.c=.o}

CC			:=	gcc

CFLAGS		:=	-Wall -Wextra -Werror

INCLUDES	:=	./includes

all:		${NAME}

${NAME}:	${OBJS}
		@make -C ./ft_printf
		${CC} ${OBJS} -Lft_printf -lftprintf -o ${NAME}

clean:
		@make -C ./ft_printf clean
		rm -f ${OBJS}

fclean:		clean
		@make -C ./ft_printf fclean
		rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re