#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/src/libft.h"
# include "minilibx/mlx.h"

# define BRICK "./textures/black_brick.xpm"
# define GRASS "./textures/wood.xpm"
# define PLAYER "./textures/fantasma.xpm"
# define PLAYER_R "./textures/fantasma_r.xpm"
# define DOOR "./textures/door.xpm"
# define COGUMELO "./textures/porcao.xpm"
# define DOOR_OPEN "./textures/door_open.xpm"
# define WHITE 16777215
# define ESC 65307
# define A 97
# define D 100
# define S 115
# define W 119

typedef struct s_map
{
	char	**map;
	int		lin;
	int		col;
	int		collect;
	int		exit;
	int		player_x;
	int		player_y;
	int		player_counter;
	int		x;
	int		y;
	int		exit_suc;
	int		exit_x;
	int		exit_y;
	int		mov;
	int		keycode;
	void	*cogumelo;
	void	*brick;
	void	*player;
	void	*door;
	void	*door_open;
	void	*player_r;
	void	*grass;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	t_map	map;
}				t_data;

char	ler_o_xpm(int fd);
void	render_map(t_data *data);
void	encerrar_jogo(t_data *data);
void	encerrar_jogo_erro(t_data *data);

#endif