#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>

int main() {
    std::cout << "Starting program...\n";

    if (!al_init()) {
        std::cout << "Failed to initialize Allegro.\n";
        return -1;
    }

    al_init_font_addon();
    if (!al_init_ttf_addon()) {
        std::cout << "Failed to initialize TTF addon.\n";
        return -1;
    }

    ALLEGRO_DISPLAY* display = al_create_display(800, 600);
    if (!display) {
        std::cout << "Failed to create display.\n";
        return -1;
    }

    ALLEGRO_FONT* font = al_load_ttf_font("YARDSALE.TTF", 48, 0);
    if (!font) {
        std::cout << "Failed to load font. Is 'YARDSALE.TTF' in the working directory?\n";
        al_destroy_display(display);
        return -1;
    }

    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_text(font, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTRE, "Hello, World!");
    al_flip_display();

    al_rest(3.0);

    al_destroy_font(font);
    al_destroy_display(display);

    std::cout << "Program ended normally.\n";
    return 0;
}
