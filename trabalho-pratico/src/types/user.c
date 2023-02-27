#include "../includes/types/user.h"

typedef struct user
{
    char *username;
    char *name;
    char  gender;
    Date birth_date;
    Date account_date;
    bool  status;
    int   rides_list_index;
} *user;

char* get_user_username (user u){

    return strdup(u -> username);
    
}

char* get_user_name (user u){
    return strdup(u -> name);
}

char get_user_gender (user u){

    return u -> gender;

}

Date get_user_birthday (user u){
    
    return u -> birth_date;

}

Date get_user_account_date_creation (user u){

    return u -> account_date;

}

bool get_user_status (user u) {

    return u -> status;

}

int get_user_rides_list_index(user u){
    return u->rides_list_index;
}

user new_user() {

    user newuser = (user) malloc(sizeof(struct user));
    return newuser;

}

void set_user_username(user u, char *newusername){

    u->username = strdup(newusername);

}

void set_user_name(user u, char *newname){

    u->name = strdup(newname);

}

void set_user_gender(user u, char *newgender){

    u->gender = newgender[0];

}

void set_user_birthdate(user u, char *new_birth_date_str){

    Date new_birth_date = str_to_date(new_birth_date_str);
    u->birth_date = new_birth_date;

}

void set_user_account_date(user u, char *new_account_date_str){

    Date new_account_date = str_to_date(new_account_date_str);
    u->account_date = new_account_date;

}

void set_user_status(user u, char *newstatus){
    if(newstatus[0] == 'a' || newstatus[0] == 'A') u->status = true;
    else u->status = false;
}

void user_rides_list_index_inc(user u){
    u->rides_list_index++;
}

void reset_user_rides_list_index(user u){
    u->rides_list_index = 0;
}

void free_user(void *void_user) {

    user user_to_free = (user) void_user;
    
    free(user_to_free->username);
    free(user_to_free->name);
    free(user_to_free->birth_date);
    free(user_to_free->account_date);

    free(user_to_free);
}

user user_new_load(char **buffer){
    user user = new_user();
    
    set_user_username(user, buffer[0]);
    set_user_name(user, buffer[1]);
    set_user_gender(user, buffer[2]);
    set_user_birthdate(user, buffer[3]);
    set_user_account_date(user, buffer[4]);
    set_user_status(user, buffer[6]);
    return user;
}
