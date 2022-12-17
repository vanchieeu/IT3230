#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

typedef struct Person {
    char name[256];
    float weight;
    float height;
    int age;
    int ID;
} person;

void initPerson(person *a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            if (j == 0)
                a[i].name[j] = (char)(65 + rand() % (90 + 1 - 65));
            else
                a[i].name[j] = (char)(97 + rand() % (122 + 1 - 97));
        }
        a[i].name[5] = '\0';
        a[i].ID = i;
        a[i].weight = 30 + (rand() / (float)RAND_MAX) * (80.0 - 30.0);
        a[i].height = 1.6 + (rand() / (float)RAND_MAX) * (1.9 - 1.6);
        a[i].age = 16 + (rand() / (float)RAND_MAX) * (76 - 16);
    }
}

void swap(person *a, person *b) {
    person temp = *a;
    *a = *b;
    *b = temp;
}

void insertsort(person *a, int n) {
    for (int i = 0; i < n-1; i++) {
        int index = i;
        for (int j = i+1; j <n; j++)
            if (a[index].age > a[j].age)
                index = j;
        swap(a+i, a+index);
    }
}

void printArr(person *a, int n) {
    int left, right;
    printf("Cin Left: ");
    scanf("%d", &left);
    printf("Cin Right: ");
    scanf("%d", &right);
    while (left < 0 || right < 0 || left >= right || left > n) {
        printf("Cin left again: ");
        scanf("%d", &left);
        printf("Cin right again: ");
        scanf("%d", &right);
    }
    for (int i = left; i <= right; i++)
        printf("%s %.2f %.2f %d %d\n", a[i].name, a[i].height, a[i].weight, a[i].age, a[i].ID);
}

int main() {
    int n;
    scanf("%d", &n);

    person arr[n];
    initPerson(arr, n);

    insertsort(arr, n);

    printArr(arr, n);
    return 0;
}