#include "Tests.h"

// Просеивание
void sift(int array[], int left, int right) {
    int x, temp;
    int i = left;
    int j = 2 * left + 1;
    x = array[left];

    if (j < right && array[j] > array[j + 1]) {
        ++j;
    }
    while (j <= right && x > array[j]) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i = j;
        j = 2 * j + 1;

        if (j < right && array[j] > array[j + 1]) { ++j; }
    }
}

void pyramid_sort(int array[], int n) {
    int left = n / 2 + 1;
    int right = n - 1;
    int temp;

    while (left > 0) {
        left --;
        sift(array, left, n - 1);
    }

    while (right > 0) {
        temp = array[0];
        array[0] = array[right];
        array[right] = temp;
        right--;
        sift(array, 0, right);
    }
    
}

int main() {
    test_case_1(pyramid_sort);
    test_case_2(pyramid_sort);
}