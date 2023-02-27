#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <glib.h>

#include "driver.h"
#include "user.h"
#include "ride.h"
#include "../includes/utilities/catalog.h"

#ifndef QUERY3_H
#define QUERY3_H

typedef struct query_3_stats *Query_3_stats;

Query_3_stats new_user_stats();

void free_query_3_stats (void *s);

void query_3_set_user(Query_3_stats stats, char *user);

void query_3_set_user_name(Query_3_stats stats, char *name);

int query_3_get_total_distance(Query_3_stats stats);

char *query_3_get_username(Query_3_stats stats);

char *query_3_get_name(Query_3_stats stats);

Date query_3_get_rides_date(Query_3_stats stats);

void user_update_stats(Query_3_stats stats, int score, int ride_distance, Date ride_date);

void add_user_to_stats_table(user u, GHashTable *users_stats_list);

int query_3_compare_users_distance_function(Query_3_stats s1, Query_3_stats s2);

void query_3_get_query_stats(ride ride, GHashTable *users_distance_list);

void print_query_3_line(FILE *output_fp, char *name, char *username, int distance);

char *query_3_get_output(GList *users_distance_sorted_list, int n, int i);

#endif