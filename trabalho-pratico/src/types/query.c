#include "../includes/types/query.h"

#define MAXQUERYLENGTH 100

typedef struct query {

    int id;
    char* args[3];

} *Query;

void set_query_id (Query query, int id) {

    query->id = id;

}

int get_query_id (Query query) {

    return query->id;

}

void set_query_arg (Query query, char* arg, int i) {

    query->args[i] = strdup(arg);

}

char* get_query_arg (Query query, int i) {

    return query->args[i];

}

size_t get_query_size () {

    return sizeof(struct query);

}

void free_query (Query query_to_free) { 

    int i = 0;

    while(i < 3 && query_to_free->args[i]){

        free(query_to_free->args[i]);
        i++;
    }
    free(query_to_free);

}

Query query_new_load (char **array) {

    Query new_query = (Query) malloc(sizeof(struct query));
    new_query->id = atoi(array[0]);
    int i = 0;

    for(int j = 0; j < 3; j++) new_query->args[j] = NULL;

    if(new_query->id==6){
        while(i<3){
            set_query_arg(new_query, array[i+1], i);
            i++;
        }
    }
    else if(new_query->id==5 || new_query->id==7 || new_query->id==8 || new_query->id==9){
        while(i<2){
            set_query_arg(new_query, array[i+1], i);
            i++;
        }
    }
    else{
        set_query_arg(new_query, array[i+1], i);
    }
    return new_query;
}