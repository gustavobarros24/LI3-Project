#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ncurses.h>

#include "../../utilities/catalog.h"
#include "../../types/query.h"
#include "../../types/query_1.h"
#include "../../utilities/parser.h"
#include "../../types/execute.h"
#include "../utils.h"

#ifndef PAGEQUERIES_H
#define PAGEQUERIES_H

WINDOW *print_page_queries();
WINDOW *print_page_query(char id);
WINDOW *print_page_query_1();
WINDOW *print_page_query_2();
WINDOW *print_page_query_3();
WINDOW *print_page_query_4();
WINDOW *print_page_query_5();
WINDOW *print_page_query_6();
WINDOW *print_page_query_7();
WINDOW *print_page_query_8();
WINDOW *print_page_query_9();
WINDOW *print_page_execute_query(char id);
WINDOW *print_page_results();
void page_results(char *filename);
void page_execute_query (Catalog catalog, char id);
void page_query(Catalog catalog, char id);
void page_list_queries(Catalog catalog);

#endif