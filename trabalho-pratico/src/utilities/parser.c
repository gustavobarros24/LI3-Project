#include "../../includes/utilities/parser.h"

char **parser (int n, char *buffer) {

    size_t buffer_size = 60;
    char *portion;
    portion = malloc(sizeof(char)*buffer_size);
    if(portion==NULL){
        perror("unable to allocate buffer\n");
        exit(2);
    }
    char *to_delete = portion;

    char **result;
    result = (char **) malloc(n*sizeof(char)*buffer_size);
    if(result==NULL){
        perror("unable to allocate buffer\n");
        exit(2);
    }

    int i = 0;
    if(n>4){
        while((portion = strsep(&buffer, ";\n")) != NULL){
            if(strcmp(portion, "") != 0){
                result[i] = portion;
                i++;
            }
            else{
                result[i] = "\0";
            }
        }
    }
    else{
        while((portion = strsep(&buffer, " \n")) != NULL){
            if(strcmp(portion, "") != 0){
                result[i] = portion;
                i++;
            }
        }
    }

    free(to_delete);
    return result;
}
