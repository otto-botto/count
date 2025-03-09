#include "gtest/gtest.h"

extern "C" {
#include "count.h"
}

TEST(FirstTest, IntegerTest) {
    EXPECT_EQ(5, test_gtest());
}

TEST(TestCount, TestingDracula) {
    char file_path[100] = "/home/lora/Documents/books/dracula";
    double words = count_words(file_path);
    printf("%0.1lf\n", words);
}

TEST(TestCount, TestingLittleWomen) {
    char file_path[100] = "/home/lora/Documents/books/little_women";
    double words = count_words(file_path);
    printf("%0.1lf\n", words);
}

TEST(TestCount, TestingBiography) {
    char file_path[100] = "/home/lora/Documents/books/biography";
    double words = count_words(file_path);
    printf("%0.1lf\n", words);
}

TEST(TestCount, TestBuildStr) {
    char file_path[100] = "/home/lora/Documents/books/dracula";
    double words = count_words(file_path);
    printf(build_str(words));
}