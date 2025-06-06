#include "Tests.h"

void pocket_sort(int sarray[], int array_size) {
    const int max = array_size;

    int bucket[10][max+1];

    for(int x=0;x<10;x++) bucket[x][max] = 0;
    for(int digit = 1; digit <= 1000000000; digit *= 10) {
        for(int i = 0; i < max; i++) {
            int dig = (sarray[i] / digit) % 10;
            bucket[dig][bucket[dig][max]++] = sarray[i];
        }
        int idx = 0;
        for(int x = 0; x < 10; x++) {
            for(int y = 0; y < bucket[x][max]; y++) {
                sarray[idx++] = bucket[x][y];
            }
            bucket[x][max] = 0;
        }
    }
}

int main() {
    test_case_1(pocket_sort);
    test_case_2(pocket_sort);
}