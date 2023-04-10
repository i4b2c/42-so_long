/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:20:57 by icaldas           #+#    #+#             */
/*   Updated: 2023/04/10 15:21:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/src/libft.h"
# include "../minilibx/mlx.h"

# define BRICK "./textures/black_brick.xpm"
# define GRASS "./textures/wood.xpm"
# define PLAYER "./textures/mario1.xpm"
# define PLAYER_R "./textures/mario2.xpm"
# define DOOR "./textures/door.xpm"
# define COGUMELO "./textures/coin1.xpm"
# define DOOR_OPEN "./textures/door_open.xpm"
# define BOY "./textures/goomba1.xpm"
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
	int		x1;
	int		x2;
	t_map	map;
}				t_data;

//ERRO//
int square_map(char **str);

//ERRO1//
int check_dobro(int p, int e, int c);
int verificar_dobro(char *str);
int check_extra_word(char *str);
int check_extra_key(char *str);
int verificar_len_linha(char *str);

//ERRO2//
int check_side_ff(char **str, int x, int y);
void flood_fill(char **str, int x, int y);
void free_path(char **str);
int check_path(char *str);
void check_p_e_c(char *str, int *p, int *e, int *c);

//ERRO3//
int extra(char *str);
int contar_linha(char *str);
char **replicar_map(char *av);
int check_path_valid(char **str);
void get_player(char **str,int *x, int *y);

//ERRO_MAIN//
int erro(char *str);

void free_path(char **str);
char **replicar_map(char *av);
int contar_linha(char *str);
void	free_fd(int fd, char *s, char *str);
int		erro_vazio(char *str);
void	mudar_letra(t_data *data, int y, int x, int op);
void	get_imagens(t_data *data);
int		funcao_x(int fd);
int		funcao_y(int fd);
int		act_a(t_data *data);
int		act_w(t_data *data);
int		act_d(t_data *data);
int		act_s(t_data *data);
int		check_end(t_data *data, int x);
void	colocar_movimento(int i, t_data *data);
void	colocar_texto_e_acabar(int x, t_data *data);
int		check_key(t_data *data, int x);
int		prox_numero(int keycode, t_data *data);
int		key_handler(int keycode, t_data *data);
int		mouse_hook(t_data *data);
char	ler_o_xpm(int fd);
void	get_map(t_data *data, int fd);
int		options_map(t_data *data, int k, int i);
void	colocar_fantasma_direcao(t_data *data, int x, int i);
//void	sprite_porta(t_data *data, int x, int y);
void	put_imagem(t_data *data, int op, int len_x, int len_y);
void	ver_objetos(t_data *data);
void	render_map(t_data *data);
char	*ft_strcpy(char *s1, char *s2);
int		verificar_ber(char *str);
int		verificar_x(char *str);
int		verificar_y(char *str);
int		ver_erro(int x, int y, t_data data);
void	atribuir_col_e_lin(t_data *data, int x, int y);
void	free_total(t_data *data);
int		get_x_y(int *x, int *y, char **av);
void	iniciar(t_data *data);
void	iniciar_jogo(t_data *data, char **av);
void	encerrar_jogo(t_data *data);
void	encerrar_jogo_erro(t_data *data);
void	colocar_imagem_door(t_data *data, int x);
int		verificar_linha(char *str);

#endif
