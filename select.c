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
        A[i] = rand()%1000;
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
int selectionSort(int n, int A[]) {
    int C=0;
    int M=0;
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            C++;
            if (A[j] < A[k]) { 
                k = j;
            }
        }
            M+=3;
            int temp = A[i];
            A[i] = A[k];
            A[k] = temp;
    }
    int T = M+C;
    return T;
    // printf("Число сравнений:%d\n",C);
    // printf("Число перемещений:%d\n",M);
    // printf("Трудоемкость:%d\n",M+C);
}
    
int upselectionSort(int n, int A[]) {
    int C=0;
    int M=0;
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            C++;
            if (A[j] < A[k]) { 
                k = j;
            }
        }
        if(A[i]!=A[k]){ // защита от фиктивности
            M+=3;
            int temp = A[i];
            A[i] = A[k];
            A[k] = temp;
        }
    }
    int T = M+C;
    return T;
    // printf("Число сравнений:%d\n",C);
    // printf("Число перемещений:%d\n",M);
    // printf("Трудоемкость:%d\n",M+C);
}

void printresult(int n, int A[]){
    int Tteor = (n*n-n)/2+3*(n-1);
    printf("|%3d|%10d|",n, Tteor);
    FillDec(n, A);
    int T = selectionSort(n, A);
    printf("%5d|", T);
    FillRand(n, A);
    T = selectionSort(n, A);
    printf("%5d|", T);
    FillInc(n, A);
    T = selectionSort(n, A);
    printf("%6d|", T);

    FillDec(n, A);
    T = upselectionSort(n, A);
    printf("%5d|", T);
    FillRand(n, A);
    T = upselectionSort(n, A);
    printf("%5d|", T);
    FillInc(n, A);
    T = upselectionSort(n, A);
    printf("%5d|\n", T);
}


int main() {
    int n = 10;
    int A[n];
    printf("|N  | M+C теор | Исходный Мф+Сф   | Улучшеный Мф+Сф |\n");
    printf("|   |          |убыв |случ |возр  |убыв |случ |возр |\n");
    printresult(n, A);
    n = 100;
    printresult(n, A);
    
    
    // //Работа с возрастающим массивом
    // FillInc(n, A);
    // printf("\nВозрастающий массив:\n");
    // PrintMas(n, A);
    // printf("Количество серий: %d\nКонтрольная сумма: %d\n", RunNumber(n, A), CheckSum(n, A));
    // selectionSort(n, A);
    // printf("\nОтсортированный возрастающий массив:\n");
    // PrintMas(n, A);
    // printf("Количество серий: %d\nКонтрольная сумма: %d\n", RunNumber(n, A), CheckSum(n, A));
    
    // //Работа с убывающим массивом
    // FillDec(n, A);
    // printf("\nУбывающий массив:\n");
    // PrintMas(n, A);
    // printf("Количество серий: %d\nКонтрольная сумма: %d\n", RunNumber(n, A), CheckSum(n, A));
    // selectionSort(n, A);
    // printf("\nОтсортированный убывающий массив:\n");
    // PrintMas(n, A);
    // printf("Количество серий: %d\nКонтрольная сумма: %d\n", RunNumber(n, A), CheckSum(n, A));
    
    
    // //Работа с рандомным массивом
    // FillRand(n, A);
    // printf("\nСлучайный массив:\n");
    // PrintMas(n, A);
    // printf("Количество серий: %d\nКонтрольная сумма: %d\n", RunNumber(n, A), CheckSum(n, A));
    // selectionSort(n, A);
    // printf("\nОтсортированный рандомный массив:\n");
    // PrintMas(n, A);
    // printf("Количество серий: %d\nКонтрольная сумма: %d\n", RunNumber(n, A), CheckSum(n, A));
    return 0;
}