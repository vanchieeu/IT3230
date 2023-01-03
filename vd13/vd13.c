#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    char name[256];
    char email[256];
    struct node *leftNode;
    struct node *rightNode;
} Node;

Node *makeNode(char *name, char *email) {
    Node *ptr = (Node *)malloc(sizeof(Node));
    strcpy(ptr->name, name);
    strcpy(ptr->email, email);
    ptr->leftNode = NULL;
    ptr->rightNode = NULL;
    return ptr;
}

Node *insertNode(Node *root, char *name, char *email) {
     if (root == NULL)
         return makeNode(name, email);

     int c = strcmp(name, root->name);
     if (c == 0) {
         printf("Đã tồn tại node.");
     } else if (c < 0) {
        root->rightNode = insertNode(root->rightNode, name, email);
    } else {
        root->leftNode = insertNode(root->leftNode, name, email);
    }
    return root;
}

Node *findNode(Node *root, char *name) {
    if (strcmp(root->name, name) == 0)
        return root;
    if (root == NULL)
        return NULL;
    if (strcmp(root->name, name) > 0)
        return findNode(root->rightNode, name);
    if (strcmp(root->name, name) < 0)
        return findNode(root->leftNode, name);
}

void printTree(Node *root) {
    if (root != NULL) {
        printf("Tên: %s\nEmail: %s\n=========\n", root->name, root->email);
        printTree(root->leftNode);
        printTree(root->rightNode);
    }
}

Node* findMin(Node* root){
    Node *ptr = root;

    while (ptr != NULL && ptr->leftNode != NULL) {
        ptr = ptr->leftNode;
    }
    return ptr;
}

Node *deleteNode(Node *root, char *name) {
    if (root == NULL)
        return NULL;

    int c = strcmp(name, root->name);
    if (c > 0)
        deleteNode(root->leftNode, name);
    else if (c < 0)
        deleteNode(root->rightNode, name);
    else {
        if (root->leftNode != NULL && root->rightNode != NULL) {
            Node *temp = findMin(root->rightNode);

            strcpy(root->name, temp->name);

            root->rightNode = deleteNode(root->rightNode, temp->name);
        } else {
            Node *temp = root;
            if (root->leftNode == NULL)
                root = root->rightNode;
            else
                root = root->leftNode;
            free(temp);
        }
    }
    return root;
}

int main() {
    Node *root = NULL;

    root = insertNode(root, "12", "email");
    root = insertNode(root, "15", "email");
    root = insertNode(root, "11", "email");
    root = insertNode(root, "14", "email");
    root = insertNode(root, "17", "email");
    root = insertNode(root, "19", "email");
    root = insertNode(root, "10", "email");

    root = deleteNode(root, "10");
    printTree(root);
    return 0;
}