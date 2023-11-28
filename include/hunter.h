/*
** EPITECH PROJECT, 2023
** B-MUL-100-MAR-1-1-myhunter-leo.gregori
** File description:
** my_hunter : hunter.h
*/
#include "my.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>
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
} Sprite_t;
typedef struct Game {
    sfVector2f scale_background;
    sfVector2f scale;
    sfTexture *background_t;
    sfSprite *background_s;
    sfTexture *dino_bleu_t;
    sfSprite *dino_bleu_s;
} Game_t;

void in_game(sfRenderWindow *window, sfEvent event, int p_current);

#endif
