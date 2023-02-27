#include "../../includes/types/query_6.h"

char *query_6_get_output(int j, int d, int i){
    char *filename = (char *) malloc(100);
    i++;
    double r = (double)d/j;
    sprintf(filename, "Resultados/command%d_output.txt", i);
    FILE *output_fp = fopen(filename, "w");
    if(j!=0)fprintf(output_fp, "%.3f\n", r);
    fclose(output_fp); 

    return filename; 
}