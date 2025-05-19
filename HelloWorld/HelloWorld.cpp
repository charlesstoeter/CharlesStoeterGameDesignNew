#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
#include <allegro5/allegro_primitives.h>

// int main()
int main() {
	std::cout << "Starting the program\n";
	// initialize Allegro
	if (!al_init()) {
		std::cout << "Failed to initialize Allegro\n";
		return -1;
	}

	//keyboard
	if (!al_install_keyboard()) {
		std::cout << "Failed to install keyboard\n";
		return -1;
	}

	// initialize the font addon
	if (!al_init_font_addon()) {
		std::cout << "Failed to initialize font addon\n";
		return -1;
	}

	// initialize the ttf addon
	if (!al_init_ttf_addon()) {
		std::cout << "Failed to initialize ttf addon\n";
		return -1;
	}

	//initialize the primitves addon
	al_init_primitives_addon();

	// initialize the display
	ALLEGRO_DISPLAY* display = al_create_display(800, 600);

	al_clear_to_color(al_map_rgb(0, 0, 0));


	if (!display) {
		std::cout << "Failed to create display\n";
		return -1;
	}

	al_draw_filled_ellipse(385, 335, 300, 200, al_map_rgb(255, 105, 180)); // pink ellipse


	
	al_draw_filled_rectangle(150, 200, 650, 450, al_map_rgb(50, 50, 50)); // dark gray

	
	al_draw_filled_rectangle(180, 230, 620, 420, al_map_rgb(0, 255, 255)); // bluew screen

	// Ground platform (green rectangle)
	al_draw_filled_rectangle(180, 390, 620, 420, al_map_rgb(0, 255, 0));


	al_draw_filled_rectangle(220, 360, 250, 390, al_map_rgb(255, 255, 0)); // yellow cube

	al_draw_filled_triangle(300, 390, 320, 390, 310, 370, al_map_rgb(255, 0, 0)); // red triangle

	al_draw_filled_circle(640, 325, 15, al_map_rgb(200, 200, 200)); // Light gray





	//flips display to the front
	al_flip_display();


	al_rest(5.0); // Wait for 5 seconds

	// clean up
	al_destroy_display(display);

	std::cout << "Program ended normally\n";

	return 0;

}