#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <glib.h>

#ifndef QUERY7_H
#define QUERY7_H

#include "driver.h"
#include "user.h"
#include "ride.h"
#include "date.h"
#include "../utilities/catalog.h"

typedef struct query_7_stats *Query_7_stats;

Query_7_stats new_query_7_stats();
void free_query_7_stats(void *to_free);
int query_7_compare_function(Query_7_stats s1, Query_7_stats s2);
void query_7_update_driver_stats(GHashTable *stats_table, ride r);
void query_7_print_line(FILE *file_fp, char *id, char *name, double medium_score);
char *query_7_get_output(GList *j, int d, int i, Catalog catalog);
void query_7_add_driver_to_stats_table(driver d, GHashTable *drivers_stats_table);

#endif