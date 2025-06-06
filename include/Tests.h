#ifndef SORT_TEST_CASES_H_
#define SORT_TEST_CASES_H_

#include <stdio.h>

void print_array(int array[], int len);
int test_case_1(void (*algorithm)(int array[], int len));
int test_case_2(void (*algorithm)(int array[], int len));
int test_case_3(void (*algorithm)(int array[], int len));

#endif