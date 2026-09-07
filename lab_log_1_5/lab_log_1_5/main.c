#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

#define COUNT 3

struct student {
    char famil[20];
    char name[20];
    char facult[20];
    int Nomzach;
};

int main(void) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    struct student stud[COUNT];
    char search_famil[20];
    int i, found = 0;

    for (i = 0; i < COUNT; i++) {
        printf("--- Ввод данных студента №%d ---\n", i + 1);
        printf("Введите фамилию: ");
        scanf("%19s", stud[i].famil);
        printf("Введите имя: ");
        scanf("%19s", stud[i].name);
        printf("Введите факультет: ");
        scanf("%19s", stud[i].facult);
        printf("Введите номер зачетной книжки: ");
        scanf("%d", &stud[i].Nomzach);
        printf("\n");
    }

    printf("Введите фамилию студента для поиска: ");
    scanf("%19s", search_famil);

    printf("\nРезультаты поиска:\n");
    for (i = 0; i < COUNT; i++) {
        if (strcmp(stud[i].famil, search_famil) == 0) {
            printf("Найден студент: %s %s | Факультет: %s | № зачетки: %d\n",
                stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);
            found = 1;
        }
    }

    if (!found) {
        printf("Студент с фамилией \"%s\" не найден.\n", search_famil);
    }

    return 0;
}