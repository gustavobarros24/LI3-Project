#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "date.h"

#ifndef USER_H
#define USER_H


typedef struct user *user;

char* get_user_username (user u);
char* get_user_name (user u);
char get_user_gender (user u);
Date get_user_birthday (user u);
Date get_user_account_date_creation (user u);
char* get_user_paymethod (user u);
bool get_user_status (user u);
user new_user();
void set_user_username(user u, char* newusername);
void set_user_name(user u, char* newname);
void set_user_gender(user u, char *newgender);
void set_user_birthdate(user u, char* newbirthdate);
void set_user_account_date(user u, char* newaccount_date);
void set_user_paymethod(user u, char* newpaymehod);
void set_user_status(user u, char* newstatus);
void free_user(void *void_user);
user user_new_load(char **buffer);

#endif