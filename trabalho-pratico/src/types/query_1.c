#include "../../includes/types/query_1.h"

typedef struct query_1_stats{
    char *entity;
    int total_distance;
    double total_money;
    int total_score;
    int total_rides;
} *Query_1_stats;

int query_1_get_total_distance(Query_1_stats stats){
    return stats->total_distance;
}

double query_1_get_total_money(Query_1_stats stats){
    return stats->total_money;
}
    
char *query_1_get_entity(Query_1_stats stats){
    return strdup(stats->entity);
}

int query_1_get_total_score(Query_1_stats stats){
    return stats->total_score;
}

int query_1_get_total_rides(Query_1_stats stats){
    return stats->total_rides;
}

void query_1_total_distance_inc(Query_1_stats stats, int to_add){
    stats->total_distance += to_add;
}

void query_1_total_money_inc(Query_1_stats stats, double to_add){
    stats->total_money += to_add;
}

void query_1_total_score_inc(Query_1_stats stats, int to_add){
    stats->total_score += to_add;
}

void query_1_total_rides_inc(Query_1_stats stats){
    stats->total_rides++;
}

void query_1_new_entity(Query_1_stats stats, char *entity){
    stats->entity = strdup(entity);
}

Query_1_stats query_1_stats_new(){
    Query_1_stats stats = (Query_1_stats) malloc (sizeof(struct query_1_stats));
    stats->total_distance = 0;
    stats->total_money = 0;
    stats->total_rides = 0;
    stats->total_score = 0;
    stats->entity = NULL;
    return stats;
}

void free_query_1_stats(Query_1_stats s){
    free(s->entity);
    free(s);
}

double calculate_total_spent_on_ride(Catalog catalog, ride ride){
    GHashTable *drivers_table = catalog_get_drivers_htable(catalog);
    driver ride_driver = g_hash_table_lookup(drivers_table, get_ride_driver_id(ride));
    int distance = get_ride_distance(ride);
    Car_class car_class = get_driver_carclass(ride_driver);
    double result = get_ride_tip(ride);
    if(car_class==0){
        result += 3.25;
        result += 0.62*distance;
        return result;
    }
    else if(car_class==1){
        result += 4;
        result += 0.79*distance;
        return result;
    }
    else{
        result += 5.2;
        result += 0.94*distance;
        return result;
    }
}

Query_1_stats query_1_get_user_stats_from_rides(Catalog catalog, ride ride, Query_1_stats stats){
    char *entity = query_1_get_entity(stats);
    char *ride_username = get_ride_user_username(ride);
    if(!strcmp(ride_username, entity)){
        query_1_total_distance_inc(stats, get_ride_distance(ride));
        query_1_total_money_inc(stats, calculate_total_spent_on_ride(catalog, ride));
        query_1_total_score_inc(stats, get_ride_score_user(ride));
        query_1_total_rides_inc(stats);
    }
    return stats;
}

Query_1_stats query_1_get_driver_stats_from_rides(Catalog catalog, ride ride, Query_1_stats stats){
    char *entity = query_1_get_entity(stats);
    char *ride_driver_id = get_ride_driver_id(ride);
    if(!strcmp(ride_driver_id, entity)){
        query_1_total_distance_inc(stats, get_ride_distance(ride));
        query_1_total_money_inc(stats, calculate_total_spent_on_ride(catalog, ride));
        query_1_total_score_inc(stats, get_ride_score_driver(ride));
        query_1_total_rides_inc(stats);
    }
    return stats;
}

char *query_1_output_user(Catalog catalog, Query_1_stats stats, int i){
    char *filename = (char *) malloc(100);
    i++;
    char *username = query_1_get_entity(stats);
    user u = g_hash_table_lookup(catalog_get_users_htable(catalog), username);
    char *name = get_user_name(u);
    char gender = get_user_gender(u);
    int age = get_age(get_user_birthday(u));
    int total_rides = query_1_get_total_rides(stats);
    double total_score = query_1_get_total_score(stats);
    double medium_score = total_score/total_rides;
    double total_spent = query_1_get_total_money(stats);

    sprintf(filename, "Resultados/command%d_output.txt", i);
    FILE *output_fp = fopen(filename, "w");
    fprintf(output_fp, "%s;%c;%d;%.3f;%d;%.3f\n", name, gender, age, medium_score, total_rides, total_spent);
    fclose(output_fp);

    free(username);
    free(name);

    return filename;
    
}

char *query_1_output_driver(Catalog catalog, Query_1_stats stats, int i){
    char *filename = (char *) malloc(100);
    i++;
    char *driver_id = query_1_get_entity(stats);
    driver d = g_hash_table_lookup(catalog_get_drivers_htable(catalog), driver_id);
    char *name = get_driver_name(d);
    char gender = get_driver_gender(d);
    Date birthday = get_driver_birthday(d);
    int age = get_age(birthday);
    int total_rides = query_1_get_total_rides(stats);
    double total_score = query_1_get_total_score(stats);
    double medium_score = total_score/total_rides;
    double total_spent = query_1_get_total_money(stats);

    sprintf(filename, "Resultados/command%d_output.txt", i);
    FILE *output_fp = fopen(filename, "w");
    fprintf(output_fp, "%s;%c;%d;%.3f;%d;%.3f\n", name, gender, age, medium_score, total_rides, total_spent);
    fclose(output_fp);

    return filename;
}

char *query_1_inactive_output(int i){
    char *filename = (char *) malloc(100);
    i++;
    sprintf(filename, "Resultados/command%d_output.txt", i);
    FILE *output_fp = fopen(filename, "w");

    return filename;
}