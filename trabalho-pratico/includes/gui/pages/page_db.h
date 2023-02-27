#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ncurses.h>

#include "../../utilities/catalog.h"
#include "../utils.h"

#ifndef PAGEDB_H
#define PAGEDB_H

WINDOW *print_page_display_data(char * filename);
void page_display_data(char *filename);
WINDOW *print_page_list_db();
void page_list_db(char *users_fpath, char *drivers_fpath, char *rides_fpath);

#endif