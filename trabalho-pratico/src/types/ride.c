#include "../includes/types/ride.h"

typedef struct ride
{
    char  *id;
    Date   date;
    char  *driver_id;
    char  *user_username;
    char  *city;
    int    distance;
    int    score_user;
    int    score_driver;
    double tip;
} *ride;

size_t ride_size(){
    return sizeof(struct ride);
}

char *get_ride_id (ride r){
    return strdup(r->id);
}

Date get_ride_date (ride r){
    return r->date;
}

char *get_ride_driver_id (ride r){
    return strdup(r->driver_id);
}

char *get_ride_user_username (ride r){
    return strdup(r->user_username);
}

char *get_ride_city (ride r){
    return strdup(r->city);
}

int get_ride_distance (ride r){
    return r->distance;
}

int get_ride_score_user (ride r){
    return r->score_user;
}

int get_ride_score_driver (ride r) {
    return r->score_driver;
}

double get_ride_tip (ride r) {
    return r->tip;
}

ride new_ride() {
    ride new_ride = (ride) malloc(sizeof(struct ride));
    return new_ride;
}

void set_ride_id(ride r, char *id){
    r->id = strdup(id);
}

void set_ride_date(ride r, char* new_date_str){
    Date new_date = str_to_date(new_date_str);
    r->date = new_date;
}

void set_ride_driver_id(ride r, char* driver_id){
    r->driver_id = strdup(driver_id);
}

void set_ride_user_username(ride r, char* user_username){
    r->user_username = strdup(user_username);

}

void set_ride_city(ride r, char *city){
    r->city = strdup(city);
}

void set_ride_distance(ride r, int distance){
    r->distance = distance;
}

void set_ride_score_user(ride r, int score_user){
    r->score_user = score_user;
}

void set_ride_score_driver(ride r, int score_driver){
    r->score_driver = score_driver;
}

void set_ride_tip(ride r, double tip){
    r->tip = tip;
}

void free_ride(void *void_ride) {

    ride ride_to_free = (ride) void_ride;

    free(ride_to_free->id);
    free(ride_to_free->date);
    free(ride_to_free->driver_id);
    free(ride_to_free->user_username);
    free(ride_to_free->city);

    free(ride_to_free);

}

ride ride_new_load(char **buffer){
    ride ride = new_ride();
    
    set_ride_id(ride, buffer[0]);
    set_ride_date(ride, buffer[1]);
    set_ride_driver_id(ride, buffer[2]);
    set_ride_user_username(ride, buffer[3]);
    set_ride_city(ride, buffer[4]);
    set_ride_distance(ride, atoi(buffer[5]));
    set_ride_score_user(ride, atoi(buffer[6]));
    set_ride_score_driver(ride, atoi(buffer[7]));
    set_ride_tip(ride, strtod(buffer[8], NULL));
    return ride;
}
