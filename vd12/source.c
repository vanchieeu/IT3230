#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Hàm itoa dùng để convert số thành string!!

typedef struct person {
    char name[100];
    char birthday[100];
} person;

void insertInfo(person *info, int n) {
    // Tạo dữ liệu random
    char Ho[10][100] = {"Nguyen", "Tran", "Le", "Ly", "Pham", "Bui", "Dang", "Vu", "Hoang", "Mai"};
    char Dem[10][100] = {" Van ", " Dac ", " The ", " Minh ", " Gia ", " Quoc ", " Duc ", " Si ", " Thi ", " Ich "};
    char Ten[10][100] = {"An", "Bao", "Cong", "Dung", "Giang", "Hoa", "Kien", "Long", "Minh", "Nam"};
    
    for (int i = 0; i < n; i++) {
        // Random Full Name
        strcpy(info[i].name, Ho[rand()%10]);
        strcat(info[i].name, Dem[rand()%10]);
        strcat(info[i].name, Ten[rand()%10]);

        // Random ngày tháng năm sinh
        char s[100];
        int n = rand()%(31-1+1)+1;

        // Ngày
        if (n < 10) { // Nếu ngày nhỏ hơn 10 thì thêm số 0 ở đằng trước
            info[i].birthday[0] = '0';
            strcat(info[i].birthday, itoa(n, s, 10));
        } else
            strcpy(info[i].birthday, itoa(n, s, 10));
        strcat(info[i].birthday, "-");

        // Tháng
        n = rand()%(12-1+1)+1;
        if (n < 10) { // Nếu tháng nhỏ hơn 10 thì thêm số 0 ở đằng trước
            strcat(info[i].birthday, "0"); 
            strcat(info[i].birthday, itoa(n, s, 10));
        } else
            strcat(info[i].birthday, itoa(n, s, 10));
        strcat(info[i].birthday, "-");

        // Năm
        n = rand()%(2010-1990+1)+1990;
        strcat(info[i].birthday, itoa(n, s, 10));
    }
}

void printMinMax(person *info, int n) {
    //int min, max;
    //printf("Cin min: ");
    //scanf("%d", &min);
    //printf("Cin max: ");
    //scanf("%d", &max);


    // Xét trường hợp in tất cả, không sử dụng min max
    for (int i = 0; i < n; i++) {
        printf("Person %d:\n", i+1);
        printf("        ");
        printf("%s\n        %s\n", info[i].name, info[i].birthday);
    }
}

void swap(person *a, person *b) {
    person temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm quicksort theo yêu cầu đề bài
void quickSort(person *info, int l, int r) {
    person ptr = info[(l+r)/2];
    int i = l, j = r;

    while (i < j) {
        while (strcmp(info[i].name, ptr.name) < 0)
            i++;
        while (strcmp(info[j].name, ptr.name) > 0)
            j--;
        
        if (i <= j) {
            swap(info+i, info+j);

            i++;
            j--;
        }
    }

    if (i < r)
        quickSort(info, i, r);
    if (l < j)
        quickSort(info, l, j);
}

void sortBirth(person *info, int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j<n;j++)
            if (info[i].name == info[j].name && strcmp(info[i].birthday, info[j].birthday) > 0)
                swap(info+i, info+j);
}

int main() {
    srand(time(NULL));
    person info[100];

    int n;
    printf("Cin n person: ");
    scanf("%d", &n);

    // Random info 
    insertInfo(info, n);

    // In dữ liệu thử (chưa xếp)
    printMinMax(info, n);

    // Xếp và in dữ liệu 
    quickSort(info, 0, n-1);
    printf("\nSort name:\n");
    printMinMax(info, n);

    // Xếp và in dữ liệu
    sortBirth(info ,n);
    printf("\nSort name + birthday:\n");
    printMinMax(info, n);
    return 0;
}