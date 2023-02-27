#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <glib.h>

#ifndef CATALOG_H
#define CATALOG_H

#include "../../includes/types/driver.h"
#include "../../includes/types/user.h"
#include "../../includes/types/ride.h"
#include "../../includes/types/query.h"
#include "../../includes/utilities/parser.h"
#include "../../includes/types/validate.h"

typedef struct catalog *Catalog;

Catalog catalog_new(char *a, char *b, char *c, char *d);

FILE *catalog_get_users_file(Catalog catalog);

FILE *catalog_get_drivers_file(Catalog catalog);

FILE *catalog_get_rides_file(Catalog catalog);

FILE *catalog_get_queries_file(Catalog catalog);

ride *catalog_get_rides_array(Catalog catalog);

GHashTable *catalog_get_drivers_htable(Catalog catalog);

GHashTable *catalog_get_users_htable(Catalog catalog);


void catalog_free(Catalog catalog);

void catalog_load(Catalog catalog);

#endif