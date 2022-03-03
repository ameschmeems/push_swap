NAME		:=	push_swap

BONUS_NAME	:=	checker

SRCS		:=	srcs/main.c \
				srcs/init.c \
				srcs/push.c \
				srcs/pop.c \
				srcs/peek.c \
				srcs/swap.c \
				srcs/push_ab.c \
				srcs/rotate.c \
				srcs/reverse_rotate.c \
				srcs/error.c \
				srcs/push_swap_upto3.c \
				srcs/push_swap_upto5.c \
				srcs/push_swap_large.c \
				srcs/simplify_stack.c

BONUS_SRCS	:=	gnl/get_next_line.c \
				gnl/get_next_line_utils.c \
				srcs/init.c \
				srcs/push.c \
				srcs/pop.c \
				srcs/peek.c \
				srcs/swap.c \
				srcs/push_ab.c \
				srcs/rotate.c \
				srcs/reverse_rotate.c \
				srcs/error.c \
				srcs/checker.c \
				srcs/checker_input.c

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
		rm -f ${OBJS} ${BONUS_OBJS}

fclean:		clean
		@make -C ./ft_printf fclean
		rm -f ${NAME} ${BONUS_NAME}

re:			fclean all

bonus:		${BONUS_NAME}

${BONUS_NAME}:
		@make -C ./ft_printf
		${CC} ${BONUS_SRCS} ${CFLAGS} -Lft_printf -lftprintf -o ${BONUS_NAME}

.PHONY:		all clean fclean re bonus