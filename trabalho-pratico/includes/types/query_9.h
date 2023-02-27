#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <glib.h>
#include "driver.h"
#include "user.h"
#include "ride.h"
#include "../includes/utilities/catalog.h"

#ifndef QUERY9_H
#define QUERY9_H

#include "driver.h"
#include "user.h"
#include "ride.h"
#include "date.h"
#include "../utilities/catalog.h"

typedef struct query_9_stats *Query_9_stats;

Query_9_stats new_querie_9_stats();
void free_query_9_stats(void *to_free);

Query_9_stats query_9_add_ride_to_stats_list(ride d);
int query_9_compare_function(Query_9_stats s1, Query_9_stats s2);
char *query_9_get_output(GList *ride_stats, int i);
void query_9_print_line(FILE *file_fp, char *id, Date data, int distance, char *city, double tip);

#endif