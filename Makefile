# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhong <rhong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 14:13:50 by rhong             #+#    #+#              #
#    Updated: 2022/10/02 16:53:06 by rhong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = pipex
CFLAGS = -Wall -Wextra -Werror

SRCS = ./src/child.c ./src/find_cmd_path.c ./src/input_err.c ./src/main.c ./src/pipex.c ./src/rm_quotes.c ./src/set_cmd.c ./src/set_p_data.c
SRCS_B = ./srcb/child_bonus.c ./srcb/find_cmd_path_bonus.c ./srcb/h_set_p_data_bonus.c ./srcb/here_doc_bonus.c ./srcb/input_err_bonus.c ./srcb/main_bonus.c ./srcb/pipex_bonus.c ./srcb/rm_quotes_bonus.c ./srcb/set_cmd_bonus.c ./srcb/set_p_data_bonus.c

HEADER = ./src/pipex.h
HEADER_B = ./srcb/pipex_bonus.h

OBJS_B = $(SRCS_B:.c=.o)
OBJS = $(SRCS:.c=.o)

LIB = ./libft/libft.a ./get_next_line/libgnl.a
LFLAG = -lft -lgnl -L./libft -L./get_next_line

ifdef WITH_BONUS
	TOTAL_OBJS = $(OBJS_B)
else
	TOTAL_OBJS = $(OBJS)
endif

all : $(NAME) $(HEADER)

$(NAME): $(TOTAL_OBJS) $(LIB)
	$(CC) $(LFLAG) $(LIB) $(TOTAL_OBJS) -o $(NAME)

./obj/%.o : %.c
	$(CC) $(CFLAGS) -c $<

$(LIB):
	make bonus -j -C ./libft; make bonus -j -C ./get_next_line

clean :
	rm -rf $(OBJS) $(OBJS_B); make clean -C ./libft; make clean -C ./get_next_line

fclean : clean
	rm -rf $(NAME) $(OBJS_B); make fclean -C ./libft; make fclean -C ./get_next_line

re :
	make fclean
	make all

bonus :
	make WITH_BONUS=1

.PHONY: all clean fclean re bonus
