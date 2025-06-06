#include <stdio.h>
#include <string.h>
#define ALPHABET_SIZE 256 // Все возможные символы

// Заполнение таблицы плохих символов
void badCharHeuristic(char *pattern, int m, int badChar[]) {
    for (int i = 0; i < ALPHABET_SIZE; i++)
        badChar[i] = -1;

    for (int i = 0; i < m; i++)
        badChar[(unsigned char)pattern[i]] = i;
}

// Основной алгоритм Бойера-Мура (только плохой символ)
void boyerMooreSearch(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);

    int badChar[ALPHABET_SIZE];
    badCharHeuristic(pattern, m, badChar);

    int shift = 0;

    while (shift <= (n - m)) {
        int j = m - 1;

        // Сравниваем с конца шаблона
        while (j >= 0 && pattern[j] == text[shift + j])
            j--;

        if (j < 0) {
            printf("Найдено вхождение на позиции %d\n", shift);

            // Если конец текста — сдвигаем шаблон на 1
            shift += (shift + m < n) ? m - badChar[(unsigned char)text[shift + m]] : 1;
        } else {
            int badCharShift = j - badChar[(unsigned char)text[shift + j]];
            shift += (badCharShift > 1) ? badCharShift : 1;
        }
    }
}

int main() {
    char text[] = "ABAAABCDAB";
    char pattern[] = "ABC";

    boyerMooreSearch(text, pattern);
    return 0;
}
