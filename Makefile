CC = nasm -f elf64
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_strdup.s ft_write.s ft_read.s
OBJS = $(SRCS:.s=.o)
NAME = libasm.a

TEST_FILE = main.c
TEST_OUT = test_output

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.s
	$(CC) -o $@ $<

tests: $(NAME)
	gcc $(TEST_FILE) -L. -lasm -o $(TEST_OUT)
	./$(TEST_OUT)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f a.out
	rm -f $(TEST_OUT)
	rm -f output.txt
	rm -f empty.txt

re: fclean all
