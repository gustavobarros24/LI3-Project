#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <sys/resource.h>

#include "../includes/types/ride.h"
#include "../includes/types/user.h"
#include "../includes/types/driver.h"
#include "../includes/types/query.h"
#include "../includes/utilities/parser.h"
#include "../includes/utilities/catalog.h"
#include "../includes/types/execute.h"


#define MAXLINELENGTH 200


//função que executa uma query e compara com o output com o resultado esperado, imprimindo as diferenças entra cada respetiva linha
bool run_query(Catalog catalog, Query query, int query_number, char *tests_folder_path){
    clock_t start, end;
    printf("TEST %d (QUERY%d)\n", query_number+1, get_query_id(query));
    start = clock();
    execute_query(catalog, query, query_number);
    end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Query runtime: %.2f seconds\n", cpu_time_used);

    query_number++;
    char *actual_result = (char *) malloc(MAXLINELENGTH);
    sprintf(actual_result, "Resultados/command%d_output.txt", query_number);
    FILE *actual_result_fp = fopen(actual_result, "r");
    if(!actual_result_fp){
        perror("actual_result file error\n");
        return false;
    }

    char *expected_result = (char *) malloc(MAXLINELENGTH);
    sprintf(expected_result, "%s/expected/command%d_output.txt", tests_folder_path, query_number);
    FILE *expected_result_fp = fopen(expected_result, "r");
    if(!expected_result_fp){
        perror("expected_result file error\n");
        return false;
    }

    int total_dif = 0;
    int line = 0;
    char *l1 = (char *) malloc(MAXLINELENGTH);
    char *l2 = (char *) malloc(MAXLINELENGTH);
    while(fgets(l1, MAXLINELENGTH, actual_result_fp) && fgets(l2, MAXLINELENGTH, expected_result_fp)){
        if(!l1 || !l2 || strcmp(l1, l2) != 0){
            printf("Line: %d\n", line);
            printf("Expected Output: %s\n", l2);
            printf("Obtained Result: %s\n", l1);
            total_dif++;
        }
        fgets(l1, MAXLINELENGTH, actual_result_fp); 
        fgets(l2, MAXLINELENGTH, expected_result_fp);
        line++;
    }
    if(total_dif==0) printf("Correct output!\n\n");
    free(l1);
    free(l2);
    free(expected_result);
    free(actual_result);
    fclose(actual_result_fp);
    fclose(expected_result_fp);
    return true;
}


// argumento 1: path para os data files // argumento 2: pasta com as queries a serem executadas // argumento 3: path para pasta com os resultados corretos //
int main(int argc, char *argv[]){
    if(argc!=4){
        perror("error in arguments number\n");
        return 1;
    }

    char *users_fpath, *drivers_fpath, *rides_fpath, *queries_fpath;
    size_t buffer_size = 100; 
    char *buffer = (char *) malloc(sizeof(char)*buffer_size);
    char *to_free = buffer;

    strcpy(buffer, argv[1]);
    users_fpath = strdup(strcat(buffer, "/users.csv"));
    strcpy(buffer, argv[1]);
    drivers_fpath = strdup(strcat(buffer, "/drivers.csv"));
    strcpy(buffer, argv[1]);
    rides_fpath = strdup(strcat(buffer, "/rides.csv"));
    strcpy(buffer, argv[2]);
    queries_fpath = strdup(buffer);

    clock_t start_catalog, end_catalog, start, end;
    double catalog_time, program_time;
    start = clock();    
    start_catalog = clock();
    Catalog catalog = catalog_new(users_fpath, drivers_fpath, rides_fpath, queries_fpath);
    catalog_load(catalog);
    end_catalog = clock();
    catalog_time = ((double)(end_catalog - start_catalog))/CLOCKS_PER_SEC;
    printf("----------------------------------------------------------------------\n\n");
    printf("Runtime for loading Catalogs: %.2f seconds\n\n", catalog_time);
    // parse_queries(catalog);

    printf("----------------------------------------------------------------------\n\n");

    int i = 0;
    char **buffer_arrayzed;
    buffer = to_free;

    while(fgets(buffer, buffer_size, catalog_get_queries_file(catalog))){
        
        buffer_arrayzed = parser(4, buffer);

        Query query_new = query_new_load(buffer_arrayzed);

        run_query(catalog, query_new, i, argv[3]);

        free_query(query_new);
        free(buffer_arrayzed);

        i++;
    }

    printf("----------------------------------------------------------------------\n\n");

    end = clock();
    program_time = ((double)(end - start))/CLOCKS_PER_SEC;

    printf("Runtime for program: %.2f seconds\n\n", program_time);
    printf("----------------------------------------------------------------------\n\n");

    int who = RUSAGE_SELF;
    struct rusage usage;

    getrusage(who, &usage);
    printf("Memory used: %.2fMB\n\n", usage.ru_maxrss *  0.000977);
    printf("----------------------------------------------------------------------\n\n");

    // char command[100];
    // sprintf(command, "/usr/bin/time -f \"%%M\" ./programa-testes %s %s %s", argv[1], argv[2], argv[3]);
    // int memory_used = system(command);

    free(to_free);

    return 0;
}
