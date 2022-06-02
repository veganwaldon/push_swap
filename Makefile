# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vwaldon <vwaldon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 19:06:36 by vwaldon           #+#    #+#              #
#    Updated: 2022/03/11 19:51:27 by vwaldon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		push_swap
BONUS = 	checker
CC = 		cc
CFLAGS = 	-Wall -Werror -Wextra
SRCS = 		main.c create_list.c atoi_ps.c ft_parse.c actions.c actions2.c \
			actions3.c actions4.c solve.c sort.c scores.c scripts.c

SRCS_BONUS = checker.c create_list.c atoi_ps.c ft_parse.c actions.c actions2.c \
			actions3.c actions4.c solve.c sort.c scores.c scripts.c
LIBFT = 	libft/libft.a
HEADER = 	push_swap.h
OBJS = 		$(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
.PHONY: 	all clean fclean re libft bonus

all: 		libft $(NAME)

$(NAME): 	$(OBJS) $(HEADER)
			${CC} $(OBJS) ${LIBFT} -o $@

%.o: %.c 	$(LIBFT) $(HEADER)
			${CC} ${CFLAGS} -I$(HEADER) -c $< -o $@

clean:
			@make -C libft clean
			rm -f $(OBJS)
			rm -f $(OBJS_BONUS) 

fclean: 	clean
			rm -f $(NAME) 
			rm -f $(BONUS) 
			@make -C libft fclean

libft: 
			@make -C libft

re: 		fclean all

bonus: 		libft $(BONUS) $(NAME)
	
$(BONUS): 	$(OBJS_BONUS) $(HEADER)
			${CC} $(OBJS_BONUS) ${LIBFT} -o $@

