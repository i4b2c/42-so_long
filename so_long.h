#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/src/libft.h"
# include "minilibx/mlx.h"

# define BRICK "./textures/brick.xpm"
# define GRASS "./textures/grass.xpm"
# define PLAYER "./textures/boy.xpm"
# define DOOR "./textures/door.xpm"
# define COGUMELO "./textures/cogumelo.xpm"
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
	void	*cogumelo;
	void	*brick;
	void	*player;
	void	*door;
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
