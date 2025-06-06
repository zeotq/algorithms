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

            // Проверяем, не вышли ли мы за границу текста при следующем сдвиге
            // shift + m — позиция символа, идущего СРАЗУ после текущего совпадения
            if (shift + m < n)
                // Если в тексте есть символ после текущего совпадения,
                // сдвигаем шаблон так, чтобы последний символ шаблона совпал
                // с последним вхождением этого символа в шаблоне.
                // Формула: m - badChar[text[shift + m]]
                shift += m - badChar[(unsigned char)text[shift + m]];
            else
                // Если мы в самом конце текста — просто сдвигаем на 1
                shift += 1;
        } else {
            // Символ в тексте, на котором произошло несовпадение
            char mismatched = text[shift + j];

            // Вычисляем сдвиг по эвристике плохого символа:
            // на сколько символ в шаблоне "отстаёт" от своего последнего вхождения
            // Если символ не встречается в шаблоне → badChar[mismatched] == -1
            int badCharShift = j - badChar[(unsigned char)mismatched];

            // Сдвигаем шаблон на вычисленное расстояние, но минимум на 1
            // Это важно, чтобы не застрять в бесконечном цикле
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
