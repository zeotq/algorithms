#include <stdio.h>
#include <string.h>
#define d 256           // размер алфавита
#define q 101           // простое число для модуля

void rabinKarp(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int i, j;
    int pattern_hash = 0;
    int current_hash = 0;
    int h = 1;

    // Вычисляем h = pow(d, m-1) % q
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Вычисляем начальные хэши шаблона и текста
    for (i = 0; i < m; i++) {
        pattern_hash = (d * pattern_hash + pattern[i]) % q;
        current_hash = (d * current_hash + text[i]) % q;
    }

    // Сканируем текст
    for (i = 0; i <= n - m; i++) {
        if (pattern_hash == current_hash) {
            // Хэши совпали, проверим побайтно
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m)
                printf("Найдено вхождение на позиции %d\n", i);
        }

        // Вычисляем хэш следующего окна текста
        if (i < n - m) {
            current_hash = (d * (current_hash - text[i] * h) + text[i + m]) % q;

            // Убедимся, что current_hash не отрицательное
            if (current_hash < 0)
                current_hash += q;
        }
    }
}

int main() {
    char text[] = "ABAAABCDAB";
    char pattern[] = "ABC";

    rabinKarp(text, pattern);
    return 0;
}
