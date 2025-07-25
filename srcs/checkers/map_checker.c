#include "../../includes/game.h"

static bool check_accessability(char **matrix);
static void flood_fill(t_game *game, char **matrix, int x, int y);

bool is_map_valid(t_game *game)
{
    char  **matrix = game->map.matrix;
    size_t width   = game->map.width;
    size_t height  = game->map.height;
    size_t i;

    if (!matrix)
        return (display_error_msg(EMPTY_MAP, false));
    i = 0;
    while (i < width)
    {
        if (matrix[0][i] != WALL || matrix[height - 1][i] != WALL)
            return (display_error_msg(INV_COVER, false));
        i++;
    }
    i = 0;
    while (i < height)
    {
        if (matrix[i][0] != WALL || matrix[i][width - 1] != WALL)
            return (display_error_msg(INV_COVER, false));
        i++;
    }
    return (true);
}

bool	check_data(t_game *game)
{
	if (game->player.pos.x == NPOS || game->player.pos.y == NPOS)
		return (display_error_msg(NO_PLAYER_ERR, false));
	if (game->data.exit_count < 1)
		return (display_error_msg(NO_EXIT_ERR, false));
	if (game->data.exit_count > 1)
		return (display_error_msg(MULTI_EXIT_ERR, false));
	if (game->data.total_collectible == 0)
		return (display_error_msg(NO_COLL_ERR, false));
	return (true);
}

bool    is_map_accessable(t_game *game)
{
    char    **copy;

    copy = copy_matrix(game, game->map.matrix);
    if (!copy)
        return (false);
    flood_fill(game, copy, game->player.pos.x, game->player.pos.y);
    return (check_accessability(copy));
}

static void flood_fill(t_game *game, char **matrix, int x, int y)
{
    if (x < 0 || y < 0 || (size_t)x >= game->map.width ||
            (size_t)y >= game->map.height)
        return;
    if (matrix[y][x] == WALL || matrix[y][x] == VISITED)
        return;
    if (matrix[y][x] == EXIT)
    {
        matrix[y][x] = VISITED;
        return ;
    }
    matrix[y][x] = VISITED;
    flood_fill(game, matrix, x + 1, y);
    flood_fill(game, matrix, x - 1, y);
    flood_fill(game, matrix, x, y + 1);
    flood_fill(game, matrix, x, y - 1);
}

static bool check_accessability(char **matrix)
{
    int i;
    int j;

    i = 0;
    while (matrix[i])
    {
        j = 0;
        while (matrix[i][j])
        {
            if (matrix[i][j] == COLL)
            {
                free_tab(matrix);
                return (display_error_msg(ACCESS_COL_ERR, false));
            }
            if (matrix[i][j] == EXIT)
            {
                free_tab(matrix);
                return (display_error_msg(ACCESS_EXIT_ERR, false));
            }
            j++;
        }
        i++;
    }
    free_tab(matrix);
    return (true);
}
