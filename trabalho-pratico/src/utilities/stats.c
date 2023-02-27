#include "../../includes/utilities/stats.h"

typedef struct stats{
    GHashTable *users_stats_table;
    GHashTable *drivers_stats_table;
    GHashTable *cities_stats_table;
} *Stats;

typedef struct user_stats{
    char *username;
    double total_score;
    double total_money_spent;
    int total_rides;
    int total_distance;
    Date last_ride_date;
} *User_stats;

typedef struct driver_stats{
    char *id;
    double total_score;
    double total_money_won;
    int total_rides;
    int total_distance;
    Date last_ride_date;
} *Driver_stats;

typedef struct city_stats{
    char *city;
    double total_money;
    int total_rides;
} *City_stats;


User_stats stats_user_new(char *username){
    User_stats new_user_stats = (User_stats) malloc(sizeof(struct user_stats));
    if(new_user_stats == NULL){
        perror("unable to allocate user stats");
        exit(1);
    }
    new_user_stats->username = strdup(username);
    new_user_stats->total_distance = 0;
    new_user_stats->total_money_spent = 0;
    new_user_stats->total_rides = 0;
    new_user_stats->total_score = 0;
    new_user_stats->last_ride_date = NULL;

    return new_user_stats;
}

void free_user_stats(void *user_stats){
    User_stats user_stats_to_free = (User_stats) user_stats;

    free(user_stats_to_free->username);   
    free(user_stats_to_free->last_ride_date); 
    free(user_stats_to_free);
}


Driver_stats stats_driver_new(char *id){
    Driver_stats new_driver_stats = (Driver_stats) malloc(sizeof(struct driver_stats));
    if(new_driver_stats == NULL){
        perror("unable to allocate driver stats");
        exit(1);
    }
    new_driver_stats->id = strdup(id);
    new_driver_stats->total_distance = 0;
    new_driver_stats->total_money_won = 0;
    new_driver_stats->total_rides = 0;
    new_driver_stats->total_score = 0;
    new_driver_stats->last_ride_date = NULL;

    return new_driver_stats;
}

void free_driver_stats(void *driver_stats){
    Driver_stats driver_stats_to_free = (Driver_stats) driver_stats;

    free(driver_stats_to_free->id);   
    free(driver_stats_to_free->last_ride_date); 
    free(driver_stats_to_free);
}


City_stats stats_city_new(char *city){
    City_stats new_city_stats = (City_stats) malloc(sizeof(struct city_stats));
    if(new_city_stats == NULL){
        perror("unable to allocate driver stats");
        exit(1);
    }
    new_city_stats->city = strdup(city);
    new_city_stats->total_money = 0;
    new_city_stats->total_rides = 0;

    return new_city_stats;
}

void free_city_stats(void *city_stats){
    City_stats city_stats_to_free = (City_stats) city_stats;

    free(city_stats_to_free->city);   
    free(city_stats_to_free);
}



GHashTable *stats_get_users_table(Stats stats){
    return stats->users_stats_table;
}

GHashTable *stats_get_drivers_table(Stats stats){
    return stats->drivers_stats_table;
}

GHashTable *stats_get_cities_table(Stats stats){
    return stats->cities_stats_table;
}



Stats stats_new(){
    GHashTable *users_table = g_hash_table_new_full(g_str_hash, g_str_equal, free, free_user_stats);
    GHashTable *drivers_table = g_hash_table_new_full(g_str_hash, g_str_equal, free, free_driver_stats);
    GHashTable *cities_table = g_hash_table_new_full(g_str_hash, g_str_equal, free, free_city_stats);

    Stats stats = (Stats) malloc(sizeof(struct stats));
    if(stats==NULL){
        perror("unable to allocate stats struct\n");
        exit(1);
    }

    stats->users_stats_table = users_table;
    stats->drivers_stats_table = drivers_table;
    stats->cities_stats_table = cities_table;
    return stats;
}

void free_stats(Stats stats){
    g_hash_table_destroy(stats->users_stats_table);
    g_hash_table_destroy(stats->drivers_stats_table);
    g_hash_table_destroy(stats->cities_stats_table);
    free(stats);
}




void get_stats_from_ride(GHashTable *users, GHashTable *drivers, GHashTable *cities, ride ride){
    int distance = get_ride_distance(ride);
    User_stats user = g_hash_table_lookup(users, get_ride_user_username(ride));
    user->total_distance += distance;
    user->total_money_spent +=
}