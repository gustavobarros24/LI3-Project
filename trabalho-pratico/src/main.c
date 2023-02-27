#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <stdio.h>
#include <time.h>

#include "../includes/types/ride.h"
#include "../includes/types/user.h"
#include "../includes/types/driver.h"
#include "../includes/types/query.h"
#include "../includes/types/execute.h"
#include "../includes/utilities/parser.h"
#include "../includes/utilities/catalog.h"
#include "../includes/gui/gui.h"

int main(int argc, const char *argv[])
{
    if (argc == 3) {

        clock_t start, end;
        double execution_time;
        start = clock();
        
        char *users_fpath, *drivers_fpath, *rides_fpath, *queries_fpath;
        char *buffer;
        size_t buffer_length = strlen(argv[1]) + 13;
        buffer = malloc(sizeof(char) * buffer_length);
  
        strcpy(buffer, argv[1]);
        users_fpath = strdup(strcat(buffer, "/users.csv"));
        strcpy(buffer, argv[1]);
        drivers_fpath = strdup(strcat(buffer, "/drivers.csv"));
        strcpy(buffer, argv[1]);
        rides_fpath = strdup(strcat(buffer, "/rides.csv"));
        strcpy(buffer, argv[2]);
        queries_fpath = strdup(buffer);

        free(buffer);
        buffer = NULL;

        /*
        Catalog users_c = catalog_new(users_fpath);
        Catalog drivers_c = catalog_new(drivers_fpath);
        Catalog rides_c = catalog_new(rides_fpath);
        Stats stats = stats_new();
        catalogs_load(users_c, drivers_c, rides_c, stats);
        */

        Catalog catalog = catalog_new(users_fpath, drivers_fpath, rides_fpath, queries_fpath);
        catalog_load(catalog);



        execute(catalog);

        catalog_free(catalog);

        end = clock();
        execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
        printf("time: %f\n", execution_time);

    } else if (argc == 1) {

        start_gui();

    } else {
        
        printf("ERROR: NUMBER OF ARGUMENTS INVALID!");
        exit(1);
    }

    return 0;
}