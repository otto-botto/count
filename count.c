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