NAME = libft.a
SRC = libft/src/ft_isalpha.c \
      libft/src/ft_isdigit.c \
      libft/src/ft_isalnum.c \
      libft/src/ft_isascii.c \
      libft/src/ft_isprint.c\
      libft/src/ft_strlen.c \
      libft/src/ft_memset.c \
      libft/src/ft_bzero.c \
      libft/src/ft_memcpy.c \
      libft/src/ft_memmove.c \
      libft/src/ft_strlcpy.c\
      libft/src/ft_strlcat.c \
      libft/src/ft_toupper.c \
      libft/src/ft_tolower.c \
      libft/src/ft_strchr.c \
      libft/src/ft_strrchr.c \
      libft/src/ft_strncmp.c\
      libft/src/ft_memchr.c \
      libft/src/ft_memcmp.c \
      libft/src/ft_strnstr.c \
      libft/src/ft_atoi.c \
      libft/src/ft_calloc.c \
      libft/src/ft_strdup.c\
      libft/src/ft_substr.c \
      libft/src/ft_strjoin.c \
      libft/src/ft_strtrim.c \
      libft/src/ft_split.c \
      libft/src/ft_itoa.c \
      libft/src/ft_strmapi.c\
      libft/src/ft_striteri.c \
      libft/src/ft_putchar_fd.c \
      libft/src/ft_putstr_fd.c \
      libft/src/ft_putendl_fd.c \
      libft/src/ft_putnbr_fd.c\
      libft/src/ft_lstnew.c \
      libft/src/ft_lstadd_front.c \
      libft/src/ft_lstsize.c \
      libft/src/ft_lstlast.c \
      libft/src/ft_lstadd_back.c\
      libft/src/ft_lstdelone.c \
      libft/src/ft_lstclear.c \
      libft/src/ft_lstiter.c \
      libft/src/ft_lstmap.c \
      libft/src/ft_printf_utils1.c \
      libft/src/ft_printf_utils2.c \
      libft/src/len.c \
      libft/src/ft_printf.c \
      get_next_line/get_next_line.c \
      get_next_line/get_next_line_utils.c

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
EXTRA = a.out libft/a.out so_long
LIBSRC = minilibx/libmlx_Linux.a \
	minilibx/libmlx.a
LIBFLAG = -lXext -lX11 -lm
GIT = git clone git@github.com:42Paris/minilibx-linux.git minilibx
RM_GIT = rm -rf minilibx
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
		@$(AR) $(NAME) $(OBJ)
		@$(GIT)
		make -C minilibx
		@$(CC) $(CFLAGS) so_long.c libft.a $(LIBSRC) $(LIBFLAG) -o so_long

clean:
		@$(RM) $(OBJ)

fclean: clean
		@$(RM) $(NAME)
extra: fclean
	@$(RM) $(EXTRA)
	$(RM_GIT)
re: extra all

ez: 
		@$(CC) $(CFLAGS) so_long.c libft.a $(LIBSRC) $(LIBFLAG) -o so_long
git:
	git add *
	git commit -m .
	git push
