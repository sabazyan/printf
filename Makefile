NAME = libftprintf.a
SRCS = ${wildcard *.c}
OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

all: ${NAME}
${NAME}: ${OBJS}
	ar rcs ${NAME} $^

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
