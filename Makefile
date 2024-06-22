
SOURCES := $(shell find . -name '*.c' -maxdepth 1)
# SOURCES = \

OBJECTS = $(SOURCES:.c=.o)
HEADER = includes
FLAGS = -Wall -Wextra -Werror -g -D BUFFER_SIZE=42
NAME = get_next_line.a
RM = rm -f
CC = cc
AR = ar rc

all: ${NAME}

${NAME}: ${OBJECTS}
		${AR} ${NAME} ${OBJECTS}
		echo ${OBJECTS}

.c.o:
		${CC} ${FLAGS} -c $< -o $@

clean:
		${RM} ${OBJECTS}

fclean: clean
		${RM} ${NAME}

re: fclean all clean

.PHONY: all clean fclean re
