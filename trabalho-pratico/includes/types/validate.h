#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#ifndef VALIDATE_H
#define VALIDATE_H

#include "driver.h"
#include "user.h"
#include "ride.h"
#include "date.h"


bool val_date(char *date);
bool val_car_class(char *car_class);
bool val_account_status(char *account_status);
bool val_distance_or_score(char *distance_or_score);
bool val_string(char *string);
bool val_tip(char *tip);

bool validate_driver(char **driver);
bool validate_user(char **user);
bool validate_ride(char **ride);

bool validate_line(int l, char **array);

#endif