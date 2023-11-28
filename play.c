/*
** EPITECH PROJECT, 2023
** B-MUL-100-MAR-1-1-myhunter-leo.gregori
** File description:
** play.c
*/
#include "include/hunter.h"

void event_close_play(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

void event_dino(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

static void struct_in_game(Game_t *in_game)
{
    in_game->background_t = sfTexture_createFromFile("assets/background.png", NULL);
    in_game->background_s = sfSprite_create();
    in_game->dino_bleu_t = sfTexture_createFromFile("assets/dino_bleu.png", NULL);
    in_game->dino_bleu_s = sfSprite_create();
    in_game->scale_background.x = 0.75;
    in_game->scale_background.y = 0.75;
    in_game->scale.x = 5;
    in_game->scale.y = 5;
}

sfIntRect move_rect(sfIntRect rect, int offset, int max_value)
{
    rect.left += offset;
    if (rect.left >= max_value) {
        rect.left = 0;
    }
    return rect;
}

void in_game(sfRenderWindow *window, sfEvent event, int p_current)
{
    sfIntRect rect;
    Game_t game;
    sfClock *clock;
    sfTime time;
    float seconds;
    int x_dino = -100;
    sfVector2f pos = {x_dino, 580};

    struct_in_game(&game);
    rect.top = 0;
    rect.left = 0;
    rect.width = 24;
    rect.height = 17;

    sfSprite_setTexture(game.dino_bleu_s, game.dino_bleu_t, sfTrue);
    sfSprite_setTextureRect(game.dino_bleu_s, rect);
    sfSprite_setScale(game.dino_bleu_s, game.scale);
    sfSprite_setPosition(game.dino_bleu_s, pos);

    sfSprite_setTexture(game.background_s, game.background_t, sfTrue);
    sfSprite_setScale(game.background_s, game.scale_background);

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            event_close_play(window, event);
            event_dino(window, event);
            if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
                p_current = 0;
                return;
            }
        }
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds > 0.03) {
            rect = move_rect(rect, 24, 144);
            sfSprite_setTextureRect(game.dino_bleu_s, rect);
            sfClock_restart(clock);
        }
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, game.background_s, NULL);
        sfRenderWindow_drawSprite(window, game.dino_bleu_s, NULL);
        sfRenderWindow_display(window);
        x_dino += 8;
        sfVector2f pos = {x_dino, 580};
        if (x_dino >= 1450)
            x_dino = -100;
        sfSprite_setPosition(game.dino_bleu_s, pos);
    }
    sfSprite_destroy(game.background_s);
    sfTexture_destroy(game.background_t);
    sfSprite_destroy(game.dino_bleu_s);
    sfTexture_destroy(game.dino_bleu_t);
}
