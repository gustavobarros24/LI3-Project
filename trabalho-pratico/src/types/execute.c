#include "../../includes/types/execute.h"

char* execute_query (Catalog catalog, Query query, int i) {
    char *filename = NULL;
    int id = get_query_id(query);
    if(id == 1){
        Query_1_stats stats = query_1_stats_new();
        char *entity = get_query_arg(query, 0); 
        query_1_new_entity(stats, entity);
        ride *rides_array = catalog_get_rides_array(catalog);
        int j = 0;
        if(isalpha(entity[0])){
            if(g_hash_table_lookup(catalog_get_users_htable(catalog), entity) == NULL || !get_user_status(g_hash_table_lookup(catalog_get_users_htable(catalog), entity))){
                filename = query_1_inactive_output(i);
            }
            else{
                while(rides_array[j]){
                    stats = query_1_get_user_stats_from_rides(catalog, rides_array[j], stats);
                    j++;
                }
                filename = query_1_output_user(catalog, stats, i);
            }
        }
        else{
            if(g_hash_table_lookup(catalog_get_drivers_htable(catalog), entity) == NULL || !get_driver_status(g_hash_table_lookup(catalog_get_drivers_htable(catalog), entity))){
                filename = query_1_inactive_output(i);
            }
            else{
                while(rides_array[j]){
                    stats = query_1_get_driver_stats_from_rides(catalog, rides_array[j], stats);
                    j++;
                }
                filename = query_1_output_driver(catalog, stats, i);
            }
        }
        free_query_1_stats(stats);
    }

    if(id == 2){
        GHashTable *drivers_stats_table = g_hash_table_new(g_str_hash, g_str_equal);
        ride *rides_array = catalog_get_rides_array(catalog);
        GHashTable *drivers_table = catalog_get_drivers_htable(catalog);
        GList *temp = g_hash_table_get_values(drivers_table);
        while(temp){
            add_driver_to_stats_table(temp->data, drivers_stats_table);
            temp = temp->next;
        }
        g_list_free_full(temp, free_driver);
        int j = 0;
        while(rides_array[j]){
            query_2_get_query_stats(rides_array[j], drivers_stats_table);
            j++;
        }

        temp = g_hash_table_get_values(drivers_stats_table);
        temp = g_list_sort(temp, (GCompareFunc) query_2_compare_drivers_score);
        filename = query_2_get_output(temp, atoi(get_query_arg(query, 0)), i);
        g_list_free_full(temp, free_query_2_stats);
    }
    
    if(id == 3){
        GHashTable *users_stats_table = g_hash_table_new(g_str_hash, g_str_equal);
        ride *rides_array = catalog_get_rides_array(catalog);
        GHashTable *users_table = catalog_get_users_htable(catalog);
        GList *temp = g_hash_table_get_values(users_table);
        while(temp){
            if(get_user_status(temp->data)){
                add_user_to_stats_table(temp->data, users_stats_table);
            }
            temp = temp->next;
        }
        g_list_free_full(temp, free_user);
        int j = 0;
        while(rides_array[j]){
            query_3_get_query_stats(rides_array[j], users_stats_table);
            j++;
        }
        temp = g_hash_table_get_values(users_stats_table);
        temp = g_list_sort(temp, (GCompareFunc) query_3_compare_users_distance_function);
        filename = query_3_get_output(temp, atoi(get_query_arg(query, 0)), i);
        g_list_free_full(temp, free_query_3_stats);
    }
    if(id == 4){
        ride *rides_array = catalog_get_rides_array(catalog);
        int totalrides = 0;
        double totalmoney = 0;
        int j = 0;
        while(rides_array[j]){
            ride rideaux = rides_array[j];
            char* ridecity = get_ride_city(rideaux);
            if(strcmp(get_query_arg(query, 0),ridecity) == 0){
                totalrides++;
                totalmoney = totalmoney + calculate_total_price_of_ride(catalog, rideaux);
            }
            j++;
        }
        filename = query_4_get_output(totalrides, totalmoney, i);
    }
    if(id == 5){
        ride *rides_array = catalog_get_rides_array(catalog);
        int total_rides = 0;
        double total_money = 0;
        int j = 0;
        while(rides_array[j]){
            ride ride_c = rides_array[j];
            Date ride_date = get_ride_date(ride_c);
            if(date_compare(ride_date, str_to_date(get_query_arg(query, 0))) <= 0 && date_compare(ride_date, str_to_date(get_query_arg(query, 1))) >=0){
                total_rides++;
                total_money += calculate_total_price_of_ride(catalog, ride_c);
            }
            j++;
        }
        filename = query_5_get_output(total_rides, total_money, i);
    }

    if(id == 6){
        ride *rides_array = catalog_get_rides_array(catalog);
        int total_rides = 0;
        int total_distance = 0;
        int j = 0;
        while(rides_array[j]){
            ride ride_c = rides_array[j];
            Date ride_date = get_ride_date(ride_c);
            if(date_compare(ride_date, str_to_date(get_query_arg(query, 1))) <= 0 && date_compare(ride_date, str_to_date(get_query_arg(query, 2))) >=0 && strcmp(get_ride_city(ride_c), get_query_arg(query, 0)) == 0){
                total_rides++;
                total_distance += get_ride_distance(ride_c);
            }
            j++;
        }
        filename = query_6_get_output(total_rides, total_distance, i);
    }
    if(id == 7){
        GHashTable *drivers_stats_table = g_hash_table_new(g_str_hash, g_str_equal);
        GHashTable *drivers_h_table = catalog_get_drivers_htable(catalog);
        ride *rides_array = catalog_get_rides_array(catalog);
        GList *temp = g_hash_table_get_values(drivers_h_table);
        while(temp){
            query_7_add_driver_to_stats_table(temp->data, drivers_stats_table);
            temp = temp->next;
        }
        g_list_free_full(temp, free_driver);
        int j = 0;
        while(rides_array[j]){
            ride tmp_r = rides_array[j];
            if(strcmp(get_ride_city(tmp_r), get_query_arg(query, 1))==0){
                query_7_update_driver_stats(drivers_stats_table, tmp_r);
            }
            j++;
        }
        temp = g_hash_table_get_values(drivers_stats_table);
        temp = g_list_sort(temp, (GCompareFunc) query_7_compare_function);
        filename = query_7_get_output(temp, atoi(get_query_arg(query, 0)), i, catalog);
        g_list_free_full(temp, free_query_7_stats);
    }
    if(id == 8){
        ride *rides_array = catalog_get_rides_array(catalog);
        GHashTable *drivers_table = catalog_get_drivers_htable(catalog);
        GHashTable *users_table = catalog_get_users_htable(catalog);
        int j = 0;
        GList *stats = NULL;
        while(rides_array[j]){
            ride r = rides_array[j];
            char *gender = get_query_arg(query, 0);
            char *username = get_ride_user_username(r);
            char *driver_id = get_ride_driver_id(r);
            char driver_gender = get_driver_gender(g_hash_table_lookup(drivers_table, driver_id));
            char user_gender = get_user_gender(g_hash_table_lookup(users_table, username));
            Date d1 = get_user_account_date_creation(g_hash_table_lookup(users_table, username));
            Date d2 = get_driver_accountcreation(g_hash_table_lookup(drivers_table, driver_id));
            short int user_account_age = get_age(d1);
            short int driver_account_age = get_age(d2);
            char *ride_id = get_ride_id(r);
            bool driverstatus = get_driver_status(g_hash_table_lookup(drivers_table, driver_id));
            bool userstatus = get_user_status(g_hash_table_lookup(users_table, username));

            char *query_age = get_query_arg(query, 1);
            if(gender[0] == driver_gender && gender[0] == user_gender && user_account_age >= atoi(query_age) && driver_account_age >= atoi(query_age) && (userstatus == true) && (driverstatus == true)){
                Query_8_stats new_stats_to_insert = query_8_stats_new(driver_id, username, ride_id, d1, d2);
                stats = g_list_prepend(stats, new_stats_to_insert);
            }
            free(username); free(driver_id); free(ride_id);
            j++;
        }
        stats = g_list_sort(stats, (GCompareFunc) query_8_compare_function);
        query_8_get_output(catalog, stats, i);
        g_list_free_full(stats, free_query_8_stats);

    }
    if(id == 9){
        ride *rides_array = catalog_get_rides_array(catalog);
        GList *rides_stats = NULL;
        int j = 0;
        while(rides_array[j]){
            ride rideaux = rides_array[j];
            Date ride_date = get_ride_date(rideaux);
            double ridetip = get_ride_tip(rideaux);
            if(date_compare(ride_date, str_to_date(get_query_arg(query,0))) <= 0 && date_compare(ride_date, str_to_date(get_query_arg(query, 1))) >= 0 && ridetip != 0){
                rides_stats = g_list_prepend(rides_stats, query_9_add_ride_to_stats_list(rideaux));
            }
            j++;
        }
        rides_stats = g_list_sort(rides_stats, (GCompareFunc) query_9_compare_function);
        filename = query_9_get_output(rides_stats, i);       
    }
    return filename;
}

void execute(Catalog catalog){

    char* filename = NULL;
    int i = 0;

    size_t buffer_size = 200; 

    char *buffer = (char *) malloc(sizeof(char)*buffer_size);
    char *to_free = buffer;
    char **buffer_arrayzed;

    while(fgets(buffer, buffer_size, catalog_get_queries_file(catalog))){
        
        buffer_arrayzed = parser(4, buffer);

        Query query_new = query_new_load(buffer_arrayzed);

        filename = execute_query(catalog, query_new, i);

        free(filename);
        free_query(query_new);
        free(buffer_arrayzed);

        i++;
    }

    free(to_free);
}

double calculate_total_price_of_ride(Catalog catalog, ride ride){
    GHashTable *drivers_table = catalog_get_drivers_htable(catalog);
    driver ride_driver = g_hash_table_lookup(drivers_table, get_ride_driver_id(ride));
    int distance = get_ride_distance(ride);
    Car_class car_class = get_driver_carclass(ride_driver);
    double result = 0;
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