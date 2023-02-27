#include "../../includes/types/driver.h"

typedef struct driver {
    char *id;
    char* name;
    Date birthday;
    char gender;
    Car_class car_class;
    Date account_creation;
    bool status;
} *driver;


char* get_driver_id (driver d) {

    return strdup(d->id);

}

char* get_driver_name (driver d) {

    return strdup(d->name);

}

Date get_driver_birthday (driver d) {

    return d->birthday;

}

char get_driver_gender (driver d) {

    return d->gender;

}

Car_class get_driver_carclass (driver d) {

    return d->car_class;

}

Date get_driver_accountcreation (driver d) {

    return d->account_creation;

}

bool get_driver_status (driver d) {

    return d->status;

}

driver new_driver() {

    driver new = (driver) malloc(sizeof(struct driver));
    return new;

}

void set_driver_id (driver d, char* new_id) {

    d -> id = strdup(new_id);

}

void set_driver_name (driver d, char* new_name) {

    d->name =  strdup(new_name);

}

void set_driver_birthday (driver d, char* new_birthday_str) {

    Date new_birthday = str_to_date(new_birthday_str);
    // memcpy(d->birthday, new_birthday, date_size());
    d->birthday = new_birthday;

}

void set_driver_gender (driver d,char *new_gender) {

    d -> gender = new_gender[0];

}

void set_driver_car_class (driver d, char *new_car_class) {
    if(!strcasecmp(new_car_class, "basic")){
        d->car_class = BASIC;
    }
    else if(!strcasecmp(new_car_class, "green")){
        d->car_class = GREEN;
    }
    else d->car_class = PREMIUM;

}

void set_driver_account_creation (driver d, char* new_account_creation_str) {

    Date new_account_creation = str_to_date(new_account_creation_str);
    // memcpy(d->account_creation, new_account_creation, date_size());
    d->account_creation = new_account_creation;

}

void set_driver_status (driver d, char* new_status) {
    if(new_status[0] == 'a' || new_status[0] == 'A') d->status = true;
    else d->status = false;
}

void free_driver(void *void_driver) {

    driver driver_to_free = (driver) void_driver;

    free(driver_to_free->account_creation);
    free(driver_to_free->birthday);
    free(driver_to_free->id);
    free(driver_to_free->name);

    free(driver_to_free);

}

driver driver_new_load(char **buffer){
    driver driver = new_driver();
    set_driver_id(driver, buffer[0]);
    set_driver_name(driver, buffer[1]);
    set_driver_birthday(driver, buffer[2]);
    set_driver_gender(driver, buffer[3]);
    set_driver_car_class(driver, buffer[4]);
    set_driver_account_creation(driver, buffer[7]);
    set_driver_status(driver, buffer[8]);
 
    return driver;
}