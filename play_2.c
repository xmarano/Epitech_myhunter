/*
** EPITECH PROJECT, 2023
** B-MUL-100-MAR-1-1-myhunter-leo.gregori
** File description:
** play_2.c
*/
#include "include/hunter.h"

void dino_window(sfRenderWindow *window, Game_t *game, Heart_t *heart)
{
    sfVector2i crosshair = sfMouse_getPositionRenderWindow(window);
    sfVector2f aim = sfRenderWindow_mapPixelToCoords(window, crosshair, NULL);
    sfVector2f aim_pos = {(float)aim.x - 26, (float)aim.y - 26};

    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, game->background_s, NULL);
    sfRenderWindow_drawSprite(window, game->dino_bleu_s, NULL);
    if (game->nb_life == 5)
        sfRenderWindow_drawSprite(window, heart->heart_5_s, NULL);
    if (game->nb_life == 4)
        sfRenderWindow_drawSprite(window, heart->heart_4_s, NULL);
    if (game->nb_life == 3)
        sfRenderWindow_drawSprite(window, heart->heart_3_s, NULL);
    if (game->nb_life == 2)
        sfRenderWindow_drawSprite(window, heart->heart_2_s, NULL);
    if (game->nb_life == 1)
        sfRenderWindow_drawSprite(window, heart->heart_1_s, NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfRenderWindow_drawSprite(window, heart->aim_s, NULL);
    sfSprite_setPosition(heart->aim_s, aim_pos);
}

int events_hunter(sfRenderWindow *window, sfEvent event, int *p_current,
    Game_t *game)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        event_click(window, event, game);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfMusic_destroy(game->music);
            (*p_current) = 0;
            return 1;
        }
    }
    return 0;
}

void init_game(Game_t *game, Heart_t *heart, sfIntRect *rect)
{
    struct_in_game(game);
    struct_in_game_heart(heart);
    sfMusic_play(game->music);
    sfMusic_setVolume(game->music, 75);
    rect->top = 0;
    rect->left = 0;
    rect->width = 24;
    rect->height = 17;
    set_texture(game, heart, *rect);
    sfSprite_setTexture(heart->aim_s, heart->aim_t, sfTrue);
    sfSprite_setScale(heart->aim_s, heart->aim_scale);
}

void dino_life(sfRenderWindow *window, Game_t *game, Heart_t *heart)
{
    dino_window(window, game, heart);
    dino_score(window, game);
    sfRenderWindow_display(window);
    dino_position(window, game);
}

void time_handeling(Game_t *game, sfIntRect *rect, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds;

    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.03) {
        (*rect) = move_rect((*rect), 24, 144);
        sfSprite_setTextureRect(game->dino_bleu_s, (*rect));
        sfClock_restart(clock);
    }
}
