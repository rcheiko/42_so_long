# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/20 15:58:56 by rcheiko           #+#    #+#              #
#    Updated: 2021/10/01 14:30:02 by rcheiko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

SRCS		=	so_long.c get_next_line.c get_next_line_utils.c \
				parse_map.c init.c ft_keyhook.c ft_movement.c \
				ft_utils.c ft_utils2.c ft_error_map.c ft_char_map.c \
				aff_map.c check_end.c

OBJS		=	${SRCS:.c=.o}

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -I./includes

LINKFLAGS	=	-lmlx -framework OpenGL -framework AppKit

PATHMLX		=	./minilibx/libmlx.a

RM			=	rm -f

${NAME} :		${OBJS}
				${CC} -o ${NAME} $^ ${LINKFLAGS} ${PATHMLX}

all: 			${NAME}

clean:
				${RM} ${OBJS} 

fclean:			clean
				${RM} ${NAME}

re:				fclean all
