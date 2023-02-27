#include "../../../includes/gui/pages/page_db.h"

WINDOW* print_page_display_data(char* filename) {

    int height, width, start_y, start_x;
    height = 30;
    width = 110;
	start_y = (LINES - height) / 2;
	start_x = (COLS - width) / 2;

    WINDOW *win = create_newwin(height, width, start_y, start_x);


    print_title(2);
    if (strstr(filename, "user")) mvprintw(4, (COLS - strlen("List of Users"))/2, "List of Users");
    if (strstr(filename, "driver")) mvprintw(4, (COLS - strlen("List of Drivers"))/2, "List of Drivers");
    if (strstr(filename, "ride")) mvprintw(4, (COLS - strlen("List of Rides"))/2, "List of Rides");
    mvprintw(28, COLS - 95, "(0) Back");
    mvprintw(28, COLS - 49, "(1) Next");

    refresh();

    return win;
}

void page_display_data(char *filename) {

    noecho();

    print_page_display_data(filename);
    pagination(filename, print_page_display_data);
    
    echo();
}

WINDOW *print_page_list_db() {

    int height, width, start_y, start_x;
    height = 20;
    width = 50;
	start_y = (LINES - height) / 2;
	start_x = (COLS - width) / 2;

    WINDOW *win = create_newwin(height, width, start_y, start_x);

    print_title(6);
    mvprintw(8, (COLS - strlen("Data Set"))/2, "Data Set");
    mvprintw(12, (COLS - strlen("(1) See Users"))/2, "(1) See Users");    
    mvprintw(15, (COLS - strlen("(2) See Drivers"))/2 + 1, "(2) See Drivers");
    mvprintw(18, (COLS - strlen("(3) See Rides"))/2, "(3) See Rides");
    mvprintw(23, (COLS - strlen("Data Set"))/2, "(0) Back");

    refresh();

    return win;
}

void page_list_db(char *users_fpath, char *drivers_fpath, char *rides_fpath) {

    char c;
    while (1) {
        print_page_list_db();
        c = getch();
        if (c == '1' ) {
            page_display_data(users_fpath);
            clear();
        } else if (c == '2' ) {
            page_display_data(drivers_fpath);
            clear();
            } else if (c == '3' ) {
            page_display_data(rides_fpath);
            clear();
                } else if (c == '0') break;
    }
}