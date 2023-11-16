// Code for Josephus Problem using Graph Theory
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* createCircularLinkedList(int n) {
    struct Node* head = NULL;
    struct Node* prev = NULL;

    for (int i = 1; i <= n; ++i) {
        struct Node* newNode = createNode(i);
        if (head == NULL) {
            head = newNode;
        } else {
            prev->next = newNode;
        }
        prev = newNode;
    }
    prev->next = head; 
    return head;
}

int josephus(struct Node* head, int k) {
    struct Node* current = head;
    struct Node* prev = NULL;

    while (current->next != current) {
        for (int i = 0; i < k - 1; ++i) {
            prev = current;
            current = current->next;
        }
        
        prev->next = current->next;
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    return current->data;
}
int main() {
    int n, k;
    printf("Enter the number of people in the circle: ");
    scanf("%d", &n);
    printf("Enter the elimination step (k): ");
    scanf("%d", &k);
    struct Node* head = createCircularLinkedList(n);
    int survivor = josephus(head, k);
    printf("The survivor is at position: %d\n", survivor);

    return 0;
}
