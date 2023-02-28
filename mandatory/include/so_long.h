#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/src/libft.h"
# include "../minilibx/mlx.h"

# define BRICK "./textures/black_brick.xpm"
# define GRASS "./textures/wood.xpm"
# define PLAYER "./textures/fantasma.xpm"
# define PLAYER_R "./textures/fantasma_r.xpm"
# define DOOR "./textures/door.xpm"
# define COGUMELO "./textures/porcao.xpm"
# define DOOR_OPEN "./textures/door_open.xpm"
# define BOY "./textures/fire.xpm"
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
	void	*inimigo;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	t_map	map;
}				t_data;

void	mudar_letra(t_data *data, int y, int x, int op);
void	get_imagens(t_data *data);
int	funcao_x(int fd);
int	funcao_y(int fd);
int	act_a(t_data *data);
int	act_w(t_data *data);
int	act_d(t_data *data);
int	act_s(t_data *data);
int	check_end(t_data *data, int x);
void	colocar_movimento(int i, t_data *data);
void	colocar_texto_e_acabar(int x, t_data *data);
int	check_key(t_data *data, int x);
int	prox_numero(int keycode, t_data *data);
int	key_handler(int keycode, t_data *data);
int	mouse_hook(t_data *data);
char	ler_o_xpm(int fd);
void	get_map(t_data *data, int fd);
int	options_map(t_data *data, int k , int i);
void	colocar_fantasma_direcao(t_data *data, int x, int i);
void	put_imagem(t_data *data, int op, int len_x, int len_y);
void	ver_objetos(t_data *data);
void	render_map(t_data *data);
char	*ft_strcpy(char *s1, char *s2);
int	verificar_ber(char *str);
int	verificar_x(t_data data);
int	verificar_y(t_data data);
int	ver_erro(int x, int y, char *str, t_data data);
void	atribuir_col_e_lin(t_data *data, int x, int y);
void	free_total(t_data *data);
int	get_x_y(int *x, int *y, char **av);
void	iniciar(t_data *data);
void	iniciar_jogo(t_data *data, char **av);
void	encerrar_jogo(t_data *data);
void	encerrar_jogo_erro(t_data *data);
void	colocar_imagem_door(t_data *data, int x);

#endif
