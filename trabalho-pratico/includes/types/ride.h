#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "date.h"

#ifndef RIDE_H
#define RIDE_H

typedef struct ride *ride;

size_t ride_size();

char  *get_ride_id (ride r);
Date   get_ride_date (ride r);
char  *get_ride_driver_id (ride r);
char  *get_ride_user_username (ride r);
char  *get_ride_city (ride r);
int    get_ride_distance (ride r);
int    get_ride_score_user (ride r);
int    get_ride_score_driver (ride r);
double get_ride_tip (ride r);

ride new_ride();
void set_ride_id(ride r, char* id);
void set_ride_date(ride r, char* date);
void set_ride_driver_id(ride r, char* driver_id);
void set_ride_user_username(ride r, char* user_username);
void set_ride_city(ride r, char* city);
void set_ride_distance(ride r, int distance);
void set_ride_score_user(ride r, int score_user);
void set_ride_score_driver(ride r, int score_driver);
void set_ride_tip(ride r, double tip);
void free_ride(void *void_ride);
ride ride_new_load(char **buffer);

#endif