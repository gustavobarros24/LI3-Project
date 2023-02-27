#include "../../includes/types/query_3.h"

#define MAXLINELENGTH 150

typedef struct query_3_stats{
    char *name;
    char *username;
    int total_distance;
    Date most_recent_date;
    double total_score;
    int total_rides;
} *Query_3_stats;

Query_3_stats new_user_stats(){
    Query_3_stats new_user_stats = (Query_3_stats) malloc(sizeof(struct query_3_stats));
    new_user_stats->most_recent_date = NULL;
    new_user_stats->username = NULL;
    new_user_stats->name = NULL;
    new_user_stats->total_distance = 0;
    new_user_stats->total_score = 0;
    new_user_stats->total_rides = 0;
    return new_user_stats;
}

void free_query_3_stats (void *s){
    Query_3_stats to_free = (Query_3_stats) s;
    free(to_free->username);
    free(to_free->name);
    free(to_free);
}

void query_3_set_user(Query_3_stats stats, char *user){
    stats->username = strdup(user);
}

void query_3_set_user_name(Query_3_stats stats, char *name){
    stats->name = strdup(name);
}

int query_3_get_total_distance(Query_3_stats stats){
    return stats->total_distance;
}

char *query_3_get_username(Query_3_stats stats){
    return strdup(stats->username);
}

char *query_3_get_name(Query_3_stats stats){
    return strdup(stats->name);
}

Date query_3_get_most_recent_date(Query_3_stats stats){
    return stats->most_recent_date;
}

double query_3_medium_score (Query_3_stats stats) {
    if(stats->total_rides==0) return 0;
    else return (stats->total_score)/(stats->total_rides);
}

void user_update_stats(Query_3_stats stats, int score, int ride_distance, Date ride_date){
    stats->total_distance += ride_distance;
    stats->total_score += score;
    stats->total_rides++;
    if(stats->most_recent_date == NULL) stats->most_recent_date = ride_date;
    else if (date_compare(ride_date, stats -> most_recent_date) == -1){
        stats -> most_recent_date = ride_date;
    }
}

void add_user_to_stats_table(user u, GHashTable *users_stats_table){
    if(get_user_status(u)){
        Query_3_stats new_user_to_add = new_user_stats();
        query_3_set_user(new_user_to_add, get_user_username(u));
        query_3_set_user_name(new_user_to_add, get_user_name(u));
        g_hash_table_insert(users_stats_table, query_3_get_username(new_user_to_add), new_user_to_add); 
    }
}

int query_3_compare_users_distance_function(Query_3_stats s1, Query_3_stats s2){

    if (query_3_get_total_distance(s1) > query_3_get_total_distance(s2)) return -1;

    else if (query_3_get_total_distance(s1) < query_3_get_total_distance(s2)) return 1;

    else{

        int date_comparation = date_compare(query_3_get_most_recent_date(s1), query_3_get_most_recent_date(s2));
        if (date_comparation != 0) return date_comparation;
        else {
            char *username1 = query_3_get_username(s1), *username2 = query_3_get_username(s2);
            if (strcmp(username1, username2)<0) return -1;
            else return 1;
        }
    }
}

void query_3_get_query_stats(ride ride, GHashTable *users_stats_table){
    Date ride_date = get_ride_date(ride);
    char *ride_username = get_ride_user_username(ride);
    int ride_distance = get_ride_distance(ride);
    int ride_score = get_ride_score_user(ride);
    Query_3_stats temp_stats = g_hash_table_lookup(users_stats_table, ride_username);
    if(temp_stats){
        user_update_stats(temp_stats, ride_score, ride_distance, ride_date);
    }
    free(ride_username);
}

//função que imprime no file uma linha de (username;name;distancia_viajada)
void print_query_3_line(FILE *file_fp, char *name, char *username, int distance){
    fprintf(file_fp, "%s;%s;%d\n", name, username, distance);
}

char* query_3_get_output(GList *users_distance_sorted_list, int n, int i){
    char *filename = (char *) malloc(100);
    i++;
    sprintf(filename, "Resultados/command%d_output.txt", i);
    FILE *output_fp = fopen(filename, "w");
    if(!output_fp){
        printf("error opening file\n"); 
        exit(1);
    }
    int j = 0;
    Query_3_stats stats = g_list_nth_data(users_distance_sorted_list, j);
    while(j<n){
        int d = query_3_get_total_distance(stats);
        char *username = query_3_get_username(stats);
        char *name = query_3_get_name(stats);
        print_query_3_line(output_fp, username, name, d);
        j++;
        stats = g_list_nth_data(users_distance_sorted_list, j);
    }
    fclose(output_fp);

    return filename;
}