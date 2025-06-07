#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Fillinc(int A[], int n){
    for(int i = 0; i < n; i++){
        A[i] = i + 1;
    }
}

void Filldec(int A[], int n){
    for(int i = 0; i < n; i++){
        A[i] = n-i;
    }
}

void Fillrand(int A[], int n) {
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        A[i] = rand() % 1000;
}
}
int Checksum(int A[], int n){
    int sum;
    for(int i=0; i < n ; i++){
        sum += A[i];
    }
    return sum;
}
int RunNumber(int A[], int n){
    if (n == 0) return 0;
    int series = 1;
    for(int i = 1; i < n; i++ ){
        if (A[i] < A[i-1]){
            series += 1;
        }
    }
    return series;
}
int PrintMas(int A[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}
int main() {
int n = 100;
int A[n];
Fillinc(A, n);
RunNumber(A, n);
printf("%d", RunNumber(A, n));
    return 0;
}
