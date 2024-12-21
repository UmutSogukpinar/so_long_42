NAME = so_long

SRCS =

OBJ = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -o ${NAME}

