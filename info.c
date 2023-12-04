/*
** EPITECH PROJECT, 2023
** B-MUL-100-MAR-1-1-myhunter-leo.gregori
** File description:
** info.c
*/
#include "include/hunter.h"

int info_event(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            return 1;
    }
    return 0;
}

void info(sfRenderWindow *window, sfEvent event)
{
    sfTexture *binfo_t = sfTexture_createFromFile("assets/info.png", NULL);
    sfSprite *binfo_s = sfSprite_create();
    sfVector2f scale = {0.75, 0.75};

    sfSprite_setTexture(binfo_s, binfo_t, sfTrue);
    sfSprite_setScale(binfo_s, scale);
    while (sfRenderWindow_isOpen(window)) {
        if (info_event(window, event) == 1)
            return;
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, binfo_s, NULL);
        sfRenderWindow_display(window);
    }
    sfTexture_destroy(binfo_t);
    sfSprite_destroy(binfo_s);
}
