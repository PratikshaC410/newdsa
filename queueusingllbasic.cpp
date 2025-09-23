#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}*Node;

Node enqueue(Node head, int data) {
    Node newNode = (Node)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node temp = head;
        while (temp->next != NULL) { // traverse to end
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("%d enqueued\n", data);
    return head; // return updated head
}

Node dequeue(Node head) {
    if (head == NULL) {
        printf("Queue Underflow\n");
        return NULL;
    }

    Node temp = head;
    int data = temp->data;
    head = head->next;
    free(temp);

    printf("%d dequeued\n", data);
    return head; // return updated head
}

void printQueue(Node head) {
    Node temp = head;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node head = NULL;

    head = enqueue(head, 10);
    head = enqueue(head, 20);
    head = enqueue(head, 30);

    printQueue(head);

    head = dequeue(head);
    head = dequeue(head);

    printQueue(head);

    return 0;
}
