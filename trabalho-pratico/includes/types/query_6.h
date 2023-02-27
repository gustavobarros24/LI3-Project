#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <glib.h>

#ifndef QUERY6_H
#define QUERY6_H

#include "driver.h"
#include "user.h"
#include "ride.h"
#include "date.h"
#include "../utilities/catalog.h"

char *query_6_get_output(int j, int d, int i);

#endif