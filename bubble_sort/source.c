#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *a, int n) {
    for (int i = 0; i < n-1; i++)
        for (int j =i+1; j < n; j++)
            if (a[i]>a[j])
                swap(a+i, a+j);
}

void printArr(int *a, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void input(int *a, int n) {
    for (int i = 0; i < n; i++)
        scanf("%d", a+i);
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    input(a, n);
    
    bubble_sort(a, n);

    printArr(a, n);

    return 0;
}