#include "Tests.h"

void quick_sort(int * nums, int len) {
    if (len < 2) return;
    int pivot = (nums[len / 2] + nums[0] + nums[len - 1]) / 3;
    int left = 0, right = len - 1;

    while (left <= right) {
        while (nums[left] < pivot) left++;
        while (nums[right] > pivot) right--;

        if (left <= right) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
    }

    // Рекурсивно сортируем две части массива
    if (right > 0) quick_sort(nums, right + 1);
    if (left < len) quick_sort(nums + left, len - left);
}

int main() {
    test_case_1(quick_sort);
    test_case_2(quick_sort);
}