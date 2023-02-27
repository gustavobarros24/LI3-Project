#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <glib.h>


#include "../../includes/types/driver.h"
#include "../../includes/types/user.h"
#include "../../includes/types/ride.h"
#include "../../includes/types/query_1.h"
#include "../../includes/types/query_2.h"
#include "../../includes/types/query_3.h"
#include "../../includes/types/query_4.h"
#include "../../includes/types/query_5.h"
#include "../../includes/types/query_6.h"
#include "../../includes/types/query_7.h"
#include "../../includes/types/query_8.h"
#include "../../includes/types/query_9.h"
#include "../../includes/types/query.h"
#include "../utilities/catalog.h"

#ifndef EXECUTE_H
#define EXECUTE_H

char* execute_query (Catalog catalog, Query query, int i);
void execute(Catalog catalog);
double calculate_total_price_of_ride(Catalog catalog, ride ride);

#endif