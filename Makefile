
BOLD            = "\033[1m"
RESET           = "\033[0m"
GREEN           = "\033[0;32m"
CYAN            = "\033[0;36m"
LIGHT_RED       = "\033[91m"
LIGHT_GREEN     = "\033[92m"
LIGHT_CYAN      = "\033[96m"
BROWN           = "\033[38;5;94m"

NEON_GREEN      = "\033[38;5;46m"
ELECTRIC_BLUE   = "\033[38;5;51m"
HOT_PINK        = "\033[38;5;198m"
BLOOD_RED       = "\033[38;5;196m"
SUNBURST_YELLOW = "\033[38;5;226m"
DEEP_ORANGE     = "\033[38;5;208m"
PURPLE_RAVE     = "\033[38;5;129m"
CYAN_SHOCK      = "\033[38;5;51m"



NAME	= philo
CC		= cc 
CFLAGS	= -Wall -Werror -Wextra -g3 -pthread 

SRCS	=	parsing/check_args.c\
			parsing/print_error.c\
			parsing/utils.c\
			src/init.c\
			src/simulation.c\
			src/main.c\
			src/routine_utils.c\
			src/routine_utils2.c



NCL	= -I. -Iprintf
PRINTF	= printf/libftprintf.a

OBJS = ${SRCS:.c=.o}

all: ${NAME}

%.o: %.c 
	@$(CC) $(CFLAGS) -I. -c $< -o $@ $(INCL)

${NAME}: ${OBJS} $(PRINTF)

	@echo $(LIGHT_GREEN) "Compilation..."$(BOLD)
	@${CC} ${CFLAGS} ${OBJS} $(PRINTF) -o ${NAME}
	@echo $(LIGHT_GREEN)"Compilation réussie ✔"$(RESET)

$(PRINTF):
	@make -sC  printf -j

clean:
	@rm -f ${OBJS}
	@make -sC printf clean -j
	@echo $(BROWN)clean reussi

fclean: clean
	@rm -f ${NAME}
	@make -sC printf fclean -j
	@echo $(BROWN)fclean reussi

re: fclean all

.PHONY : re fclean clean all