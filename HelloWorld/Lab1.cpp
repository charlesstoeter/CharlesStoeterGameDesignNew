#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
#include <allegro5/allegro_primitives.h>

// int main()
int main() {
	std::cout << "Starting the program\n";
	// Initialize Allegro
	if (!al_init()) {
		std::cout << "Failed to initialize Allegro\n";
		return -1;
	}

	//keyboard
	if (!al_install_keyboard()) {
		std::cout << "Failed to install keyboard\n";
		return -1;
	}

	// Initialize the font addon
	if (!al_init_font_addon()) {
		std::cout << "Failed to initialize font addon\n";
		return -1;
	}

	// Initialize the ttf addon
	if (!al_init_ttf_addon()) {
		std::cout << "Failed to initialize ttf addon\n";
		return -1;
	}

	//initialize the primitves addon
	al_init_primitives_addon();

	// Initialize the display
	ALLEGRO_DISPLAY* display = al_create_display(800, 600);

	al_clear_to_color(al_map_rgb(0, 0, 0));


	if (!display) {
		std::cout << "Failed to create display\n";
		return -1;
	}

	// Initialize starting screen/clear screen
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_draw_filled_rectangle(200, 300, 400, 500, al_map_rgb(255, 255, 255)); // white

	//flips display to the front
	al_flip_display();


	al_rest(5.0); // Wait for 5 seconds

	// clean up
	al_destroy_display(display);

	std::cout << "Program ended normally\n";

	return 0;

}