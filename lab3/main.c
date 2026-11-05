#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h> 

bool input(int* n, int min, int max) { 
    char ch;
    long long int long_n;
    while (true) { 
        int scan = scanf("%lld%c", &long_n, &ch); 
        int garbage;
        
        if (scan == -1 || scan == 1) { 
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

        while (true) { 
            garbage = getchar();
            if (garbage == '\n') break;
            
            if (garbage == -1) { 
                clearerr(stdin); 
                break; 
            }
        }
        printf("\nпопробуйте другой ввод: ");
    }
}

int* init_array(int size) {
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Ошибка выделения памяти для массива.\n");
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        printf("Введите элемент массива [%d]: ", i);
        input(&arr[i], -100, 100);
    }
    return arr;
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
    for (int i = 0; argv[i] != NULL; i++) {
        printf("%s, ", argv[i]);
    }
    printf("\n");
    return 0;
}
