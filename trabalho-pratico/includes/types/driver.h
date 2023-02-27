#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "date.h"

#ifndef DRIVER_H
#define DRIVER_H

typedef enum car_class{
    BASIC,
    GREEN,
    PREMIUM
} Car_class;

typedef struct driver *driver;

char* get_driver_id(driver d);
char* get_driver_name (driver d);
Date get_driver_birthday (driver d);
char get_driver_gender (driver d);
Car_class get_driver_carclass (driver d);
Date get_driver_accountcreation (driver d);
bool get_driver_status (driver d);
driver new_driver();
void set_driver_id (driver d, char* new_id);
void set_driver_name (driver d, char* new_name);
void set_driver_birthday (driver d, char* new_birthday);
void set_driver_gender (driver d,char *new_gender);
void set_driver_car_class (driver d, char *new_car_class);
void set_driver_account_creation (driver d, char* new__account_creation);
void set_driver_status (driver d, char* new_status);
void free_driver(void *void_driver);
driver driver_new_load(char **buffer);

#endif