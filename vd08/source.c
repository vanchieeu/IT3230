#include <stdio.h>
#include <stdlib.h>

typedef struct nodeTree {
    int ID, fID, mID;
    float weight, hight, length;

    struct nodeTree *pLeft;
    struct nodeTree *pRight;
} nodeTree;

nodeTree *makeNode(int ID, int fID, int mID, float w, float h, float l) {
    nodeTree *ptr = (nodeTree *)malloc(sizeof(nodeTree));

    ptr->fID = fID;
    ptr->hight = h;
    ptr->ID = ID;
    ptr->length = l;
    ptr->mID = mID;
    ptr->weight = w;
    ptr->pLeft = NULL;
    ptr->pRight = NULL;

    return ptr;
}

nodeTree* find(nodeTree *tree, int ID) {
    if (tree == NULL)
        return NULL;
    if (tree->ID == ID)
        return tree;

    nodeTree *ptr = tree->pLeft;
    while (ptr != NULL) {
        nodeTree *q = find(ptr, ID);
        if (q != NULL)
            return q;
        
        ptr = ptr->pRight;
    }
}

nodeTree *addLast(nodeTree *tree, int ID, int fID, int mID, float w, float h, float l) {
    if (tree == NULL)
        return makeNode(ID, fID, mID, w, h, l);
    
    tree->pRight = addLast(tree->pRight, ID, fID, mID, w, h, l);
    return tree;
}

nodeTree *insertNodeTree(nodeTree *tree, int ID, int fID, int mID, float w, float h, float l) {
    if (tree == NULL)
        return makeNode(ID, fID, mID, w, h, l);
    else {
        nodeTree *ptr = find(tree, mID);

        if (ptr == NULL)
            return NULL;
        
        ptr->pLeft = addLast(ptr->pLeft, ID, fID, mID, w, h, l);
    }

    return tree;
}

void printTree(nodeTree *root) {
    if (root != NULL) {
        printf("%d ", root->ID);
        printTree(root->pLeft);
        printTree(root->pRight);
    }
}

int height(nodeTree *tree) {
    if (tree == NULL)
        return 0;

    int max = 0;
    nodeTree *ptr = tree->pLeft;
    while (ptr != NULL) {
        int h = height(ptr);
        if (h > max)
            max = h;
        
        ptr = ptr->pRight;
    }

    return max + 1;
}

int count(nodeTree *tree) {
    if (tree == NULL)
        return 0;
    
    int cnt = 1;
    nodeTree *ptr = tree->pLeft;
    while (ptr != NULL) {
        cnt += count(ptr);
        ptr = ptr->pRight;
    }

    return cnt;
}

int main() {
    nodeTree *root;
    root = NULL;

    printf("Cin count goat: ");
    int n;
    scanf("%d", &n);

    printf("==========================\n");
    int ID, fID, mID;
    float w, h, l;

    for (int i = 1; i <= n; i++) {
        printf("Cin ID %d: ", i);
        scanf("%d", &ID);

        printf("Cin fID %d: ", i);
        scanf("%d", &fID);

        printf("Cin mID %d: ", i);
        scanf("%d", &mID);

        printf("Cin weight %d: ", i);
        scanf("%f", &w);

        printf("Cin hight %d: ", i);
        scanf("%f", &h);

        printf("Cin length %d: ", i);
        scanf("%f", &l);

        if (find(root, mID) == NULL && root != NULL) {
            printf("    -> Error & Can't cin the goat.\n");
        } else {
            printf("    -> Cin successful.\n");
            root = insertNodeTree(root, ID, fID, mID, w, h, l);
        }
        printf("==========================\n");
    }

    printTree(root);
    printf("\n==========================\n");
    printf("Height of tree: %d", height(root));
    printf("\n==========================\n");
    printf("Count of goat: %d", count(root));
    return 0;
}