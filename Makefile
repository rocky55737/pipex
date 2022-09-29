# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhong <rhong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 14:13:50 by rhong             #+#    #+#              #
#    Updated: 2022/09/27 19:03:43 by rhong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = pipex
CFLAGS = -Wall -Wextra -Werror

SRCS = ./src/main.c ./src/input_err.c ./src/set_p_data.c ./src/child.c ./src/set_cmd.c ./src/find_cmd_path.c ./src/rm_quotes.c
SRCS_B = ./srcb/child_bonus.c ./srcb/here_doc_bonus.c ./srcb/input_err_check_bonus.c ./srcb/m_pipe_bonus.c ./srcb/multi_pipe_bonus.c ./srcb/pipex_bonus.c

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
	rm -rf $(TOTAL_OBJS); make clean -C ./libft; make clean -C ./get_next_line

fclean : clean
	rm -rf $(NAME); make fclean -C ./libft; make fclean -C ./get_next_line

re :
	make fclean
	make all

bonus :
	make WITH_BONUS=1

debug :
	$(CC) -g3 ./src/*.c $(LFLAG) $(LIB)

.PHONY: all clean fclean re bonus
