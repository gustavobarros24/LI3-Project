#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ncurses.h>

#include "../../utilities/catalog.h"
#include "page_queries.h"
#include "page_db.h"
#include "../utils.h"

#ifndef PAGEMAINMENU_H
#define PAGEMAINMENU_H

WINDOW *print_main_menu();
void page_main_menu(Catalog catalog, char* users_fpath, char *drivers_fpath, char *rides_fpath);

#endif