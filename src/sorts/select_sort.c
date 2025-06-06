#include "Tests.h"

void select_sort(int array[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            int temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }
}

int main() {
    test_case_1(select_sort);
    test_case_2(select_sort);
}