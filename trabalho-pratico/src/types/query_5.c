#include "../../includes/types/query_5.h"

char *query_5_get_output(int j, double d, int i){
    char *filename = (char *) malloc(100);
    double r = d/j;
    i++;
    sprintf(filename, "Resultados/command%d_output.txt", i);
    FILE *output_fp = fopen(filename, "w");
    if(j!=0)fprintf(output_fp, "%.3f\n", r);
    fclose(output_fp);  

    return filename;
}