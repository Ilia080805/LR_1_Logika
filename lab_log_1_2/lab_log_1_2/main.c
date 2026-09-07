#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "Russian");
    int a[10];
    int n = 10;
    int i;
    int min_val = 10, max_val = 50;

    srand((unsigned int)time(NULL));

    for (i = 0; i < n; i++) {
        a[i] = min_val + rand() % (max_val - min_val + 1);
    }

    printf("—генерированный массив:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}