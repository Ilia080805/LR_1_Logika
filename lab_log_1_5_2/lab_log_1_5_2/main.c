#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

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

    struct student* students = NULL;
    int count = 0;

    printf("--- Ввод данных студентов ---\n");
    printf("Для завершения ввода введите '*' в поле фамилии.\n\n");

    while (1) {
        char temp_famil[20];
        printf("Введите фамилию (или '*' для окончания): ");
        scanf("%19s", temp_famil);

        if (strcmp(temp_famil, "*") == 0) {
            break;
        }

        struct student* new_ptr = realloc(students, (count + 1) * sizeof(struct student));
        if (new_ptr == NULL) {
            printf("Ошибка выделения памяти!\n");
            free(students);
            return 1;
        }
        students = new_ptr;

        strcpy(students[count].famil, temp_famil);

        printf("Введите имя: ");
        scanf("%19s", students[count].name);

        printf("Введите факультет: ");
        scanf("%19s", students[count].facult);

        printf("Введите номер зачетной книжки: ");
        scanf("%d", &students[count].Nomzach);

        count++;
        printf("\n");
    }

    if (count == 0) {
        printf("Список студентов пуст.\n");
        free(students);
        return 0;
    }

    char search_famil[20];
    printf("\nВведите фамилию (или её часть) для поиска: ");
    scanf("%19s", search_famil);

    printf("\nРезультаты поиска (неполное совпадение):\n");
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(students[i].famil, search_famil) != NULL) {
            printf("Найден студент: %s %s | Факультет: %s | № зачетки: %d\n",
                students[i].famil, students[i].name,
                students[i].facult, students[i].Nomzach);
            found = 1;
        }
    }

    if (!found) {
        printf("Студент с фамилией, содержащей \"%s\", не найден.\n", search_famil);
    }

    free(students);
    return 0;
}