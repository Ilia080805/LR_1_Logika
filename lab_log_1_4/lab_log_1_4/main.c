#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <locale.h>
#include <stdio.h>

#define ROWS 3
#define COLS 4

int main(void) {
    setlocale(LC_ALL, "Russian");
    int matrix[ROWS][COLS] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };
    int i, j, sum;

    printf("Исходный массив:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Сумма элементов по строкам:\n");
    for (i = 0; i < ROWS; i++) {
        sum = 0;
        for (j = 0; j < COLS; j++) {
            sum += matrix[i][j];
        }
        printf("Строка %d: %d\n", i + 1, sum);
    }

    printf("\n");

    printf("Сумма элементов по столбцам:\n");
    for (j = 0; j < COLS; j++) {
        sum = 0;
        for (i = 0; i < ROWS; i++) {
            sum += matrix[i][j];
        }
        printf("Столбец %d: %d\n", j + 1, sum);
    }

    return 0;
}