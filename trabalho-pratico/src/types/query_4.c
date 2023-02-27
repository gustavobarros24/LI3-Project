#include "../../includes/types/query_4.h"

//função imprime num file o output de (preço_medio)
char *query_4_get_output(int totalrides, double totalmoney, int i){
    char *filename = (char *) malloc(100);
    i++;

    double total = totalmoney/totalrides;
    sprintf(filename, "Resultados/command%d_output.txt", i);
    FILE *output_fp = fopen(filename, "w");
    if(totalrides!=0)fprintf(output_fp, "%.3f\n", total);
    fclose(output_fp);

    return filename;
}