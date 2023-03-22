NAME = so_long
SRC = mandatory/check_end_key.c \
      mandatory/encerrar.c \
      mandatory/erro.c \
      mandatory/extra.c \
      mandatory/free.c \
      mandatory/get_x_y.c \
      mandatory/get.c \
      mandatory/hook.c \
      mandatory/iniciar.c \
      mandatory/key.c \
      mandatory/render.c \
	  mandatory/erro_line.c \
	  mandatory/main.c

SRC_BONUS = bonus/check_end_key.c \
      		bonus/encerrar.c \
     		bonus/erro.c \
      		bonus/extra.c \
      		bonus/free.c \
      		bonus/get_x_y.c \
      		bonus/get.c \
      		bonus/hook.c \
      		bonus/iniciar.c \
      		bonus/key.c \
      		bonus/render.c \
      		bonus/sprite.c \
			bonus/erro_line.c \
			bonus/main.c

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
EXTRA = so_long
LIBSRC = minilibx/libmlx_Linux.a \
	minilibx/libmlx.a
LIBFLAG = -lXext -lX11 -lm
LIBFT = libft/libft.a
GIT = git clone git@github.com:42Paris/minilibx-linux.git minilibx
RM_GIT = rm -rf minilibx
OBJ = $(SRC:%.c=%.o)
OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft/
		@$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(LIBSRC) $(LIBFLAG) -o $(NAME)

bonus: $(OBJ_BONUS)
		make -C libft/
		@$(CC) $(CFLAGS) $(SRC_BONUS) $(LIBFT) $(LIBSRC) $(LIBFLAG) -o $(NAME)

clean:
		@$(RM) $(OBJ)
		@$(RM) $(OBJ_BONUS)
		@$(RM)
minilibx:
	@$(GIT)
	make -C minilibx

fclean: clean
		@$(RM) $(NAME)
		@make fclean -C libft/
extra: fclean
	@$(RM) $(EXTRA)
	#$(RM_GIT)
re: extra all

ez:
		@$(CC) $(CFLAGS) $(SRC_MAIN) libft.a $(LIBSRC) $(LIBFLAG) -o so_long
git:
	git add *
	git commit -m .
	git push
