#include <glib.h>

#ifndef STATS_H
#define STATS_H

#include "../types/date.h"
#include "../types/ride.h"

typedef struct stats *Stats;

typedef struct user_stats *User_stats;

typedef struct driver_stats *Driver_stats;

typedef struct city_stats *City_stats;

User_stats stats_user_new(char *username);
void free_user_stats(void *user_stats);

Driver_stats stats_driver_new(char *id);
void free_driver_stats(void *driver_stats);

City_stats stats_city_new(char *city);
void free_city_stats(void *city_stats);

GHashTable *stats_get_users_table(Stats stats);
GHashTable *stats_get_drivers_table(Stats stats);
GHashTable *stats_get_cities_table(Stats stats);

Stats stats_new();
void free_stats(Stats stats);

#endif