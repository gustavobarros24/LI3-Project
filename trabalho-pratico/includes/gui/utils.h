#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ncurses.h>

#ifndef UTILS_H
#define UTILS_H

int from_file_to_stdout (char *filename,int page_n);
void pagination (char *filename, WINDOW *(*print_func)());
void print_title();
WINDOW *create_newwin(int height, int width, int start_y, int start_x);
void prepend(char* s, char* t);

#endif