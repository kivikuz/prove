#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <limits.h>

int InputArray();
void selectionSort(int a[], int size);
void Generator(int a[], int size1);
void ResultWrite(int a[], int size1);

int main() {
    int* a, size;
    srand(time(0));
    setlocale(LC_ALL, "Rus");

    size = InputArray();
    a = (int*)malloc(size * sizeof(int));

    Generator(a, size);

    clock_t start = clock();
    selectionSort(a, size);
    clock_t stop = clock();

    ResultWrite(a, size);

    printf("Время выполнения алгоритма: %.3f секунд\n", ((double)(stop - start)) / CLOCKS_PER_SEC);
    free(a);
    return 0;
}

int InputArray() {
    int input;
    while (1) {
        printf("Введите размер массива: ");

        if (scanf("%d", &input) != 1) {
            // Очистка буфера ввода при ошибке
            while (getchar() != '\n');
            printf("Ошибка: введено не число. Пожалуйста, введите целое число.\n");
            continue;
        }

        if (input < 2) {
            printf("Ошибка: значение должно быть не меньше 2.\n");
        }
        else {
            break;
        }
    }
    return input;
}

void selectionSort(int a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }
}

void Generator(int a[], int size1) {
    FILE* file = fopen("original.txt", "w");
    printf("Сгенерированный массив в файле original.txt\n");
    for (int i = 0; i < size1; i++) {
        a[i] = (rand() % 2000) - 1000;
        fprintf(file, "%d ", a[i]);
    }
    fclose(file);
}

void ResultWrite(int a[], int size1) {
    FILE* file = fopen("sorted.txt", "w");
    printf("\nОтсортированный по возрастанию массив в файле sorted.txt\n");
    for (int i = 0; i < size1; i++) {
        fprintf(file, "%d ", a[i]);
    }
    
}