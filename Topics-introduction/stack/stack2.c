#include <stdio.h>
#include <stdlib.h>
#include "stack_ll.h"

void bastir(node *root) {
    while(root != NULL){
        printf("%d ", root->data);
            root = root->next;
    }
}

int pop(node *root) {
    if(root == NULL) {
        printf("Stack is empty");
        return -1;
    }
    //tek d���m varsa
    if(root->next == NULL) {
        int rvalue = root->data;
        free(root);
        return rvalue;
    }
    node *iter = root;
    while(iter->next->next != NULL) {
        iter = iter->next;
    }
    node *temp = iter->next;
    int rvalue = temp->data;
    iter->next = NULL;
    free(temp);
    return rvalue;
}

node* push(node *root, int a) {
    if(root == NULL) {
        root = (node *)malloc(sizeof(node));
        root->data = a;
        root->next = NULL;
        return root;
    }
    node *iter = root;
    while(iter->next != NULL) {
        iter = iter->next;
    }
    node *temp = (node *)malloc(sizeof(node));
    temp->data = a;
    temp->next = NULL;
    iter->next = temp;
    return root;
}

int main() {

    node *s = NULL;
    s = push(s, 10);
    s = push(s, 20);
    s = push(s, 30);
    s = push(s, 40);
    s = push(s, 50);
    s = push(s, 60);

    printf("%d \n", pop(s));
    printf("%d \n", pop(s));

    s = push(s, 70);


    bastir(s);

    return 0;
}
