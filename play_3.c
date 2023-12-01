/*
** EPITECH PROJECT, 2023
** B-MUL-100-MAR-1-1-myhunter-leo.gregori
** File description:
** play.c
*/
#include "include/hunter.h"

void dino_position(sfRenderWindow *window, Game_t *in_game)
{
    sfVector2f pos = {in_game->x_dino, in_game->y_dino};

    in_game->x_dino = in_game->x_dino + 8 + in_game->speed;
    if (in_game->x_dino >= 1450) {
        in_game->x_dino = -100;
        in_game->y_dino = ((rand() % 610) + 0);
        in_game->speed = 0;
        sfMusic_play(in_game->life);
        in_game->nb_life--;
    }
    sfSprite_setPosition(in_game->dino_bleu_s, pos);
    in_game->speed = in_game->speed + 0.02;
}

void dino_score(sfRenderWindow *window, Game_t *in_game)
{
    sfVector2f pos_score = {60, 700};
    sfVector2f pos_nombre = {290, 700};

    sfText_setFont(in_game->text, in_game->font);
    sfText_setString(in_game->text, "score:");
    sfText_setCharacterSize(in_game->text, 35);
    sfText_setFillColor(in_game->text, sfWhite);
    sfText_setPosition(in_game->text, pos_score);
    sfRenderWindow_drawText(window, in_game->text, NULL);
    sfText_setFont(in_game->nombre, in_game->font);
    sfText_setString(in_game->nombre, my_inttostr(in_game->score));
    sfText_setCharacterSize(in_game->nombre, 35);
    sfText_setFillColor(in_game->nombre, sfWhite);
    sfText_setPosition(in_game->nombre, pos_nombre);
    sfRenderWindow_drawText(window, in_game->nombre, NULL);
}

void set_texture(Game_t *game, Heart_t *heart, sfIntRect rect)
{
    sfVector2f pos = {game->x_dino, game->y_dino};

    sfSprite_setTexture(game->dino_bleu_s, game->dino_bleu_t, sfTrue);
    sfSprite_setTextureRect(game->dino_bleu_s, rect);
    sfSprite_setScale(game->dino_bleu_s, game->scale);
    sfSprite_setPosition(game->dino_bleu_s, pos);
    sfSprite_setTexture(heart->heart_5_s, heart->heart_5_t, sfTrue);
    sfSprite_setScale(heart->heart_5_s, game->scale_background);
    sfSprite_setTexture(heart->heart_4_s, heart->heart_4_t, sfTrue);
    sfSprite_setScale(heart->heart_4_s, game->scale_background);
    sfSprite_setTexture(heart->heart_3_s, heart->heart_3_t, sfTrue);
    sfSprite_setScale(heart->heart_3_s, game->scale_background);
    sfSprite_setTexture(heart->heart_2_s, heart->heart_2_t, sfTrue);
    sfSprite_setScale(heart->heart_2_s, game->scale_background);
    sfSprite_setTexture(heart->heart_1_s, heart->heart_1_t, sfTrue);
    sfSprite_setScale(heart->heart_1_s, game->scale_background);
    sfSprite_setTexture(game->background_s, game->background_t, sfTrue);
    sfSprite_setScale(game->background_s, game->scale_background);
}
