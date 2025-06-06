#include "Tests.h"

void bubble_sort(int array[], int array_size) {
    for (int i = 1; i < array_size; ++i) {
        for (int j = 0; j < array_size - i; ++j) {
            if (array[j] > array[j + 1]) {
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main() {
    test_case_1(bubble_sort);
    test_case_2(bubble_sort);
}