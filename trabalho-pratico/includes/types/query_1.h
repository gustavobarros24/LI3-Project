#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <glib.h>

#ifndef QUERY1_H
#define QUERY1_H

#include "driver.h"
#include "user.h"
#include "ride.h"
#include "date.h"
#include "../utilities/catalog.h"

typedef struct query_1_stats *Query_1_stats;

void free_query_1_stats(Query_1_stats s);
int query_1_get_total_distance(Query_1_stats stats);
double query_1_get_total_money(Query_1_stats stats);
char *query_1_get_entity(Query_1_stats stats);
int query_1_get_total_score(Query_1_stats stats);
int query_1_get_total_rides(Query_1_stats stats);

void query_1_total_distance_inc(Query_1_stats stats, int to_add);
void query_1_total_money_inc(Query_1_stats stats, double to_add);
void query_1_total_score_inc(Query_1_stats stats, int to_add);
void query_1_total_rides_inc(Query_1_stats stats);
void query_1_new_entity(Query_1_stats stats, char *entity);
Query_1_stats query_1_stats_new();
double calculate_total_spent_on_ride(Catalog catalog, ride ride);
Query_1_stats query_1_get_user_stats_from_rides(Catalog catalog, ride ride, Query_1_stats stats);
Query_1_stats query_1_get_driver_stats_from_rides(Catalog catalog, ride ride, Query_1_stats stats);
char *query_1_output_user(Catalog catalog, Query_1_stats stats, int i);
char *query_1_output_driver(Catalog catalog, Query_1_stats stats, int i);
char *query_1_inactive_output(int i);

#endif




