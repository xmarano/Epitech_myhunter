/*
** EPITECH PROJECT, 2023
** B-MUL-100-MAR-1-1-myhunter-leo.gregori
** File description:
** main.c
*/
#include "include/hunter.h"

void key_up(int *p_current)
{
    if ((*p_current) == 0)
        (*p_current) = 2;
    else
        (*p_current) = ((*p_current) - 1) % 3;
}

void event_close(sfRenderWindow *window, int *p_current)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (sfKeyboard_isKeyPressed(sfKeyDown))
            (*p_current) = ((*p_current) + 1) % 3;
        if (sfKeyboard_isKeyPressed(sfKeyUp))
            key_up(p_current);
        if (sfKeyboard_isKeyPressed(sfKeyReturn) && (*p_current) == 0)
            in_game(window, event, *p_current);
        if (sfKeyboard_isKeyPressed(sfKeyReturn) && (*p_current) == 1)
            info(window, event);
        if (sfKeyboard_isKeyPressed(sfKeyReturn) && (*p_current) == 2)
            sfRenderWindow_close(window);
    }
}

static void initial(Sprite_t *image)
{
    image->play_t = sfTexture_createFromFile("assets/menu_play.png", NULL);
    image->play_s = sfSprite_create();
    image->info_t = sfTexture_createFromFile("assets/menu_info.png", NULL);
    image->info_s = sfSprite_create();
    image->exit_t = sfTexture_createFromFile("assets/menu_exit.png", NULL);
    image->exit_s = sfSprite_create();
    image->scale.x = 0.75;
    image->scale.y = 0.75;
}

void set_st(sfRenderWindow *window, Sprite_t *image, sfSprite **tab_menu)
{
    sfSprite_setTexture(image->play_s, image->play_t, sfTrue);
    sfSprite_setScale(image->play_s, image->scale);
    sfSprite_setTexture(image->info_s, image->info_t, sfTrue);
    sfSprite_setScale(image->info_s, image->scale);
    sfSprite_setTexture(image->exit_s, image->exit_t, sfTrue);
    sfSprite_setScale(image->exit_s, image->scale);
    tab_menu[0] = image->play_s;
    tab_menu[1] = image->info_s;
    tab_menu[2] = image->exit_s;
    sfRenderWindow_setFramerateLimit(window, 60);
}

static int error_handle(sfRenderWindow *window, Sprite_t *image)
{
    if (!image->play_t)
        return 84;
    if (!image->info_t)
        return 84;
    if (!image->exit_t)
        return 84;
    return 0;
}

void destroy_all(sfRenderWindow *window, Sprite_t *image)
{
    sfSprite_destroy(image->play_s);
    sfTexture_destroy(image->play_t);
    sfSprite_destroy(image->info_s);
    sfTexture_destroy(image->info_t);
    sfSprite_destroy(image->exit_s);
    sfTexture_destroy(image->exit_t);
    sfRenderWindow_destroy(window);
}

static int my_hunter_h(void)
{
    write(1, "--------------------------------------\n", 40);
    write(1, "|       Bienvenue sur My_Hunter      |\n", 40);
    write(1, "|------------------------------------|\n", 40);
    write(1, "|  À vous de faire le meilleur score |\n", 40);
    write(1, "|     Tuez le maximum de dino !!!    |\n", 40);
    write(1, "--------------------------------------\n", 40);
    return 0;
}

static void sf_render(sfRenderWindow *window, sfSprite *tab_menu[3],
    int current)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, tab_menu[current], NULL);
    sfRenderWindow_display(window);
}

int main(int argc, char **argv)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    Sprite_t image;
    sfSprite *tab_menu[3];
    int current = 0;
    int error = error_handle(window, &image);

    if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'h')
        return my_hunter_h();
    initial(&image);
    window = sfRenderWindow_create(mode, "MyHunter", sfResize | sfClose, NULL);
    set_st(window, &image, tab_menu);
    while (sfRenderWindow_isOpen(window)) {
        sf_render(window, tab_menu, current);
        event_close(window, &current);
    }
    destroy_all(window, &image);
    return 0;
}
