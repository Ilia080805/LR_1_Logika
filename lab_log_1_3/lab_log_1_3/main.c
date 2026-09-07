#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "Russian");
    int n, i;
    int* a;

    printf("Введите размер массива: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Ошибка: введено неверное значение размера.\n");
        return 1;
    }

    a = (int*)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }

    printf("Введите %d элементов массива:\n", n);
    for (i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    printf("\nВведенный массив:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    free(a);

    return 0;
}