#include "../../includes/utilities/catalog.h"

/*
typedef struct catalog{
    FILE *file_p;
    GHashTable *hash_table;
    GList *glist;
} *Catalog

Catalog catalog_new(char *fp){
    FILE *file = fopen(fp, "r");
    GHashTable *h_table = g_hash_table_new_full(g_str_hash, g_str_equal, free, free_user);
    GList *list = NULL;

    Catalog catalog = (Catalog) malloc(sizeof(struct catalog));
    if(catalog == NULL){
        perror("unable to allocate catalog\n");
        return 1;
    }

    catalog->file_p = file;
    catalog->hash_table = h_table;
    catalog->glist = list;
    return catalog;
}

FILE *catalog_get_file(Catalog catalog){
    return catalog->file_p;
}
GHashTable *catalog_get_hash_table(Catalog catalog){
    return catalog->hash_table;
}

GList *catalog_get_list(Catalog catalog){
    return catalog->glist;
}

void catalog_list_new_start(Catalog catalog, GList *list){
    catalog->glist = list;
}

void catalog_free(Catalog catalog){
    g_hash_table_destroy(catalog->hash_table);
    g_list_free_full(catalog->glist);
    free(catalog);
}

int catalogs_load(Catalog users, Catalog drivers, Catalog rides, Stats stats){

    GHashTable *users_stats_table = stats_get_users_table(stats);
    GHashTable *drivers_stats_table = stats_get_drivers_table(stats);
    GHashTable *cities_stats_table = stats_get_cities_table(stats);

    size_t buffer_size = 200; 
    char *buffer = (char *) malloc(sizeof(char)*buffer_size);
    if(buffer==NULL){
        perror("unable to allocate buffer\n");
        return 1;
    }
    char *to_free = buffer;

    char **buffer_arrayzed;

    while(fgets(buffer, buffer_size, catalog_get_file(users))){
        buffer_arrayzed = parser(7, buffer);
        if(validate_line(7, buffer_arrayzed)){
            User_stats user_stats_new(buffer_arrayzed[0]);
            g_hash_table_insert(users_stats_table, buffer_arrayzed[0], user_stats_new);
            user user_to_insert = user_new_load(buffer_arrayzed);
            g_hash_table_insert(catalog_get_hash_table(users), get_user_username(user_to_insert), user_to_insert);
            // user temp = g_hash_table_lookup(catalog_get_hash_table(users), "VerPinheiro-Araújo80");
            // if(temp != NULL) {printf("%s", get_user_name(temp)); printf(" %d\n", get_user_status(temp));}
        }
        free(buffer_arrayzed);
    }

    while(fgets(buffer, buffer_size, catalog_get_file(drivers))){
        buffer_arrayzed = parser(9, buffer);
        if(validate_line(9, buffer_arrayzed)){
            Driver_stats driver_stats_new(buffer_arrayzed[0]);
            g_hash_table_insert(drivers_stats_table, buffer_arrayzed[0], driver_stats_new);
            driver driver_to_insert = driver_new_load(buffer_arrayzed);
            g_hash_table_insert(catalog_get_hash_table(drivers), get_driver_id(driver_to_insert), driver_to_insert);
        }
        free(buffer_arrayzed);
    }

    while(fgets(buffer, buffer_size, catalog_get_file(rides))){
        buffer_arrayzed = parser(9, buffer);
        if(validate_line(10, buffer_arrayzed)){
            ride ride_to_insert = ride_new_load(buffer_arrayzed);
            get_stats_from_ride(users_stats_table, drivers_stats_table, cities_stats_table, ride_to_insert);
            catalog_rides_list_new_start(catalog, g_list_prepend(catalog_get_rides_list(catalog), ride_to_insert));
        }
        free(buffer_arrayzed);
    } 

    free(to_free);
    to_free = NULL; 
}




*/



typedef struct catalog{

    FILE *users_fp;
    FILE *drivers_fp;
    FILE *rides_fp;
    FILE *queries_fp;

    GHashTable *users_table;
    GHashTable *drivers_table;
    ride *rides_array;

} *Catalog;

Catalog catalog_new(char *a, char *b, char *c, char *d){
    FILE *users_fp = fopen(a, "r");
    FILE *drivers_fp = fopen(b, "r");
    FILE *rides_fp = fopen(c, "r");
    FILE *queries_fp = fopen(d, "r");

    ride *rides_array = (ride *) malloc(10000000*ride_size());
    GHashTable *users_table = g_hash_table_new_full(g_str_hash, g_str_equal, free, free_user);
    GHashTable *drivers_table = g_hash_table_new_full(g_str_hash, g_str_equal, free, free_driver);

    Catalog catalog = (Catalog) malloc(sizeof(struct catalog));
    catalog->drivers_fp = drivers_fp;
    catalog->rides_fp = rides_fp;
    catalog->users_fp = users_fp;
    catalog->queries_fp = queries_fp;
    catalog->drivers_table = drivers_table;
    catalog->rides_array = rides_array;
    catalog->users_table = users_table;
    return catalog;
}

FILE *catalog_get_users_file(Catalog catalog){
    return catalog->users_fp;
}

FILE *catalog_get_drivers_file(Catalog catalog){
    return catalog->drivers_fp;
}

FILE *catalog_get_rides_file(Catalog catalog){
    return catalog->rides_fp;
}

FILE *catalog_get_queries_file(Catalog catalog){
    return catalog->queries_fp;
}

GHashTable *catalog_get_users_htable(Catalog catalog){
    return catalog->users_table;
}

GHashTable *catalog_get_drivers_htable(Catalog catalog){
    return catalog->drivers_table;
}

ride *catalog_get_rides_array(Catalog catalog){
    return catalog->rides_array;
}

void free_rides_array(ride *array_to_free){
    int i = 0;
    while(i<10000000 && array_to_free[i]){
        free_ride(array_to_free[i]);
        i++;
    }
    free(array_to_free);
}

void catalog_free(Catalog catalog) {

    g_hash_table_destroy(catalog->users_table);
    g_hash_table_destroy(catalog->drivers_table);
    free_rides_array(catalog->rides_array);

    free(catalog);
}

void catalog_load(Catalog catalog){
    
    size_t buffer_size = 200; 
    char *buffer = (char *) malloc(sizeof(char)*buffer_size);
    char *to_free = buffer;

    char **buffer_arrayzed;


    while(fgets(buffer, buffer_size, catalog_get_users_file(catalog))){
        buffer_arrayzed = parser(7, buffer);
        if(validate_line(7, buffer_arrayzed)){
            user user_to_insert = user_new_load(buffer_arrayzed);
            g_hash_table_insert(catalog_get_users_htable(catalog), get_user_username(user_to_insert), user_to_insert);
        }
        free(buffer_arrayzed);
    }

    while(fgets(buffer, buffer_size, catalog_get_drivers_file(catalog))){
        buffer_arrayzed = parser(9, buffer);
        if(validate_line(9, buffer_arrayzed)){
            driver driver_to_insert = driver_new_load(buffer_arrayzed);
            g_hash_table_insert(catalog_get_drivers_htable(catalog), get_driver_id(driver_to_insert), driver_to_insert);
        }
        free(buffer_arrayzed);
    }

    int i = 0;
    while(fgets(buffer, buffer_size, catalog_get_rides_file(catalog))){
        buffer_arrayzed = parser(9, buffer);
        if(validate_line(10, buffer_arrayzed)){
            ride ride_to_insert = ride_new_load(buffer_arrayzed);
            catalog_get_rides_array(catalog)[i] = ride_to_insert;
            i++;
        }
        free(buffer_arrayzed);
    } 

    free(to_free);
    to_free = NULL;  
}