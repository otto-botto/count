#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "count.h"


int test_gtest(){
    return 5;
}

double count_words(char* file_path) {
    int count = 0;
    int in_word = 0;
    char ch;
    FILE* fileptr;

    fileptr = fopen(file_path, "r");
    if(fileptr == NULL) {
        fprintf(stderr, "Error opening file to read.");
        return -1;
    }

    while((ch = fgetc(fileptr)) != EOF) {
        if(isalnum(ch)) {
            if(in_word == 0) {
                in_word = 1;
                count++;
            }
        }
        else {
            in_word = 0;
        }
    }
    fclose(fileptr);
    return count;
}

char* build_str(double words) {
    // max digits 17 + 15 max hours --> allocated 256 chars should work
    double hours = (words/200)/60;
    int max_words = 18;
    char* str = (char*)malloc(256 * sizeof(char));
    str[0] = '\0';

    strcat(str, "words: ");
    char tmp[max_words];
    sprintf(tmp, "%.lf\n", words);
    strcat(str, tmp);
    strcat(str, "hours: ");
    char tmp2[max_words];
    sprintf(tmp2, "%.1lf\n", hours);
    strcat(str, tmp2);
    return str;
}


char* parse(char* body) {
    const cJSON* path_json = NULL;
    cJSON* body_json = cJSON_Parse(body);
    if(body_json == NULL) {
        fprintf(stderr, "Failed to parse request body.");
        exit(EXIT_FAILURE);
    }

    path_json = cJSON_GetObjectItemCaseSensitive(body_json, "path");
    if(!cJSON_IsString(path_json) || (path_json->valuestring == NULL)) {
        fprintf(stderr, "Failed to parse name.");
        exit(EXIT_FAILURE);
    }
    char* path = path_json->valuestring;
    double words = count_words(path);
    char* message = build_str(words);
    return message;
}

void count(Server server, Request request) {
    char* message = parse(request.content);
    printf("%s\n", message);
    respond(&server, &request, 200, message);
    free(message);
}