#include <stdio.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "Russian");
    int a[10] = { 15, 3, 42, 8, 90, 12, 4, 67, 23, 11 };
    int n = 10;
    int i;

    int min = a[0];
    int max = a[0];

    for (i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
        if (a[i] > max) {
            max = a[i];
        }
    }

    printf("Массив: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Максимальный элемент: %d\n", max);
    printf("Минимальный элемент: %d\n", min);
    printf("Разница (max - min): %d\n", max - min);

    return 0;
}