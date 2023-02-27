#include "../../includes/gui/gui.h"

#define clearScreen() printf("\033[H\033[J");

char *page_get_data_folder() {

    int height = 10;
	int width = 80;
	int start_y = (LINES - height) / 2 - 2;
	int start_x = (COLS - width) / 2;


    char message[] = "Introduz o caminho para a pasta onde se encontram os ficheiros de entrada";
    char input_sign[] = "> ";
    char *buffer = malloc(sizeof(char)*80);

    create_newwin(height, width, start_y, start_x);	

    print_title(9);
    mvprintw(LINES/2 -3,(COLS - strlen(message))/2,"%s",message);
    mvprintw(LINES/2 -2,(COLS - strlen(message))/2,"%s",input_sign);

    getstr(buffer);

    clear();
    return buffer;
}

void start_gui() {

    setlocale(LC_ALL, "pt_PT.UTF-8");
    initscr();
    cbreak();

    char *original_buffer = page_get_data_folder();
    noecho();
    char *changed_buffer = malloc(sizeof(char) * 80);
    strcpy(changed_buffer, original_buffer);

    char *users_fpath = strdup(strcat(changed_buffer, "/users.csv"));
    strcpy(changed_buffer, original_buffer);
    char *drivers_fpath = strdup(strcat(changed_buffer, "/drivers.csv"));
    strcpy(changed_buffer, original_buffer);
    char *rides_fpath = strdup(strcat(changed_buffer, "/rides.csv"));

    free(changed_buffer);
    free(original_buffer);

    Catalog catalog = catalog_new(users_fpath, drivers_fpath, rides_fpath, NULL);
    catalog_load(catalog);

    page_main_menu(catalog, users_fpath, drivers_fpath, rides_fpath);

    getch();
    endwin();

}
