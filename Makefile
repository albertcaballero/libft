NAME = libft.a
# BNAME = .bonus
LIBRARY = libft.h
CFLAGS= -Wall -Wextra -Werror -I.
CC = cc

SRC = ft_isthing.c ft_mem.c	ft_string.c	ft_case.c ft_atoi.c ft_calloc.c ft_put.c\
	ft_strmalloc.c ft_string2.c	ft_itoa.c ft_split.c
BONUSRC = ft_lstbasics.c ft_lstextra.c 
GNLSRC = gnl/get_next_line.c gnl/get_next_line_utils.c

SRC += $(GNLSRC)
SRC += $(BONUSRC)

OBJS = $(SRC:.c=.o)
# BONUSOBJS = $(BONUSRC:.c=.o)
# BONUSOBJS = $(GNLSRC:.c=.o)


%.o: %.c $(LIBRARY) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBRARY)
	$(MAKE) -C ./ft_printf
	ar -crs $(NAME) $(OBJS)

# bonus: $(BNAME)
# $(BNAME): $(BONUSOBJS) $(OBJS)
# 	$(MAKE) -C ./ft_printf
# 	ar -crs $(NAME) $(BONUSOBJS) $(OBJS) $(GNLSRC)
# 	touch $(BNAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus