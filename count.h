#ifndef SEARCH_H
#define SEARCH_H

#include "server.h"
#include "cJSON.h"

int test_gtest();
char* build_str(double words);
double count_words(char* file_path);
void count(Server server, Request request);

#endif //SEARCH_H