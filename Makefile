NAME = so_long
SRC =	mandatory/check_end_key.c \
		mandatory/check_sprite.c \
		mandatory/encerrar.c \
		mandatory/erro_main.c \
		mandatory/erro.c \
		mandatory/erro1.c \
		mandatory/erro2.c \
		mandatory/erro3.c \
		mandatory/erro4.c \
		mandatory/erro5.c \
		mandatory/extra.c \
		mandatory/free.c \
		mandatory/get_x_y.c \
		mandatory/get.c \
		mandatory/hook_change.c \
		mandatory/hook.c \
		mandatory/iniciar.c \
		mandatory/key.c \
		mandatory/loop.c \
		mandatory/put_image.c \
		mandatory/render.c \
		mandatory/sprite.c \
		mandatory/main.c

SRC_BONUS =	bonus/check_end_key.c \
			bonus/check_sprite.c \
			bonus/encerrar.c \
			bonus/erro_main.c \
			bonus/erro.c \
			bonus/erro1.c \
			bonus/erro2.c \
			bonus/erro3.c \
			bonus/erro4.c \
			bonus/erro5.c \
			bonus/extra.c \
			bonus/free.c \
			bonus/get_x_y.c \
			bonus/get.c \
			bonus/hook_change.c \
			bonus/hook.c \
			bonus/iniciar.c \
			bonus/inimigo.c \
			bonus/key.c \
			bonus/loop.c \
			bonus/put_image.c \
			bonus/render.c \
			bonus/sprite.c \
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
		@$(RM) $(OBJ_BONUS)
		make -C libft/
		@$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(LIBSRC) $(LIBFLAG) -o $(NAME)
bonus: $(OBJ_BONUS)
		@$(RM) $(OBJ)
		make -C libft/
		@$(CC) $(CFLAGS) $(SRC_BONUS) $(LIBFT) $(LIBSRC) $(LIBFLAG) -o $(NAME)_bonus
clean:
		@$(RM) $(OBJ)
		@$(RM) $(OBJ_BONUS)
		@$(RM)
minilibx:
	@$(GIT)
	make -C minilibx
fclean: clean
		@$(RM) $(NAME)
		@$(RM) $(NAME)_bonus
		@make fclean -C libft/
extra: fclean
	@$(RM) $(EXTRA)
re: extra all

ez:
		@$(CC) $(CFLAGS) $(SRC_MAIN) libft.a $(LIBSRC) $(LIBFLAG) -o so_long
git:
	git add *
	git commit -m .
	git push
