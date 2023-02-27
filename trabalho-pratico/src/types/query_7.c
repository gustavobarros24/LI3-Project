#include "../../includes/types/query_7.h"

typedef struct query_7_stats{
    char *id;
    int total_rides;
    double total_score_acc;
} *Query_7_stats;

Query_7_stats new_query_7_stats(){
    Query_7_stats new_stats = (Query_7_stats) malloc(sizeof(struct query_7_stats));
    new_stats->id = NULL;
    new_stats->total_rides = 0;
    new_stats->total_score_acc = 0;
    return new_stats;
}

void free_query_7_stats(void *to_free){
    Query_7_stats s = (Query_7_stats) to_free;
    free(s->id);
    free(s);
}

char *query_7_get_id(Query_7_stats s1){
    return strdup(s1->id);
}

void query_7_set_id(Query_7_stats s1, char *id){
    s1->id = strdup(id);
}

int query_7_get_total_rides(Query_7_stats s1){
    return s1->total_rides;
}

double query_7_get_total_score_acc(Query_7_stats s1){
    return s1->total_score_acc;
}

void query_7_add_driver_to_stats_table(driver d, GHashTable *drivers_stats_table){
    if(get_driver_status(d)){
        Query_7_stats new_stats = new_query_7_stats();
        query_7_set_id(new_stats, get_driver_id(d));
        g_hash_table_insert(drivers_stats_table, query_7_get_id(new_stats), new_stats); 
    }
}

void query_7_update_driver_stats(GHashTable *stats_table, ride r){
    Query_7_stats stats = g_hash_table_lookup(stats_table, get_ride_driver_id(r));
    if(stats){
        stats->total_score_acc += get_ride_score_driver(r);
        stats->total_rides++;
    }
}

int query_7_compare_function(Query_7_stats s1, Query_7_stats s2){
    int a1 = query_7_get_total_rides(s1);
    int a2 = query_7_get_total_rides(s2);
    if(a1==0) return 1;
    else if(a2==0) return -1;
    double medium_score_s1 = query_7_get_total_score_acc(s1)/a1;
    double medium_score_s2 = query_7_get_total_score_acc(s2)/a2;
    char *id_s1 = query_7_get_id(s1);
    char *id_s2 = query_7_get_id(s2);
    if(medium_score_s1>medium_score_s2) return -1;
    else if(medium_score_s1<medium_score_s2) return 1;
    else{
        if(atoi(id_s1)>atoi(id_s2)){
            free(id_s1); free(id_s2);
            return -1;
        }
        else{
            free(id_s1); free(id_s2);
            return 1;
        }
    }
}

void query_7_print_line(FILE *file_fp, char *id, char *name, double medium_score){
    fprintf(file_fp, "%s;%s;%.3f\n", id, name, medium_score);
}

char *query_7_get_output(GList *sorted_list, int n, int i, Catalog catalog){
    char *filename = (char *) malloc(100);
    i++;
    sprintf(filename, "Resultados/command%d_output.txt", i);
    FILE *output_fp = fopen(filename, "w");
    if(!output_fp){
        printf("error opening file\n"); 
        exit(1);
    }
    int j = 0;
    Query_7_stats stats = g_list_nth_data(sorted_list, j);
    if(query_7_get_total_rides(stats)==0){
        return NULL;
    };
    while(j<n){
        char *id = query_7_get_id(stats);
        char *name = get_driver_name(g_hash_table_lookup(catalog_get_drivers_htable(catalog), id));
        double medium_score = query_7_get_total_score_acc(stats)/query_7_get_total_rides(stats);
        query_7_print_line(output_fp, id, name, medium_score);
        j++;
        stats = g_list_nth_data(sorted_list, j);
    }
    fclose(output_fp);

    return filename;
}