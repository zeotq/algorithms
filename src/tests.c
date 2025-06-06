#include "Tests.h"


void print_array(int array[], int len) {
    for (int i = 0; i < len - 1; ++i) printf("%d, ", array[i]);
    printf("%d\n", array[len - 1]);
}

int run_test(void (*alghoritm)(int array[], int len), int array[], int len) {
    print_array(array, len);
    alghoritm(array, len);
    print_array(array, len);
    return 0;
}

int test_case_1(void (*alghoritm)(int array[], int len)) {
    printf("Test 1:\n");
    int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    run_test(alghoritm, a, 10);
    return 0;
}

int test_case_2(void (*alghoritm)(int array[], int len)) {
    printf("Test 2:\n");
    int a[10] = {2, 1, 6, 4, 8, 7, 5, 3, 9, 0};
    run_test(alghoritm, a, 10);
    return 0;
}

int test_case_3(void (*alghoritm)(int array[], int len)) {
    printf("Test 3:\n");
    int a[3] = {1, 2, 3};
    run_test(alghoritm, a, 3);
    return 0;
}