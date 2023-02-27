#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <glib.h>
#include "driver.h"
#include "user.h"
#include "ride.h"
#include "../includes/utilities/catalog.h"

#ifndef QUERY4_H
#define QUERY4_H

#include "driver.h"
#include "user.h"
#include "ride.h"
#include "date.h"
#include "../utilities/catalog.h"

char *query_4_get_output(int totalrides, double totalmoney, int i);

#endif