#include "../includes/types/date.h"

typedef struct date {

    short int year;
    short int month;
    short int day;

}*Date;

Date date_new () {

    return (Date) malloc(sizeof(struct date));

}

void date_set_day (Date date, short int day) {

    date->day = day;

}

void date_set_month (Date date, short int month) {

    date->month = month;

}

void date_set_year (Date date, short int year) {

    date->year = year;

}

short int date_get_day (Date date) {

    if(!date) return 0;
    return date->day;

}

short int date_get_month (Date date) {

    if(!date) return 0;
    return date->month;

}

short int date_get_year (Date date) {

    if(!date) return 0;
    return date->year;

}

size_t date_size () {

    return sizeof(struct date);

}

Date str_to_date (char* str) {

    Date new_date = date_new();

    char* token = (char *) malloc(strlen(str));
    char* to_free = token;
    
    strncpy(token, str, 2);
    date_set_day(new_date, (short) atoi(token));

    strncpy(token, str+3, 2);
    date_set_month(new_date, (short) atoi(token));

    strncpy(token, str+6, 4);
    date_set_year(new_date, (short) atoi(token));

    free(to_free);
    return new_date;
}

// -1 se a data 1 for mais recente, 0 se forem iguais e -1 se date2 for mais recente
int date_compare (Date date1, Date date2) {

    int result = 0;
    short int year1 = date_get_year(date1), year2 = date_get_year(date2);
    short int month1 = date_get_month(date1), month2 = date_get_month(date2);
    short int day1 = date_get_day(date1), day2 = date_get_day(date2);
    if (date2==NULL || date1==NULL) {
        return -1;
    }
    else{
        if (year1 != year2) {
            if (year1 > year2) result = -1;
            else result =1; 
        }
        else if (month1 != month2) {
            if (month1 > month2) result = -1;
            else result =1; 
        }
        else if (day1 != day2) {
            if (day1 > day2) result = -1;
            else result =1; 
        }
        return result;  
    }
}

short int get_age (Date date) {

    short int birth_day = date_get_day(date), birth_month = date_get_month(date), birth_year = date_get_year(date);
    short int age = CURRENT_YEAR - birth_year;

    if (CURRENT_MONTH - birth_month < 0) age--;
    else if (CURRENT_MONTH - birth_month == 0) {
        if (CURRENT_DAY - birth_day < 0) age--;
    }
    return age;
}