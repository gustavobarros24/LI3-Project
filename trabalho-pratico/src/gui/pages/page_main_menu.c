#include "../../../includes/gui/pages/page_main_menu.h"

WINDOW *print_main_menu() {

    int height, width, start_y, start_x;
    height = 20;
    width = 50;
	start_y = (LINES - height) / 2;
	start_x = (COLS - width) / 2;

    WINDOW *win = create_newwin(height, width, start_y, start_x);

    print_title(6);
    mvprintw(8, (COLS - strlen("Main Menu"))/2,"Main Menu");
    mvprintw(12, COLS/2 - 8, "(1) List Queries");
    mvprintw(14, COLS/2 - 8, "(2) List Data");
    mvprintw(16, COLS/2 - 8, "(3) Help");
    mvprintw(18, COLS/2 - 8, "(4) Exit");
    mvprintw(23,(COLS - strlen("Choose an option... "))/2 - 12, "Choose an option...");

    refresh();

    return win;
}

void page_main_menu(Catalog catalog, char* users_fpath, char *drivers_fpath, char *rides_fpath) {

    char c;
	while(1) {

    	WINDOW *win = print_main_menu();
    	c = wgetch(win);
		switch (c) {

			case '1':
				clear();
				page_list_queries(catalog);
				break;
			case '2':
				clear();
				page_list_db(users_fpath, drivers_fpath, rides_fpath);
				break;
			case '3':
				// page_help();
				break;
			case '4':
				clear();
				printf("Exited sucessefully");
				exit(2);
			default:
				refresh();
				break;
		}
	}
    clear();
}