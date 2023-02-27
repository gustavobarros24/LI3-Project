#include "../../includes/gui/utils.h"

int from_file_to_stdout (char *filename,int page_n) {

    FILE *fp = fopen(filename, "r");

    int end = 0;    
    int buffer_size = 150, y = 7, result_n = (page_n - 1) * 20 + 1;
    char *buffer = (char *)malloc(sizeof(char)*buffer_size);

    if(strstr(filename, "user") || strstr(filename, "driver") || strstr(filename, "ride")) fgets(buffer,buffer_size, fp);
    for(int i = 0; i<(page_n - 1)*20 && fgets(buffer,buffer_size, fp); i++);

    while(result_n <=page_n*20 && fgets(buffer, buffer_size, fp)) {

        mvprintw(28, (COLS - strlen("Page 0"))/2, "Page %d", page_n); 
        if (strstr(filename, "user") || strstr(filename, "driver") || strstr(filename, "ride")) {
            buffer[strcspn(buffer, "\n")] = 0;
            mvprintw(y, COLS - 120, "%d. %s", result_n, buffer);
        } else {
            buffer[strcspn(buffer, "\n")] = 0;
            mvprintw(y, COLS - 95, "%d. %s", result_n, buffer);
        }
        y++; result_n++;
    }
    if (result_n != page_n*20 + 1) end = 1;

    fclose(fp);
    free(buffer);

    return end;
}

void pagination (char *filename, WINDOW *(*print_func)()) {

    int page_n = 1, end = 0;
    while (1) {
        end = from_file_to_stdout(filename, page_n);

        char c = getch();
        if (c == '1') {
            if (end == 0) {
                clear();
                print_func();
                page_n++;
            }
        }
        if (c == '0') {
            if (page_n != 1) {
                clear();
                print_func();
                page_n--;
                
            } else break;
        }
    }

}

void print_title(int y){

    char title[] = "Uber Manager";

    mvprintw(y, (COLS - strlen(title))/2, "%s", title);
    
}

WINDOW *create_newwin(int height, int width, int start_y, int start_x) {

	WINDOW * win = newwin(height, width, start_y, start_x);
    refresh();

    box(win, 0, 0);
    mvwprintw(win, 0, 2, "LI3 - Grupo 15");
    wrefresh(win);

	return win;
}

void prepend(char* s, char* t) {
    
    size_t len = strlen(t);
    memmove(s + len, s, strlen(s) + 1);
    memcpy(s, t, len);

}
