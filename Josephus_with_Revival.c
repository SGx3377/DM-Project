// Josephus with revivals 
#include <stdio.h>
#include <stdlib.h>

// Queue structure for eliminated individuals
struct Queue {
    int* items;
    int front, rear, capacity;
};

// Create a new queue
struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->items = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Check if the queue is full
int isFull(struct Queue* queue) {
    return ((queue->rear + 1) % queue->capacity == queue->front);
}

// Check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

// Enqueue an element into the queue
void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % queue->capacity;
    }
    queue->items[queue->rear] = value;
}

// Dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }

    int removedValue = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    return removedValue;
}

// Function to solve the Josephus Problem with revivals
void josephusWithRevivals(int n, int k, int m) {
    int* circle = (int*)malloc(n * sizeof(int));
    struct Queue* eliminated = createQueue(n);

    for (int i = 0; i < n; ++i) {
        circle[i] = i + 1; // Initialize the circular arrangement
    }

    int index = 0;
    printf("Elimination sequence: ");

    while (n > 1) {
        for (int i = 0; i < m - 1; ++i) {
            index = (index + 1) % n; // Move to the next person
        }

        int eliminatedPerson = circle[index];
        printf("%d ", eliminatedPerson);

        enqueue(eliminated, eliminatedPerson); // Add to the eliminated queue

        for (int i = index; i < n - 1; ++i) {
            circle[i] = circle[i + 1]; // Shift remaining people in the circle
        }

        n--;

        if (n == 1) {
            break; // Exit loop if only one person is left
        }

        // Revive the first person in the queue and add them back to the circle
        int revivedPerson = dequeue(eliminated);
        circle[(index + m - 1) % n] = revivedPerson;

        index = (index + m - 1) % n; // Move index to the next person after revival
    }

    printf("\nSurvivor: %d\n", circle[0]);
    free(circle);
    free(eliminated->items);
    free(eliminated);
}

int main() {
    int n, k, m;
    printf("Enter the number of people (n): ");
    scanf("%d", &n);
    printf("Enter the k-th person to revive: ");
    scanf("%d", &k);
    printf("Enter the elimination count (m): ");
    scanf("%d", &m);

    josephusWithRevivals(n, k, m);
    return 0;
}
