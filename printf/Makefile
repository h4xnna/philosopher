NAME = libftprintf.a
CC = gcc 
CFLAGS = -Wall -Werror -Wextra 

SRCS = ./ft_printf.c \
        ./ft_printf_string.c \
        ./ft_printf_char.c \
        ./ft_printf_nbr.c \
        ./ft_printf_pointer.c \
        ./ft_printf_hexa_min.c \
        ./ft_printf_hexa_max.c \
        ./ft_printf_unsigned.c \

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	ar -cr ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY : re fclean allxi

.SILENT: