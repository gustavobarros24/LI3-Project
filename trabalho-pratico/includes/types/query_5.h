#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <glib.h>

#ifndef QUERY5_H
#define QUERY5_H

#include "driver.h"
#include "user.h"
#include "ride.h"
#include "date.h"
#include "../utilities/catalog.h"

char *query_5_get_output(int j, double d, int i);

double calculate_total_price_of_ride(Catalog catalog, ride ride);

#endif