CC = cc
NAME = pipex
CFLAGS = -Wall -Wextra -Werror

SRCS_B = ./src/child_bonus.c ./src/here_doc_bonus.c ./src/input_err_check_bonus.c ./src/m_pipe_bonus ./src/multi_pipe_bonus.c ./src/pipex_bonus.c

HEADER = ./src/pipex_bonus.h

OBJS_B = $(SRCS_B:.c=.o)

TOTAL_OBJS = $(OBJS_B)

LIB = ./libft/libft.a ./get_next_line/libgnl.a
LFLAG = -lft -lgnl -L

all : $(NAME) $(HEADER)

$(NAME): $(TOTAL_OBJS) $(LIB)
	$(CC) $(LFLAG) $(LIB) $(TOTAL_OBJS) $(HEADER) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $<

$(LIB):
	make -C ./libft; make -C ./get_next_line

clean :
	rm -rf $(OBJS_B); make clean -C ./libft; make clean -C ./get_next_line

fclean : clean
	rm -rf $(NAME); make fclean -C ./libft; make fclean -C ./get_next_line

re : fclean all

.PHONY: all clean fclean re
