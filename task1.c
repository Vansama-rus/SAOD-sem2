#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void FillInc(int n, int A[]) {
    for (int i = 0; i < n; i++) {
        A[i] = i + 1;
    }
}

void FillDec(int n, int A[]) {
    for (int i = 0; i < n; i++) {
        A[i] = n - i;
    }
}

void FillRand(int n, int A[]) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        A[i] = rand()%100;
    }
}

int CheckSum(int n, int A[]) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
    }
    return sum;
}

int RunNumber(int n, int A[]) {
    if (n == 0) return 0;
    int series = 1;
    for (int i = 1; i < n; i++) {
        if (A[i] < A[i - 1]) {
            series++;
        }
    }
    return series;
}

void PrintMas(int n, int A[]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

double leightS(int n, int A[]){
    if (n == 0) return 0;
    int count_series = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] < A[i - 1]) {
            count_series ++;
        }
    }
    double series = n/(double)count_series;
    return series;
}
int main() {
    int n = 10;
    int A[n];
    
    //Работа с возрастающим массивом
    FillInc(n, A);
    printf("\nВозрастающий массив:\n");
    PrintMas(n, A);
    printf("Количество серий: %d\n", RunNumber(n, A));
    
    //Работа с убывающим массивом
    FillDec(n, A);
    printf("\nУбывающий массив:\n");
    PrintMas(n, A);
    printf("Количество серий: %d\n", RunNumber(n, A));
    
    //Работа с рандомным массивом
    FillRand(n, A);
    printf("\nСлучайный массив:\n");
    PrintMas(n, A);
    printf("Количество серий: %d\n", RunNumber(n, A));
    printf("средняя длина серии: %.3lf\n",leightS(n, A));
}