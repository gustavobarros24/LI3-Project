#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <glib.h>
#include "driver.h"
#include "user.h"
#include "ride.h"
#include "../includes/utilities/catalog.h"

typedef struct query_8_stats *Query_8_stats;
Query_8_stats query_8_stats_new(char *driver_id, char *username, char *ride_id, Date u1, Date d2);
void free_query_8_stats(void *to_free);
int query_8_compare_function(Query_8_stats s1, Query_8_stats s2);
void query_8_print_line(FILE *file_fp, char *id, char*d_name, char *username, char *u_name);
char *query_8_get_output(Catalog catalog, GList *stats, int i);