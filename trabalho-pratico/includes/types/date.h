#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef DATE_H
#define DATE_H
#define CURRENT_DAY 9
#define CURRENT_YEAR 2022
#define CURRENT_MONTH 10

typedef struct date *Date;

Date date_new ();

void date_set_day (Date date, short int day);
void date_set_month (Date date, short int month);
void date_set_year (Date date, short int year);
short int date_get_day (Date date);
short int date_get_month (Date date);
short int date_get_year (Date date);
Date str_to_date (char* str);
size_t date_size ();
int date_compare (Date date1, Date date2);
short int get_age (Date date);

#endif