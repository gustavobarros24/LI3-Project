#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <glib.h>
#include "driver.h"
#include "user.h"
#include "ride.h"
#include "../includes/utilities/catalog.h"

#ifndef QUERY2_H
#define QUERY2_H

typedef struct query_2_stats *Query_2_stats;

Query_2_stats new_driver_stats();
void free_query_2_stats(void *s);
void query_2_destroy_func(void *query_2_stats);
void query_2_set_name(Query_2_stats stats, char *name);
void query_2_set_id(Query_2_stats stats, char *id);
double query_2_get_total_score(Query_2_stats stats);
int query_2_get_total_rides(Query_2_stats stats);
char *query_2_get_id(Query_2_stats stats);
char *query_2_get_name(Query_2_stats stats);
Date query_2_get_most_recent_ride_date(Query_2_stats stats);
double query_2_medium_driver_score(Query_2_stats stats);
void driver_update_stats(Query_2_stats stats, int score, Date ride_date);
bool add_driver_to_stats_table(driver d, GHashTable *driver_stats_table);
int query_2_compare_drivers_score(Query_2_stats stats1, Query_2_stats stats2);
void query_2_get_query_stats(ride ride, GHashTable *drivers_stats_table);
void print_query_2_line(FILE *file_fp, char *id, char *name, double medium_score);
char *query_2_get_output(GList *drivers_medium_score_sorted_list, int N, int y);

#endif