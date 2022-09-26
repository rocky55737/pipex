CC = cc
NAME = libgnl.a
CFLAGS = -Wall -Wextra -Werror

SRCS = ./get_next_line.c ./get_next_line_utils.c

SRCS_B = ./get_next_line_bonus.c ./get_next_line_utils_bonus.c

HEADER = get_next_line.h
HEADER_B = get_next_line_bonus.h

AR = ar
ARFLAGS = -rcs
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

ifdef WITH_BONUS
	TOTAL_OBJS = $(OBJS_B) $(HEADER_B)
else
	TOTAL_OBJS = $(OBJS) $(HEADER)
endif

all : $(NAME)

$(NAME): $(TOTAL_OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean :
	rm -rf $(OBJS) $(OBJS_B)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

bonus :
	make WITH_BONUS=1

.PHONY: all clean fclean re bonus