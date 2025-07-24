#ifndef STRUCTURES_H
# define STRUCTURES_H

// ========================================== Constants ==========================================

# define GAME_NAME 				"so_long"

# define SIZE   64

// =========================== Assets files Extensions ===========================

# define MAP_FILE_EXTENSION 	".ber"
# define ASSET_FILE_EXTENSION 	".xpm"

// =========================== String Constants ===========================

# define SPACE_SET				" \t\n\v\f\r"
# define SLASH 					'/'

// =========================== GNL Constants ===========================

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE			1024
# endif

// =========================== Map Element Constants ===========================

# define COLL					'C'
# define EXIT					'E'
# define WALL					'1'
# define FLOOR					'0'
# define PLAYER					'P'
# define VISITED				'V'

# define NPOS					-1

# define MAP_SET                "10CEP"

// =========================== Asset Paths =========================

// Environment
# define WALL_PATH			"assets/enviroment/wall.xpm"
# define EXIT_PATH			"assets/enviroment/exit.xpm"
# define FLOOR_PATH			"assets/enviroment/floor.xpm"
# define COLLECTIBLE_PATH	"assets/enviroment/collectible.xpm"

// Player directions
# define PLAYER_U_PATH		"assets/player/up.xpm"
# define PLAYER_D_PATH		"assets/player/down.xpm"
# define PLAYER_L_PATH		"assets/player/left.xpm"
# define PLAYER_R_PATH		"assets/player/right.xpm"

// =========================== Directions ===========================

# define UP             0
# define DOWN           1
# define LEFT           2
# define RIGHT          3

# define NUMBER_OF_DIR  4

// =========================== Key Constants ===========================

# define KEY_ESC   65307
# define KEY_W     119
# define KEY_A     97
# define KEY_S     115
# define KEY_D     100

// =========================== Structures ===========================

typedef struct s_axis
{
	int	x;
	int	y;
}	t_axis;

typedef struct s_texture
{
    void *img;
    int   width;
    int   height;
    char *addr;
    int   bpp;
    int   line_len;
    int   endian;
}   t_texture;

typedef struct	s_env_textures
{
    t_texture wall;
    t_texture floor;
    t_texture collectible;
    t_texture exit;
}   			t_env_textures;

typedef struct s_player
{
    int         dir;
	t_axis		pos;
    t_texture	textures[NUMBER_OF_DIR];
	size_t		gathered_collectible;
}	t_player;

typedef	struct	s_map
{
	size_t	height;
	size_t	width;
	char	*path;
	char	**matrix;
}				t_map;

typedef struct	s_data
{
	size_t	move_count;
	size_t	exit_count;
	size_t	total_collectible;
}				t_data;

typedef struct s_mlx
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int      bpp;
    int      line_len;
    int      endian;
	int      width;
    int      height;
}   t_mlx;

typedef struct s_game
{
	char			*name;
	t_map			map;
	t_data			data;
	t_mlx			*mlx;
	t_env_textures	textures;
	t_player		player;
}	t_game;

#endif
