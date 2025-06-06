#include <stdio.h>
#include <limits.h>
#include <Tests.h>

#define MAXN 10000
int tree[2 * MAXN];

void tournament_sort(int *a, int n) {
    // Построение дерева
    for (int i = 0; i < n; i++) 
        tree[n + i] = a[i];
    
    for (int i = n - 1; i > 0; i--)
        tree[i] = (tree[2 * i] < tree[2 * i + 1]) ? tree[2 * i] : tree[2 * i + 1];

    // Сортировка
    for (int i = 0; i < n; i++) {
        int min_val = tree[1];
        a[i] = min_val;

        // Находим лист с минимальным значением и заменяем его на INT_MAX
        int j = 1;
        while (j < n) {
            j = (tree[2 * j] == min_val) ? 2 * j : 2 * j + 1;
        }
        tree[j] = INT_MAX;

        // Обновляем путь от листа к корню
        for (j /= 2; j >= 1; j /= 2) {
            tree[j] = (tree[2 * j] < tree[2 * j + 1]) ? tree[2 * j] : tree[2 * j + 1];
        }
    }
}

int main() {
    test_case_1(tournament_sort);
    test_case_2(tournament_sort);
    return 0;
}
