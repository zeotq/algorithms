#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Построение префикс-функции
void computePrefixFunction(const char* pattern, int* prefix, int m) {
    int length = 0; // длина предыдущего совпавшего префикса
    prefix[0] = 0;  // первый элемент всегда 0

    for (int i = 1; i < m; i++) {
        while (length > 0 && pattern[i] != pattern[length])
            length = prefix[length - 1];

        if (pattern[i] == pattern[length])
            length++;

        prefix[i] = length;
    }
}

// КМП поиск
void KMP(const char* text, const char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);

    int* prefix = (int*)malloc(sizeof(int) * m);
    computePrefixFunction(pattern, prefix, m);

    int i = 0, j = 0; // i - индекс в тексте, j - индекс в шаблоне

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            printf("Найдено совпадение на позиции %d\n", i - j);
            j = prefix[j - 1]; // продолжаем поиск
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = prefix[j - 1];
            } else {
                i++;
            }
        }
    }

    free(prefix);
}


int main() {
    char text[] = "ABAAABCDAB";
    char pattern[] = "ABC";

    KMP(text, pattern);
    return 0;
}
