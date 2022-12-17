#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    char name[256];
    int age;
    int ID;
    float weight;
    float height;

    struct Person *pLeft;
    struct Person *pRight;
} person;

person *makeNode(char *name, int ID, int age, float w, float h) {
    person *ptr = (person *)malloc(sizeof(person));

    strcpy(ptr->name, name);
    ptr->age = age;
    ptr->ID = ID;
    ptr->height = h;
    ptr->weight = w;
    ptr->pLeft = NULL;
    ptr->pRight = NULL;

    return ptr;
}

person *findPerson(person *tree, int ID) {
    if (tree == NULL)
        return NULL;
    if (tree->ID == ID)
        return tree;
    
    person *ptr = findPerson(tree->pLeft, ID);
    if (ptr != NULL)
        return ptr;
    return findPerson(tree->pRight, ID);
}

person *addRight(person *tree, int ID1, char *name, int ID, int age, float w, float h) {
    return makeNode(name, ID, age, w, h);
}

person *insertTree(person *tree, int ID1, char *name, int ID, int age, float w, float h) {
    if (tree == NULL)
        return makeNode(name, ID, age, w, h);
    else {
        person *ptr = findPerson(tree, ID1);

        if (ptr == NULL) {
            return NULL;
        }

        if (ptr->pLeft == NULL)
            ptr->pLeft = addRight(ptr->pLeft, ID1, name, ID, age, w, h);
        else if (ptr->pRight == NULL)
            ptr->pRight = addRight(ptr->pRight, ID1, name, ID, age, w, h);
    }

    return tree;   
}

void printTree(person *root) {
    if (root != NULL) {
        printf("%s(%d) ", root->name, root->ID);
        printTree(root->pLeft);
        printTree(root->pRight);
    }
}

void printPerson(person *tree) {
    int ID;
    printf("Cin ID find: ");
    scanf("%d", &ID);

    person *ptr = findPerson(tree, ID);

    if (ptr == NULL) {
        printf("Can't find %d.", ID);
        return;
    }

    if (ptr->pLeft != NULL)
        printf("%s - %d         ", ptr->pLeft->name, ptr->pLeft->ID);
    if (ptr->pRight != NULL)
        printf("%s - %d", ptr->pRight->name, ptr->pRight->ID);
}

int height(person *tree) {
    if (tree == NULL)
        return 0;
    int max = 0;

    int hl = height(tree->pLeft);
    if (max < hl)
        max = hl;
    int hr = height(tree->pRight);
    if (max < hr)
        max = hr;
    
    return max+1;
}

int count(person *tree) {
    if (tree == NULL)
        return 0;
    else 
        return 1+count(tree->pLeft)+count(tree->pRight);
}

int main() {
    person *root;
    root = NULL;

    int i = 1;
    int age;
    int ID;
    float w;
    float h;
    int ID1;

TRY:
    system("cls");
    printf("===================MENU===============\n");
    printf("1. Nhap du lieu person cho cay.\n");
    printf("2. In du lieu cua cay.\n");
    printf("3. In trai, phai cua mot person.\n");
    printf("4. Tinh chieu cao tu mot person.\n");
    printf("5. Tinh tong so node cua cay.\n");
    printf("0. Thoat menu.\n");
    printf("======================================\n");
    printf("Chon chuc nang: ");
    int n;
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        system("cls");
        while (i != 0) {
            char name[256];

            int checkWhile;
            printf("Cin -1 to break: ");
            scanf("%d", &checkWhile);
            if (checkWhile == -1)
                break;

            getchar();
            printf("Cin name of person - %d: ", i);
            fgets(name, sizeof(name), stdin);
            name[strlen(name)-1] = '\0';

            printf("Cin ID - %d: ", i);
            scanf("%d", &ID);

            printf("Cin age - %d: ", i);
            scanf("%d", &age);

            printf("Cin weight - %d: ", i);
            scanf("%f", &w);

            printf("Cin height - %d: ", i);
            scanf("%f", &h);

            printf("Cin ID1 - %d: ", i);
            scanf("%d", &ID1);

            if (findPerson(root, ID1) == NULL && root != NULL) 
                printf("Err.\n");
            else {
                printf("Cin success.\n");
                root = insertTree(root, ID1, name, ID, age, w, h);
            }
            
            printf("=======================\n");
            i++;
        }
        system("pause");
        goto TRY;

    case 2:
        system("cls");
        printTree(root);  
        printf("\n");
        system("pause");
        goto TRY;

    case 0:
        break;

    case 3:
        system("cls");
        printPerson(root);
        printf("\n");
        system("pause");
        goto TRY;
    case 4:
        system("cls");
        printf("Cin ID: ");
        scanf("%d", &ID);
        person *ptr = findPerson(root, ID);
        if (ptr != NULL)
            printf("Max length: %d\n", height(root));
        else
            printf("NULL.\n");
        system("pause");
        goto TRY;
    
    case 5:
        system("cls");
        printf("Max count: %d\n", count(root));
        system("pause");
        goto TRY;
    default:
        goto TRY;
    }
    return 0;
}