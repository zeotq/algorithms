# Алгоритмы

## Сортировки

### O(n^2)

| Алгоритм              | Код | Визуализация | Временная сложность | Пространственная сложность |
|-----------------------|-----|--------------|---------------------|----------------------------|
| **Сортировка вставкой**<br>(Insertion Sort) | [`insert_sort.c`](/src/sorts/insert_sort.c) | <img src="https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif" width="120"> | **Лучший:** O(n)<br>**Средний:** O(n²)<br>**Худший:** O(n²) | O(1) |
| **Сортировка выбором**<br>(Selection Sort) | [`select_sort.c`](/src/sorts/select_sort.c) | <img src="https://upload.wikimedia.org/wikipedia/commons/9/94/Selection-Sort-Animation.gif" width="120" height="160"> | **Все случаи:** O(n²) | O(1) |
| **Пузырьковая**<br>(Bubble Sort) | [`bubble_sort.c`](/src/sorts/bubble_sort.c) | <img src="https://upload.wikimedia.org/wikipedia/commons/c/c8/Bubble-sort-example-300px.gif" width="120"> | **Лучший:** O(n)<br>**Средний:** O(n²)<br>**Худший:** O(n²) | O(1) |
| **Шейкерная**<br>(Cocktail Shaker Sort) |  | <img src="https://upload.wikimedia.org/wikipedia/commons/e/ef/Sorting_shaker_sort_anim.gif" width="120"> | **Лучший:** O(n)<br>**Худший:** O(n²) | O(1) |
| **Гномья**<br>(Gnome Sort) |  | <img src="https://upload.wikimedia.org/wikipedia/commons/3/37/Sorting_gnomesort_anim.gif" width="120"> | **Лучший:** O(n)<br>**Худший:** O(n²) | O(1) |

### O(n * log(n))

| Алгоритм              | Код | Визуализация | Временная сложность | Пространственная сложность |
|-----------------------|-----|--------------|---------------------|----------------------------|
| **Сортировка Хоара**<br>(Quick Sort) | [`quick_sort.c`](/src/sorts/quick_sort.c) | <img src="https://upload.wikimedia.org/wikipedia/commons/6/6a/Sorting_quicksort_anim.gif" width="120"> | Лучший: O(n log n)<br>Средний: O(n log n)<br>Худший: O(n²) | O(log n) |
| **Пирамидальная**<br>(Heap Sort) | [`pyramid_sort.c`](/src/sorts/pyramid_sort.c) | <img src="https://upload.wikimedia.org/wikipedia/commons/1/1b/Sorting_heapsort_anim.gif" width="120"> | Все случаи: O(n log n) | O(1) |
| **Гладкая**<br>(Smooth Sort) | [`smooth_sort.c`](/src/sorts/smooth_sort.c) | <img src="https://i.imgur.com/JZnQf3e.gif" width="120"> | Лучший: O(n)<br>Худший: O(n log n) | O(1) |
| **Карманная**<br>(Bucket Sort) | [`pocket_sort.c`](/src/search/pocket_sort.c) | <img src="https://upload.wikimedia.org/wikipedia/commons/6/61/Bucket_sort_1.png" width="120"> | Лучший: O(n + k)<br>Худший: O(n²) | O(n + k) |
| **Турнирная**<br>(Tournament Sort) | [`tournament_sort.c`](/src/sorts/tournament_sort.c) | <img src="https://i.imgur.com/XYZABC.gif" width="120"> | Все случаи: O(n log n) | O(n) |
| **Шелла**<br>(Shell Sort) |  | <img src="https://upload.wikimedia.org/wikipedia/commons/d/d8/Sorting_shellsort_anim.gif" width="120"> | Лучший: O(n log n)<br>Худший: O(n²) | O(1) |
| **Подсчетом**<br>(Counting Sort) |  | <img src="https://upload.wikimedia.org/wikipedia/commons/c/cd/Counting_sort_animation.gif" width="120"> | Все случаи: O(n + k) | O(n + k) |
| **Поразрядная**<br>(Radix Sort) |  | <img src="https://upload.wikimedia.org/wikipedia/commons/f/fe/Radix_sort_example.gif" width="120"> | Все случаи: O(d(n + b)) | O(n + b) |

## Поиск

6. [Алгоритм Рабина-Карпа](src/search/rabinKarp.c)

7. [Алгоритм Бойeра-Мура](src/search/boyerMoore.c)

8. [Алгоритм Кнутта-Мориса-Пратта](src/search/kmp.c)

## Прочее

1. [Алгоритм Дейкстры](https://github.com/zeotq/math-postfix/blob/main/src/postfix.c)