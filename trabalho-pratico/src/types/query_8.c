#include "../../includes/types/query_8.h"

typedef struct query_8_stats{
    char *idride;
    char *iddriver;
    char *username;
    Date d;
    Date u;
} *Query_8_stats;

Query_8_stats query_8_stats_new(char *driver_id, char *username, char *ride_id, Date u1, Date d2){
    Query_8_stats new_stats = (Query_8_stats) malloc(sizeof(struct query_8_stats));
    new_stats->iddriver = strdup(driver_id);
    new_stats->idride = strdup(ride_id);
    new_stats->username = strdup(username);
    new_stats->d = d2;
    new_stats->u = u1;
    return new_stats;
}

void free_query_8_stats(void *to_free){
    Query_8_stats s = (Query_8_stats) to_free;
    free(s->idride);
    free(s->iddriver);
    free(s->username);
    free(s);
}

//função usada para comparar os elementos seguindo as instruções da query
int query_8_compare_function(Query_8_stats s1, Query_8_stats s2){
    int date_compare_result = date_compare(s1->d, s2->d);
    if(date_compare_result == 1) return -1;
    else if(date_compare_result == -1) return 1;
    else{
        date_compare_result = date_compare(s1->u, s2->u);
        if(date_compare_result == 1) return -1;
        else if(date_compare_result == -1) return 1;
        else{
            if(atoi(s1->idride)>atoi(s2->idride)) return 1;
            else return -1;
        }
    }
}

//função imprime num file o output de (id;driver_name;username;user_name)
void query_8_print_line(FILE *file_fp, char *id, char*d_name, char *username, char *u_name){
    fprintf(file_fp, "%s;%s;%s;%s\n", id, d_name, username, u_name);
}

//função imprime num file várias linhas do output de (id;driver_name;username;user_name)
char *query_8_get_output(Catalog catalog, GList *stats, int i){
    char *filename = (char *) malloc(100);
    i++;
    sprintf(filename, "Resultados/command%d_output.txt", i);
    FILE *output_fp = fopen(filename, "w");
    if(!output_fp){
        printf("error opening file\n");
        exit(1);
    }
    while(stats){
        GHashTable *users_table = catalog_get_users_htable(catalog);
        GHashTable *drivers_table = catalog_get_drivers_htable(catalog);
        Query_8_stats q8 = stats->data;
        char *username = q8->username;
        char *driver_id = q8->iddriver;

        query_8_print_line(output_fp, driver_id, get_driver_name(g_hash_table_lookup(drivers_table, driver_id)), username, get_user_name(g_hash_table_lookup(users_table, username)));
        stats = stats -> next;
    }
    fclose(output_fp);

    return filename;
}