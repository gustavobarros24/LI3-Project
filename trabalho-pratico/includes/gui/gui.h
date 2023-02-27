#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ncurses.h>
#include <locale.h>

#include "../types/driver.h"
#include "../types/user.h"
#include "../types/ride.h"
#include "../utilities/catalog.h"
#include "pages/page_queries.h"
#include "pages/page_main_menu.h"

#ifndef GUI_H
#define GUI_H

char *page_get_data_folder();
void page_query_1(Catalog catalog);
void page_query_2(Catalog catalog);
void page_query_3(Catalog catalog);
void page_query_4(Catalog catalog);
void page_query_5(Catalog catalog);
void page_query_6(Catalog catalog);
void page_query_7(Catalog catalog);
void page_query_8(Catalog catalog);
void page_query_9(Catalog catalog);
void start_gui();

#endif