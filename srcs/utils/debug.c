#include "../../includes/game.h"
/**
 * Print the current state of the game for debugging purposes.
 */
void debug_game_state(t_game *game)
{
    size_t i;
    
    printf("=== Game Debug State ===\n");
    /* Game identity */
    printf("Name           : %s\n", game->name);
    
    /* Map info */
    printf("Map path       : %s\n", game->map.path);
    printf("Map dimensions : %zux%zu (width x height)\n",
           game->map.width, game->map.height);
    
    /* MLX context */
    if (game->mlx)
    {
        printf("MLX pointers    : context=%p, win=%p, img=%p\n",
               game->mlx->mlx, game->mlx->win, game->mlx->img);
        printf("Window size     : %dx%d\n",
               game->mlx->width, game->mlx->height);
    }
    else
        printf("MLX not initialized\n");

    /* Game counters */
    printf("Moves made      : %zu\n", game->data.move_count);
    printf("Exits reached   : %zu\n", game->data.exit_count);
    printf("Collectibles total / gathered : %zu / %zu\n",
           game->data.total_collectible,
           game->player.gathered_collectible);

    /* Player position */
    printf("Player position : (%d, %d)\n",
           game->player.pos.x, game->player.pos.y);

    /* Map matrix */
    printf("Map matrix:\n");
    i = 0;
    while (i < game->map.height && game->map.matrix && game->map.matrix[i])
    {
        printf("  %s\n", game->map.matrix[i]);
        i++;
    }

    /* Environment textures dimensions */
    printf("Textures dims (wxh): wall=%dx%d, floor=%dx%d, collectible=%dx%d, exit=%dx%d\n",
           game->textures.wall.width, game->textures.wall.height,
           game->textures.floor.width, game->textures.floor.height,
           game->textures.collectible.width, game->textures.collectible.height,
           game->textures.exit.width, game->textures.exit.height);

    /* Player sprite textures */
    printf("Player sprite dims (wxh): ");
    i = 0;
    while (i < NUMBER_OF_DIR)
    {
        printf("[%zu]=%dx%d ", i,
               game->player.textures[i].width,
               game->player.textures[i].height);
        i++;
    }
    printf("\n");

    printf("==========================\n");
}
