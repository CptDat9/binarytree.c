#include <stdio.h>
#include <stdlib.h>

typedef struct tnode {
    int data;
    struct tnode *pLeft, *pRight;
} tnode;

tnode *root = NULL;

tnode *newNode(int data) {
    tnode *node = (tnode*)malloc(sizeof(tnode));
    node->data = data;
    node->pLeft = NULL;
    node->pRight = NULL;
    return node;
}

void insertNode(tnode* p, int value) {
    tnode *node = newNode(value);
    if (p->pLeft == NULL) {
        p->pLeft = node;
    } else if (p->pRight == NULL) {
        p->pRight = node;
    } else {
        node->pLeft = p->pLeft;
        p->pLeft = node;
    }
}

void insertNewRoot(int value) {
    tnode *node = newNode(value);
    node->pLeft = root;
    root = node;
}

void NLR(tnode *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        NLR(root->pLeft);
        NLR(root->pRight);
    }
}

void LRN(tnode *root) {
    if (root != NULL) {
        LRN(root->pLeft);
        LRN(root->pRight);
        printf("%d ", root->data);
    }
}

void LNR(tnode *root) {
    if (root != NULL) {
        LNR(root->pLeft);
        printf("%d ", root->data);
        LNR(root->pRight);
    }
}

int main() {
    // Tạo các node
    root = newNode(1);
    tnode *node2 = newNode(2);
    tnode *node3 = newNode(3);
    tnode *node4 = newNode(4);
    tnode *node5 = newNode(5);
    tnode *node6 = newNode(6);
    tnode *node7 = newNode(7);

    // Gán các node con
    root->pLeft = node2;
    root->pRight = node3;
    node2->pLeft = node4;
    node2->pRight = node5;
    node5->pLeft = node6;
    node5->pRight = node7;

    // Duyệt cây nhị phân theo NLR
    printf("Traverse tree with NLR: ");
    NLR(root);

    // Duyệt cây theo LNR
    printf("\nTraverse tree with LNR: ");
    LNR(root);

    // Duyệt cây theo LRN
    printf("\nTraverse tree with LRN: ");
    LRN(root);

    // Chèn node mới vào cây
    insertNode(node2, 9);

    // Duyệt cây nhị phân theo NLR sau khi chèn node mới
    printf("\nTraverse tree with NLR after insert: ");
    NLR(root);

    return 0;
}
