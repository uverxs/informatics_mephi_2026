#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h> 

bool input(int* n, int min, int max) { 
    while (true) { 
        long long int long_n;
        char ch = 0;

        int scan = scanf("%lld%c", &long_n, &ch); 
        
        if (scan == -1) { 
            clearerr(stdin); 
            printf("\nпопробуйте другой ввод: ");
            continue;
        }
        
        if (scan == 2 && ch == '\n') { 
            if (long_n >= min && long_n <= max) {
                *n = (int)long_n;
                return true;
            }    
            printf("вводите числа от %d до %d: ", min, max);
            continue;
        }

        if (scan == 0) {
            char exit_ch = 0;
            char check_enter = 0; 
            
            int res = scanf(" %c%c", &exit_ch, &check_enter);
            
            if (res >= 1 && (exit_ch == 'e' || exit_ch == 'E')) {
                if (res == 1 || check_enter == '\n') {
                    return false;
                }
            }
        }

        scanf("%*[^\n]");
        scanf("%*c");
        printf("\nпопробуйте другой ввод: ");
    }
}

int init_array(int **array) {
    int size = 0;       
    int capacity = 10;  
    int* arr = malloc(capacity * sizeof(int));
    if (arr == NULL) {
        printf("Ошибка выделения памяти для массива.\n");
        return -1;
    }

    while (true) {
        if (size == capacity) {
            capacity += 10;
            int* temp = realloc(arr, capacity * sizeof(int));
            if (temp == NULL) {
                printf("Ошибка выделения памяти для массива.\n");
                free(arr);
                return -1;
            }
            arr = temp;
            printf("Выделение памяти\nsize = %d\ncapacity = %d\n", size, capacity);
        }

        printf("Введите число от -1000000 до 1000000 (или 'e' для выхода): ");
        
        if (!input(&arr[size], -1000000, 1000000)) {
            break;
        }
        size++;
    }

    *array = arr;
    return size;
}

void menu() {
    printf("\n==================================MENU====================================\n");
    printf("выберите один из предложенных вариантов для текущих матриц A и B:\n");
    printf(" 1 - Вывести текущие матрицы A и B на экран\n");
    printf(" 2 - Создать новые матрицы А и B\n");
    printf(" 3 - Сложить матрицы (A + B)\n");
    printf(" 4 - Вычесть матрицы (A - B)\n");
    printf(" 5 - Умножение матриц (A * B)\n");
    printf(" 6 - Траспонирование матрицы A\n");
    printf(" 7 - Возвести матрицы A в степень\n");
    printf(" 8 - Поиск определителя матрицы A\n");
    printf(" 9 - Поменять матрицы A и B местами\n");
    printf(" 0 - Для завершения работы программы\n");
    printf("==========================================================================\n");
}

int main(int argc, char** argv) {
    int *arr = NULL;
    int size = 0;
    if (argc == 3 && argv[1] != "--file") {
        // открытие и чтение из файла
    } else if (argc == 1) {
        size = init_array(&arr);
        if (size == -1) {
            return 1;
        }
    } else {
        printf("Bad arguments\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
