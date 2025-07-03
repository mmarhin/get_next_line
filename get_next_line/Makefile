# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamarin- <mamarin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/01 17:45:18 by mamarin-          #+#    #+#              #
#    Updated: 2024/06/28 11:06:27 by mamarin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
NAME_BONUS = get_next_line_bonus.a

SRCS = get_next_line.c get_next_line_utils.c
SRCS_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	ar rcs $(NAME_BONUS) $(OBJS_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re