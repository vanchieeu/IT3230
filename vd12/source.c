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
    char Ho[10][100] = {"Nguyen", "Tran", "Le", "Ly", "Pham", "Bui", "Dang", "Vu", "Hoang", "Mai"};
    char Dem[10][100] = {" Van ", " Dac ", " The ", " Minh ", " Gia ", " Quoc ", " Duc ", " Si ", " Thi ", " Ich "};
    char Ten[10][100] = {"An", "Bao", "Cong", "Dung", "Giang", "Hoa", "Kien", "Long", "Minh", "Nam"};
    
    for (int i = 0; i < n; i++) {
        printf("Person %d:\n", i+1);
        printf("        ");

        strcpy(info[i].name, Ho[rand()%10]);
        strcat(info[i].name, Dem[rand()%10]);
        strcat(info[i].name, Ten[rand()%10]);

        info[i].birthday[0] = (char)(rand()%(3-0+1)+48);
        if (info[i].birthday[0] == '3')
            info[i].birthday[1] = (char)(rand()%2+48);
        else if (info[i].birthday[0] == '0')
            info[i].birthday[1] = (char)(rand()%(9-1+1)+1+48);
        else
            info[i].birthday[1] = (char)(rand()%10+48);
        info[i].birthday[2] = '-';
        info[i].birthday[3] = (char)(rand()%2+48);
        if (info[i].birthday[3] == '0')
            info[i].birthday[4] = (char)(rand()%(9-1+1)+1+48);
        else
            info[i].birthday[4] = (char)(rand()%2+48);
        info[i].birthday[5] = '-';
        info[i].birthday[6] = (char)(rand()%2+1+48);
        if (info[i].birthday[6] == '1') {
            info[i].birthday[7] = '9';
            info[i].birthday[8] = '9';
            info[i].birthday[9] = (char)(rand()%(9-1+1)+1+48);
        }
        else {
            info[i].birthday[7] = '0';
            info[i].birthday[8] = (char)(rand()%2+48);
            if (info[i].birthday[8] == '1')
                info[i].birthday[9] = '0';
            else
                info[i].birthday[9] = (char)(rand()%(9-1+1)+1+48);
        }

        printf("%s\n        %s\n", info[i].name, info[i].birthday);
    }
}


int main() {
    srand(time(NULL));
    person info[100];

    int n;
    printf("Cin n person: ");
    scanf("%d", &n);

    insertInfo(info, n);
    return 0;
}