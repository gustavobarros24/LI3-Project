#include "../../includes/types/query_9.h"

typedef struct query_9_stats{
    char *id;
    Date date;
    short int distance;
    char *city;
    double tip;
} *Query_9_stats;

Query_9_stats new_querie_9_stats(){
    Query_9_stats new_stats = (Query_9_stats) malloc(sizeof(struct query_9_stats));
    new_stats -> id = NULL;
    new_stats -> date = NULL;
    new_stats -> distance = 0;
    new_stats -> city = NULL;
    new_stats -> tip = 0;
    return new_stats;
}

void free_query_9_stats(void *to_free){
    Query_9_stats s = (Query_9_stats) to_free;
    free(s->id);
    free(s->city);
    free(s);
}

//função para adicionar os stats de uma ride
Query_9_stats query_9_add_ride_to_stats_list(ride d){
    Query_9_stats new_ride_to_add = new_querie_9_stats();
    new_ride_to_add->id = get_ride_id(d);
    new_ride_to_add->date = get_ride_date(d);
    new_ride_to_add->distance = get_ride_distance(d);
    new_ride_to_add->city = get_ride_city(d);
    new_ride_to_add->tip = get_ride_tip(d);
    return new_ride_to_add;
}

//função usada para comparar os elementos seguindo as instruções da query
int query_9_compare_function(Query_9_stats s1, Query_9_stats s2){
    int distance1 = s1->distance;
    int distance2 = s2->distance;
    if(distance1 > distance2){
        return -1;
    }
    else if(distance1 < distance2){
        return 1;
    }
    else{
        int date_comparation = date_compare(s1->date, s2->date);
        if(date_comparation!=0){
            return date_comparation;
        }
        else{
            int id1 = atoi(s1->id);
            int id2 = atoi(s2->id);
            if(id1 > id2){
                return -1;
            }
            else{
                return 1;
            }
        }
    } 
}

//função imprime num file o output de (id;data;distância;cidade;tip)
void query_9_print_line(FILE *file_fp, char *id, Date date, int distance, char *city, double tip){
    fprintf(file_fp, "%s;%d/%d/%d;%d;%s;%.3f\n", id, date_get_day(date), date_get_month(date), date_get_year(date), distance, city, tip);
}

//função imprime num file várias linhas do output de (id;data;distância;cidade;tip)
char *query_9_get_output(GList *ride_stats, int i){
    char *filename = (char *) malloc(100);
    i++;
    sprintf(filename, "Resultados/command%d_output.txt", i);
    FILE *output_fp = fopen(filename, "w");
    if(!output_fp){
        printf("error opening file\n");
        exit(1);
    }
    while(ride_stats){
        Query_9_stats q9 = ride_stats->data;
        char *id = q9->id;
        Date data = q9->date;
        int distance = q9->distance;
        char *city = q9->city;
        double tip = q9->tip;
        query_9_print_line(output_fp, id, data, distance, city, tip);
        ride_stats = ride_stats -> next;
    }
    fclose(output_fp);

    return filename;
}