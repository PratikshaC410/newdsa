#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}*Node;

int isEmpty(Node top) {
    return top == NULL;
}

Node push(Node top, int data) {
    Node newNode = (Node)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Stack Overflow\n");
        return top; 
    }

    newNode->data = data;
    newNode->next = top;
    printf("%d pushed to stack\n", data);
    return newNode; 
}

Node pop(Node top) {
    if (isEmpty(top)) {
        printf("Stack Underflow\n");
        return NULL; // Indicate error
    }

    Node temp = top;
    int poppedData = temp->data;
    top = temp->next;
    free(temp);

    printf("%d popped from stack\n", poppedData);
    return top; 
}

int peek(Node top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

int main() {
    Node top = NULL;

    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);

    printf("Top element is %d\n", peek(top));
    top = pop(top);
    top = pop(top);

    printf("Top element is %d\n", peek(top));

    while (!isEmpty(top)) {
        top = pop(top);
    }

    return 0;
}
