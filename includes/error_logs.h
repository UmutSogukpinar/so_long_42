#ifndef ERROR_LOGS_H
# define ERROR_LOGS_H

// =========================== General Error Labels ===========================

# define ERR			"Error"
# define ERR_BAR		"===================================="

// =========================== Specific Error Messages ========================

# define INV_ARGC		"Invalid number of arguments!"

# define INIT_ERR		"Game initialization failed!"
# define MLX_ERR		"Mlx initialization failed!"
# define FD_OPEN_ERR	"File initialization failed!"

# define EMPTY_MAP      "Empty map!"
# define INV_MAP		"Invalid map!"
# define INV_MAP_EXT	"Invalid map extension!"
# define INV_ASSET_EXT	"Invalid map extension!"
# define INV_MAP_EL		"Invalid map element found in the map!"


# define INV_COVER          "The map is not covered properly!"
# define MAP_NOT_RECT	    "The map is not rectangular!"
# define NO_PLAYER_ERR      "There is no player in the map!"
# define MULTI_PLAYER_ERR   "Multiple player found in the map!"
# define NO_EXIT_ERR        "There is no exit in the map!"
# define MULTI_EXIT_ERR     "There is multiple exit found in the map!"
# define NO_COLL_ERR        "There is no collectible item in the map!"

# define ACCESS_EXIT_ERR    "Exit are not accessable!"
# define ACCESS_COL_ERR     "All collectibles are not accessable!"

# define TEXTURE_ERR        "Failed to load texture!"

# define GETTIMEOFDAY_ERR   "gettimeofday() error"

#endif
