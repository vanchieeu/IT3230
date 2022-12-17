#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort(int *a, int n) {
    for (int i = 0; i < n-1; i++) {
        int index = i;
        for (int j =  i + 1; j < n; j++) {
            if (a[j]<a[i])
                index = j;
        }
        swap(a+i, a+index);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", a+i);
    
    insertion_sort(a, n);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}