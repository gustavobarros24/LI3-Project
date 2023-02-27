#include "../../includes/types/query_2.h"

typedef struct query_2_stats{
    char *id;
    char *name;
    double total_score;
    Date most_recent_ride_date;
    int total_rides;
} *Query_2_stats;

Query_2_stats new_driver_stats(){
    Query_2_stats new_driver_stats = (Query_2_stats) malloc(sizeof(struct query_2_stats));
    new_driver_stats -> most_recent_ride_date = NULL;
    new_driver_stats -> name = NULL;
    new_driver_stats -> total_score = 0;
    new_driver_stats -> id = NULL;
    new_driver_stats -> total_rides = 0;
    return new_driver_stats;
}

void free_query_2_stats(void *s){

    Query_2_stats driver_to_free = (Query_2_stats) s;
    free(driver_to_free->name);
    free(driver_to_free->id);
    free(driver_to_free);
}

void query_2_destroy_func(void *query_2_stats){
    Query_2_stats query_to_free = (Query_2_stats) query_2_stats;
    free(query_to_free);
}


void query_2_set_name(Query_2_stats stats, char *name){
    stats->name = strdup(name);
}

void query_2_set_id(Query_2_stats stats, char *id){
    stats->id = strdup(id);
}

double query_2_get_total_score(Query_2_stats stats){
    return stats -> total_score;
}

int query_2_get_total_rides(Query_2_stats stats){
    return stats -> total_rides;
}

char *query_2_get_id(Query_2_stats stats){
    return strdup(stats->id);
}

char *query_2_get_name(Query_2_stats stats){
    return strdup(stats->name);
}

Date query_2_get_most_recent_ride_date(Query_2_stats stats){
    return stats -> most_recent_ride_date;
}

//função que calcula o medium_score
double query_2_medium_driver_score(Query_2_stats stats){
    if(stats->total_rides==0) return 0;
    else return (stats->total_score)/(stats->total_rides);
}

//função para dar updates aos stats de um driver
void driver_update_stats(Query_2_stats stats, int score, Date ride_date){
    stats -> total_score += score;
    stats -> total_rides++;
    if(stats->most_recent_ride_date == NULL) stats->most_recent_ride_date = ride_date;
    else if (date_compare(ride_date, stats -> most_recent_ride_date) == -1){
        stats -> most_recent_ride_date = ride_date;
    }
}

//função para adicionar os stats de um driver
bool add_driver_to_stats_table(driver d, GHashTable *driver_stats_table){
    if(get_driver_status(d) == true){
        Query_2_stats new_driver_to_add = new_driver_stats();
        query_2_set_id(new_driver_to_add, get_driver_id(d));
        query_2_set_name(new_driver_to_add, get_driver_name(d));
        g_hash_table_insert(driver_stats_table, get_driver_id(d), new_driver_to_add);
        return true;
    }
    else return false;
}

//função usada para comparar os elementos seguindo as instruções da query
int query_2_compare_drivers_score(Query_2_stats stats1, Query_2_stats stats2){
    double medium_score1 = query_2_medium_driver_score(stats1);
    double medium_score2 = query_2_medium_driver_score(stats2);
    if(medium_score1 > medium_score2){
        return -1;
    }
    else if(medium_score1 < medium_score2){
        return 1;
    }
    else{
        int date_comparation = date_compare(query_2_get_most_recent_ride_date(stats1), query_2_get_most_recent_ride_date(stats2));
        if(date_comparation!=0) return date_comparation;
        else{
            int id1 = atoi(query_2_get_id(stats1));
            int id2 = atoi(query_2_get_id(stats2));
            if(id1 > id2){
                return 1;
            }
            else{
                return -1;
            }
        }
    }
}

//função permite obter as stats da query
void query_2_get_query_stats(ride ride, GHashTable *drivers_stats_table){
    Date ride_date = get_ride_date(ride);
    char *driver_id = get_ride_driver_id(ride);
    int ride_score = get_ride_score_driver(ride);
    Query_2_stats stats = g_hash_table_lookup(drivers_stats_table, driver_id);
    if(stats){
        driver_update_stats(stats, ride_score, ride_date);
    }
    free(driver_id);
}

//função imprime num file o output de (id;nome;avaliação média)
void print_query_2_line(FILE *file_fp, char *id, char *name, double medium_score){
    fprintf(file_fp, "%s;%s;%.3f\n", id, name, medium_score);
}

//função imprime num file várias linhas do output de (id;nome;avaliação média)
char *query_2_get_output(GList *drivers_medium_score_sorted_list, int N, int y){
    char *filename = (char *) malloc(100);
    y++;
    sprintf(filename, "Resultados/command%d_output.txt", y);
    FILE *output_fp = fopen(filename, "w");
    if(!output_fp){
        printf("error opening file\n");
        exit(1);
    }
    int k = 0;
    Query_2_stats stats = g_list_nth_data(drivers_medium_score_sorted_list, k);
    while(k<N){
        double medium_score = query_2_medium_driver_score(stats);
        char *id = query_2_get_id(stats);
        char *name = query_2_get_name(stats);
        print_query_2_line(output_fp, id, name, medium_score);
        k++;
        stats = g_list_nth_data(drivers_medium_score_sorted_list, k);
        if(stats == NULL) perror("null data\n");
    }
    fclose(output_fp);
    return filename;
}