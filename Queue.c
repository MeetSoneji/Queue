#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Queue {
    struct Node* front;
    struct Node* rear;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    queue->front = queue->rear = NULL;
    return queue;
}
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("%d enqueued to the queue.\n", data);
}
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow!\n");
        exit(1);
    }
    struct Node* temp = queue->front;
    int dequeued = temp->data;
    queue->front = queue->front->next;
    free(temp);
    return dequeued;
}
int front(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        exit(1);
    }
    return queue->front->data;
}
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements:\n");
    struct Node* temp = queue->front;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
int main() {
    struct Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Front element: %d\n", front(queue));
    display(queue);
    return 0;
}
