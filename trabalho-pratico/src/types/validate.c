
#include "../includes/types/validate.h"


bool val_date(char *date){
    if (strspn(date, "0123456789/") != strlen(date)) return false;
    char *portion = malloc(sizeof(date));
    char *to_free = portion;
    int tmp;

    portion = strsep(&date, "/");
    if(portion){
        tmp = atoi(portion);
        if(tmp<1 || tmp>31) return false;
    }

    portion = strsep(&date, "/");
    if(portion){
        tmp = atoi(portion);
        if(tmp<1 || tmp>12) return false;
    }

    portion = strsep(&date, "/");
    if(portion){
        if(strspn(portion, "0123456789") != strlen(portion)) return false;
    }
    free(to_free);
    return true;
}

bool val_car_class(char *car_class){
    if(strcasecmp(car_class, "green")==0 || strcasecmp(car_class, "premium")==0 || strcasecmp(car_class, "basic")==0) return true;
    else return false;
}

bool val_account_status(char *account_status){
    if(strcasecmp(account_status, "active")==0 || strcasecmp(account_status, "inactive")==0) return true;
    else return false;
}

bool val_distance_or_score(char *distance){
    for(int i=0; i<strlen(distance); i++){
        if(!isdigit(distance[i])) return false;
    }
    if(atoi(distance) <= 0) return false;
    return true;
}

bool val_string(char *string){
    if(strlen(string)>0) return true;
    else return false;
}

bool val_tip(char *tip){
    int len = strlen(tip);
    if (!isdigit(tip[0]) || atof(tip)<0) return false;
    if (strspn(tip, "0123456789.") != len) return false;
    int i;
    for(i=0; i<len; i++){
        if(tip[i] == '.'){
            if(!isdigit(tip[i+1]) || i+2!=len) return false;
        }
    }
    return true;
}


bool validate_user(char **user){
    int i;
    for(i=0; i<7; i++){
        if(i==0 || i==1 || i==2 || i==5){
            if(!val_string(user[i])) return false;
        }
    }
    char *d1 = strdup(user[3]);
    char *d2 = strdup(user[4]);
    if(val_date(d1) && val_date(d2) && val_account_status(user[6])) {
        free(d1); free(d2);
        return true;
    }
    else return false;
}

bool validate_driver(char **driver){
    int i;
    for(i=0; i<9; i++){
        if(i==0 || i==1 || i==3 || i==5 || i==6){
            if(!val_string(driver[i])) return false;
            }
        i++;
    }
    char *d1 = strdup(driver[2]);
    char *d2 = strdup(driver[7]);
    if(val_date(d1) && val_car_class(driver[4])  && val_date(d2) && val_account_status(driver[8])){
        free(d1); free(d2);
        return true;
    }
    else return false;
}

bool validate_ride(char **ride){
    int i;
    for(i=0; i<9; i++){
        if(i==0 || i==2 || i==3 || i==4){
            if(!val_string(ride[i])) return false;
            }
        i++;
    }
    char *d1 = strdup(ride[1]);
    if(val_date(d1) && val_distance_or_score(ride[5]) && val_distance_or_score(ride[6]) && val_distance_or_score(ride[7]) && val_tip(ride[8])) {
        free(d1);
        return true;
    }
    else return false;
}

bool validate_line(int l, char **array){
    switch (l){
        case 7:
            return validate_user(array);
        case 9:
            return validate_driver(array);
        case 10:
            return validate_ride(array);
    }
    return false;
}