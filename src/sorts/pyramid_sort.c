#include "Tests.h"

// Просеивание для max-кучи
void sift_down(int array[], int root, int bottom) {
    int max_child;
    int done = 0;
    
    while ((root * 2 <= bottom) && (!done)) {
        if (root * 2 == bottom) {
            max_child = root * 2;
        } else if (array[root * 2] > array[root * 2 + 1]) {
            max_child = root * 2;
        } else {
            max_child = root * 2 + 1;
        }
        
        if (array[root] < array[max_child]) {
            int temp = array[root];
            array[root] = array[max_child];
            array[max_child] = temp;
            root = max_child;
        } else {
            done = 1;
        }
    }
}

void pyramid_sort(int array[], int n) {
    // Построение кучи
    for (int i = (n / 2) - 1; i >= 0; i--) {
        sift_down(array, i, n - 1);
    }
    
    // Сортировка
    for (int i = n - 1; i >= 1; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        sift_down(array, 0, i - 1);
    }
}

int main() {
    test_case_1(pyramid_sort);
    test_case_2(pyramid_sort);
}