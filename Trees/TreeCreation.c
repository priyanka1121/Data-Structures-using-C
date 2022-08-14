#include<stdio.h>
#include<stdlib.h>

typedef struct treenode{
    int data;
    struct treenode *left;
    struct treenode *right;
}treenode;

treenode *create(int x){
    treenode *node = malloc(sizeof(treenode));
    if(node != NULL){
        node->left = NULL;
        node->right = NULL;
        node->data = x;

    }
    return node;

}

void print(treenode *root){
    if(root == NULL){
        printf("Empty tree!! \n");
        return;
    }
    printf("Value = %d\n", root->data);
    printf("left\n");
    print(root->left);
    printf("Right\n");
    print(root->right);
}


int main() {
    treenode *n1 = create(1);
    treenode *n2 = create(2);
    treenode *n3 = create(3);
    treenode *n4 = create(4);
    treenode *n5 = create(5);

    n1->left = n2;
    n2->left = n3;
    n3->left = n4;
    n3->right = n5;
    
    print(n1);


    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
}