/*
** EPITECH PROJECT, 2023
** B-MUL-100-MAR-1-1-myhunter-leo.gregori
** File description:
** my_hunter : hunter.h
*/
#include "my.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#ifndef HUNTER_H
    #define HUNTER_H
typedef struct Sprite {
    sfTexture *play_t;
    sfVector2f scale;
    sfSprite *play_s;
    sfTexture *info_t;
    sfSprite *info_s;
    sfTexture *exit_t;
    sfSprite *exit_s;
    int current;
} Sprite_t;
typedef struct Game {
    sfVector2f scale_background;
    sfVector2f scale;
    sfTexture *background_t;
    sfSprite *background_s;
    sfTexture *dino_bleu_t;
    sfSprite *dino_bleu_s;
    int x_dino;
    int y_dino;
    float speed;
    int score;
    sfFont *font;
    sfText *text;
    sfText *nombre;
    sfMusic *shoot;
    sfMusic *life;
    int nb_life;
    sfMusic *music;
    sfMusic *game_over;
} Game_t;
typedef struct Heart {
    sfTexture *heart_5_t;
    sfSprite *heart_5_s;
    sfTexture *heart_4_t;
    sfSprite *heart_4_s;
    sfTexture *heart_3_t;
    sfSprite *heart_3_s;
    sfTexture *heart_2_t;
    sfSprite *heart_2_s;
    sfTexture *heart_1_t;
    sfSprite *heart_1_s;
    sfTexture *aim_t;
    sfSprite *aim_s;
    sfVector2f aim_scale;
} Heart_t;
typedef struct Over {
    sfTexture *over_t;
    sfSprite *over_s;
    sfText *text;
    sfText *nombre;
    int score;
    int exit;
} Over_t;
void in_game(sfRenderWindow *window, sfEvent event, int p_current);
void game_over(sfRenderWindow *window, sfEvent event, Game_t *in_game,
    int p_current);
void dino_window(sfRenderWindow *window, Game_t *game, Heart_t *heart);
int events_hunter(sfRenderWindow *window, sfEvent event, int *p_current,
    Game_t *game);
void init_game(Game_t *game, Heart_t *heart, sfIntRect *rect);
void dino_life(sfRenderWindow *window, Game_t *game, Heart_t *heart);
void time_handeling(Game_t *game, sfIntRect *rect, sfClock *clock);
void struct_in_game(Game_t *in_game);
void event_click(sfRenderWindow *window, sfEvent event, Game_t *in_game);
void dino_position(sfRenderWindow *window, Game_t *in_game);
sfIntRect move_rect(sfIntRect rect, int offset, int max_value);
void struct_in_game_heart(Heart_t *heart);
void set_texture(Game_t *game, Heart_t *heart, sfIntRect rect);
void dino_score(sfRenderWindow *window, Game_t *in_game);
void info(sfRenderWindow *window, sfEvent event);
#endif
