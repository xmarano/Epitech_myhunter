/*
** EPITECH PROJECT, 2023
** B-MUL-100-MAR-1-1-myhunter-leo.gregori
** File description:
** play.c
*/
#include "include/hunter.h"

void struct_in_game(Game_t *in_game)
{
    in_game->background_t = sfTexture_createFromFile("assets/fond.png", NULL);
    in_game->background_s = sfSprite_create();
    in_game->dino_bleu_t = sfTexture_createFromFile("assets/dino.png", NULL);
    in_game->dino_bleu_s = sfSprite_create();
    in_game->scale_background.x = 0.75;
    in_game->scale_background.y = 0.75;
    in_game->scale.x = 5;
    in_game->scale.y = 5;
    in_game->x_dino = -100;
    in_game->y_dino = 580;
    in_game->speed = 0;
    in_game->score = 0;
    in_game->font = sfFont_createFromFile("assets/daydream.ttf");
    in_game->text = sfText_create();
    in_game->nombre = sfText_create();
    in_game->music = sfMusic_createFromFile("assets/song.ogg");
    in_game->shoot = sfMusic_createFromFile("assets/shoot.ogg");
    in_game->life = sfMusic_createFromFile("assets/life.ogg");
    in_game->game_over = sfMusic_createFromFile("assets/game_over.ogg");
    in_game->nb_life = 5;
}

void struct_in_game_heart(Heart_t *heart)
{
    heart->heart_5_t = sfTexture_createFromFile("assets/heart_5.png", NULL);
    heart->heart_5_s = sfSprite_create();
    heart->heart_4_t = sfTexture_createFromFile("assets/heart_4.png", NULL);
    heart->heart_4_s = sfSprite_create();
    heart->heart_3_t = sfTexture_createFromFile("assets/heart_3.png", NULL);
    heart->heart_3_s = sfSprite_create();
    heart->heart_2_t = sfTexture_createFromFile("assets/heart_2.png", NULL);
    heart->heart_2_s = sfSprite_create();
    heart->heart_1_t = sfTexture_createFromFile("assets/heart_1.png", NULL);
    heart->heart_1_s = sfSprite_create();
    heart->aim_t = sfTexture_createFromFile("assets/crosshair.png", NULL);
    heart->aim_s = sfSprite_create();
    heart->aim_scale.x = 0.1;
    heart->aim_scale.y = 0.1;
}

void event_click(sfRenderWindow *window, sfEvent event, Game_t *in_game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse2 = sfRenderWindow_mapPixelToCoords(window, mouse, NULL);
    sfFloatRect dino_shoot = sfSprite_getGlobalBounds(in_game->dino_bleu_s);
    sfVector2f pos = {in_game->x_dino, in_game->y_dino};
    sfVector2f new_position = {-100, in_game->y_dino};

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseButtonPressed) {
        if (sfFloatRect_contains(&dino_shoot, mouse2.x, mouse2.y)) {
            in_game->x_dino = -100;
            in_game->y_dino = ((rand() % 610) + 0);
            in_game->score += 25;
            sfMusic_play(in_game->shoot);
        }
    }
}

sfIntRect move_rect(sfIntRect rect, int offset, int max_value)
{
    rect.left += offset;
    if (rect.left >= max_value) {
        rect.left = 0;
    }
    return rect;
}

static void destroy_all_play(Game_t *in_game, Heart_t *heart)
{
    sfSprite_destroy(in_game->background_s);
    sfTexture_destroy(in_game->background_t);
    sfSprite_destroy(in_game->dino_bleu_s);
    sfTexture_destroy(in_game->dino_bleu_t);
    sfSprite_destroy(heart->heart_1_s);
    sfTexture_destroy(heart->heart_1_t);
    sfSprite_destroy(heart->heart_2_s);
    sfTexture_destroy(heart->heart_2_t);
    sfSprite_destroy(heart->heart_3_s);
    sfTexture_destroy(heart->heart_3_t);
    sfSprite_destroy(heart->heart_4_s);
    sfTexture_destroy(heart->heart_4_t);
    sfSprite_destroy(heart->heart_5_s);
    sfTexture_destroy(heart->heart_5_t);
    sfMusic_destroy(in_game->music);
    sfText_destroy(in_game->text);
    sfFont_destroy(in_game->font);
    sfMusic_destroy(in_game->shoot);
    sfMusic_destroy(in_game->life);
    sfText_destroy(in_game->nombre);
}

void in_game(sfRenderWindow *window, sfEvent event, int p_current)
{
    sfIntRect rect;
    Game_t game;
    Heart_t heart;
    sfClock *clock = sfClock_create();

    init_game(&game, &heart, &rect);
    while (sfRenderWindow_isOpen(window)) {
        if (events_hunter(window, event, &p_current, &game) == 1)
            return;
        time_handeling(&game, &rect, clock);
        dino_life(window, &game, &heart);
        if (game.nb_life == 0) {
            sfMusic_destroy(game.music);
            sfMusic_play(game.game_over);
            game_over(window, event, &game, p_current);
            return;
        }
    }
    destroy_all_play(&game, &heart);
}
