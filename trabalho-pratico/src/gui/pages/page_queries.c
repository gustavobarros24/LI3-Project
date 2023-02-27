#include "../../../includes/gui/pages/page_queries.h"

WINDOW *print_page_queries() {

    int height, width, start_y, start_x;
    height = 20;
    width = 50;
	start_y = (LINES - height) / 2;
	start_x = (COLS - width) / 2;

    WINDOW *win = create_newwin(height, width, start_y, start_x);

    print_title(6);
    mvprintw(8,(COLS - strlen("Queries List"))/2, "Queries List");
    
    mvprintw(12, (COLS - strlen("Query 1"))/2 - 11, "Query 1");
    mvprintw(12, (COLS - strlen("Query 2"))/2, "Query 2");
    mvprintw(12, (COLS - strlen("Query 3"))/2 + 11, "Query 3");
    mvprintw(14, (COLS - strlen("Query 4"))/2 - 11, "Query 4");
    mvprintw(14, (COLS - strlen("Query 5"))/2, "Query 5");
    mvprintw(14, (COLS - strlen("Query 6"))/2 + 11, "Query 6");
    mvprintw(16, (COLS - strlen("Query 7"))/2 - 11, "Query 7");
    mvprintw(16, (COLS - strlen("Query 8"))/2, "Query 8");
    mvprintw(16, (COLS - strlen("Query 9"))/2 + 11, "Query 9");

    mvprintw(21, (COLS - strlen("Choose a query number for more information..."))/2, "Choose a query number for more information...");
    mvprintw(23, (COLS - strlen("(0) Back"))/2, "%s", "(0) Back");

    refresh();

    return win;
}

WINDOW *print_page_query(char id) {

    int height, width, start_y, start_x;
    height = 20;
    width = 70;
	start_y = (LINES - height) / 2;
	start_x = (COLS - width) / 2;

    WINDOW *win = create_newwin(height, width, start_y, start_x);

    print_title(6);
    mvprintw(8,(COLS - strlen("Query 0"))/2, "Query %c", id);
    mvprintw(23, (COLS - strlen("(1) Execute Query   (0) Back"))/2, "(1) Execute Query   (0) Back" );

    return win;

}

WINDOW *print_page_query_1() {

    WINDOW *win = print_page_query(1);
    mvprintw(12, COLS - 100, "Description: List a user/driver profile resume");
    mvprintw(14, COLS - 100, "Arguments:");
    mvprintw(15, COLS - 95, "- <ID> - User's username or Driver's id");
    mvprintw(17, COLS - 100, "Output Example:");
    mvprintw(18, COLS - 95, "name;gender;age;average_score;number_of_rides;total_spent");

    refresh();

    return win;
}

WINDOW *print_page_query_2() {

    WINDOW *win = print_page_query(2);
    mvprintw(12, COLS - 100, "Description: List the N drivers with the best average score");
    mvprintw(14, COLS - 100, "Arguments:");
    mvprintw(15, COLS - 95, "- <N> - Number of drivers");
    mvprintw(17, COLS - 100, "Output Example:");
    mvprintw(18, COLS - 95, "id;name;average_score");

    refresh();

    return win;
}

WINDOW *print_page_query_3() {

    WINDOW *win = print_page_query(3);
    mvprintw(12, COLS - 100, "Description: List the N users with the most distance traveled");
    mvprintw(14, COLS - 100, "Arguments:");
    mvprintw(15, COLS - 95, "- <N> - Number of users");
    mvprintw(17, COLS - 100, "Output Example:");
    mvprintw(18, COLS - 95, "username;name;total_distance");

    refresh();

    return win;
}

WINDOW *print_page_query_4() {

    WINDOW *win = print_page_query(4);
    mvprintw(12, COLS - 100, "Description: Average ride price (without tips) in a given city");
    mvprintw(14, COLS - 100, "Arguments:");
    mvprintw(15, COLS - 95, "- <city> - city");
    mvprintw(17, COLS - 100, "Output Example:");
    mvprintw(18, COLS - 95, "average_price");

    refresh();

    return win;
}

WINDOW *print_page_query_5() {

    WINDOW *win = print_page_query(5);
    mvprintw(12, COLS - 100, "Description: Average ride price (without tips) in a given time");
    mvprintw(13, COLS - 87, "span");
    mvprintw(15, COLS - 100, "Arguments:");
    mvprintw(16, COLS - 95, "- <date A> - Start date");
    mvprintw(17, COLS - 95, "- <date B> - End date");
    mvprintw(19, COLS - 100, "Output Example:");
    mvprintw(20, COLS - 95, "average_price");

    refresh();

    return win;
}

WINDOW *print_page_query_6() {

    WINDOW *win = print_page_query(6);
    mvprintw(12, COLS - 100, "Description: Average distance traveled, in a given city, in a");
    mvprintw(13, COLS - 87, "given time span");
    mvprintw(15, COLS - 100, "Arguments:");
    mvprintw(16, COLS - 95, "- <city> - city");
    mvprintw(17, COLS - 95, "- <date A> - Start date");
    mvprintw(18, COLS - 95, "- <date B> - End date");
    mvprintw(20, COLS - 100, "Output Example:");
    mvprintw(21, COLS - 95, "average_distance");

    refresh();

    return win;
}

WINDOW *print_page_query_7() {

    WINDOW *win = print_page_query(7);
    mvprintw(12, COLS - 100, "Description: Top N drivers in a given city, ordered by average");
    mvprintw(13, COLS - 87, "score");
    mvprintw(15, COLS - 100, "Arguments:");
    mvprintw(16, COLS - 95, "- <N> - Number of drivers");
    mvprintw(17, COLS - 95, "- <city> - city");
    mvprintw(19, COLS - 100, "Output Example:");
    mvprintw(20, COLS - 95, "id;name;average_score");

    refresh();

    return win;
}

WINDOW *print_page_query_8() {

    WINDOW *win = print_page_query(8);
    mvprintw(12, COLS - 100, "Description: List rides in which user and driver are the same");
    mvprintw(13, COLS - 87, "gender and are X or older");
    mvprintw(15, COLS - 100, "Arguments:");
    mvprintw(16, COLS - 95, "- <gender> - gender of both user and driver");
    mvprintw(17, COLS - 95, "- <X> - age of both user and driver");
    mvprintw(19, COLS - 100, "Output Example:");
    mvprintw(20, COLS - 95, "driver_id;driver_name;user_username;user_name");

    refresh();

    return win;
}

WINDOW *print_page_query_9() {

    WINDOW *win = print_page_query(9);
    mvprintw(12, COLS - 100, "Description: List rides where the user gave a tip, in a given");
    mvprintw(13, COLS - 87, "time span");
    mvprintw(15, COLS - 100, "Arguments:");
    mvprintw(16, COLS - 95, "- <date A> - Start date");
    mvprintw(17, COLS - 95, "- <date B> - End date");
    mvprintw(19, COLS - 100, "Output Example:");
    mvprintw(20, COLS - 95, "ride_id;ride_date;distance;city;tip_value");
    refresh();

    return win;
}

WINDOW* print_page_results() {

    int height, width, start_y, start_x;
    height = 30;
    width = 70;
	start_y = (LINES - height) / 2;
	start_x = (COLS - width) / 2;

    WINDOW *win = create_newwin(height, width, start_y, start_x);

    print_title(2);
    mvprintw(4,(COLS - strlen("Results"))/2, "Results");
    mvprintw(28, COLS - 95, "(0) Back");
    mvprintw(28, COLS - 49, "(1) Next");

    return win;
}

void page_results(char* filename) {

    noecho();

    print_page_results();
    pagination(filename, print_page_results);

    echo();
}

WINDOW *print_page_execute_query(char id) {

    int height, width, start_y, start_x;
    height = 15;
    width = 50;
	start_y = (LINES - height) / 2;
	start_x = (COLS - width) / 2;

    WINDOW *win = create_newwin(height, width, start_y, start_x);

    print_title(9);
    mvprintw(10,(COLS - strlen("Execute Query 0"))/2, "Execute Query %c", id);
    mvprintw(14, COLS/2 - 20, "Arguments with a space between them: ");
    mvprintw(17, COLS/2 - 20, "Write \"back\" to back");
    mvprintw(15, COLS/2 - 20, "> ");

    refresh();

    return win;
}

void page_execute_query (Catalog catalog, char id) {

    WINDOW *win = print_page_execute_query(id);
    char *buffer = malloc(sizeof(char)*80);

    char to_prepend[2];
    to_prepend[0] = id; to_prepend[1] = ' ';
    echo();

    getstr(buffer);

    if (strcmp(buffer,"back") && strcmp(buffer,"Back")) {

        prepend(buffer, to_prepend);   
        char **buffer_arrayzed;
        char* filename;

        buffer_arrayzed = parser(4, buffer);

        wattron(win, A_BLINK);
        mvprintw(20, (COLS - strlen("Executing Query..."))/2, "Executing Query...");
        wattroff(win, A_BLINK);
        refresh();

        Query query_new = query_new_load(buffer_arrayzed);

        filename = execute_query(catalog, query_new, 0);

        free_query(query_new);
        free(buffer_arrayzed);
        clear();
        
        page_results(filename);

        free(filename);
    }
}

void page_query(Catalog catalog, char id) {

    char c;

    while(1) {
        switch (id) {
            case '1':
                print_page_query_1();
                break;
            case '2':
                print_page_query_2();
                break;
            case '3':
                print_page_query_3();
                break;
            case '4':
                print_page_query_4();
                break;
            case '5':
                print_page_query_5();
                break;
            case '6':
                print_page_query_6();
                break;
            case '7':
                print_page_query_7();
                break;
            case '8':
                print_page_query_8();
                break;
            case '9':
                print_page_query_9();
                break;
        }
        c = getch();
		if (c == '1') {
            clear();
            page_execute_query(catalog, id);
        }
        if (c == '0'){
            clear();
            break;
        }
        clear();
	}
}

void page_list_queries(Catalog catalog) {

    char c;
    char id = '1';

    while(1) {

        WINDOW *win = print_page_queries();
    	c = wgetch(win);
		if (strchr("123456789", c)) {
            page_query(catalog, id);
        } else if (c == '0') break;
	}
    refresh();    
}