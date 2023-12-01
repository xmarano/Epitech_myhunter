/*
** EPITECH PROJECT, 2023
** B-MUL-100-MAR-1-1-myhunter-leo.gregori
** File description:
** game_over.c
*/
#include "include/hunter.h"

void event_over(sfRenderWindow *window, sfEvent event, int p_current,
    Over_t *over)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            p_current = 0;
            over->exit = 1;
        }
    }
}

static void struct_game_over(Over_t *over)
{
    over->over_t = sfTexture_createFromFile("assets/game_over.png", NULL);
    over->over_s = sfSprite_create();
    over->nombre = sfText_create();
    over->score = 0;
    over->exit = 0;
}

void final_score(sfRenderWindow *window, Game_t *in_game)
{
    sfVector2f pos_nombre = {660, 440};

    sfText_setFont(in_game->nombre, in_game->font);
    sfText_setString(in_game->nombre, my_inttostr(in_game->score));
    sfText_setCharacterSize(in_game->nombre, 40);
    sfText_setFillColor(in_game->nombre, sfWhite);
    sfText_setPosition(in_game->nombre, pos_nombre);
    sfRenderWindow_drawText(window, in_game->nombre, NULL);
}

static int info_line(char *buffer)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *str;

    while (buffer[i] != '\n')
        i++;
    str = malloc(i * sizeof(char));
    while (j < i) {
        str[j] = buffer[j];
        j++;
    }
    k = my_atoi(str);
    return k;
}

void change_high_score(sfRenderWindow *window, Game_t *in_game)
{
    int file_write = open("highscore", O_WRONLY | O_TRUNC | S_IWUSR);
    char *new_score_str = my_inttostr(in_game->score);

    write(file_write, new_score_str, my_strlen(new_score_str));
    close(file_write);
}

void high_score(sfRenderWindow *window, Game_t *in_game)
{
    struct stat info_file;
    int file_read = open("highscore", O_RDONLY);
    char buffer[300];
    int read_file = read(file_read, buffer, sizeof(buffer));
    int high_score = info_line(buffer);
    sfVector2f pos_high_score = {875, 700};
    sfText *best_score = sfText_create();

    sfText_setFont(best_score, in_game->font);
    sfText_setString(best_score, buffer);
    sfText_setCharacterSize(best_score, 42);
    sfText_setFillColor(best_score, sfYellow);
    sfText_setPosition(best_score, pos_high_score);
    sfRenderWindow_drawText(window, best_score, NULL);
    close(file_read);
    if (in_game->score > high_score)
        change_high_score(window, in_game);
}

void game_over(sfRenderWindow *window, sfEvent event, Game_t *in_game,
    int p_current)
{
    Over_t over;

    struct_game_over(&over);
    sfSprite_setTexture(over.over_s, over.over_t, sfTrue);
    sfSprite_setScale(over.over_s, in_game->scale_background);
    while (sfRenderWindow_isOpen(window)) {
        event_over(window, event, p_current, &over);
        if (over.exit == 1)
            return;
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, over.over_s, NULL);
        final_score(window, in_game);
        high_score(window, in_game);
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(over.over_s);
    sfTexture_destroy(over.over_t);
}
