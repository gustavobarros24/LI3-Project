#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <glib.h>

#ifndef QUERY_H
#define QUERY_H


typedef struct query *Query;

void set_query_id (Query query, int id);
int get_query_id (Query query);
void set_query_arg (Query query, char* arg, int i);
char* get_query_arg (Query query, int i);
size_t get_query_size ();
void free_query(Query query_to_free);
Query query_new_load(char **array);

#endif






