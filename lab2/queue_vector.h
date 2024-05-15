#include <stdio.h>
#include <stdlib.h>

struct vector_Queue {
    int* items;
    int front;
    int last;
    int capacity;
};

struct vector_Queue* vector_createQueue() {
    struct vector_Queue* q = (struct vector_Queue*)malloc(sizeof(struct vector_Queue));
    q->capacity = 1; // Начальная емкость
    q->items = (int*)malloc(q->capacity * sizeof(int));
    q->front = -1;
    q->last = -1;
    return q;
}

int vector_isEmpty(struct vector_Queue* q) {
    return q->front == -1;
}

void resizeQueue(struct vector_Queue* q) {
    q->capacity ++;
    q->items = (int*)realloc(q->items, q->capacity * sizeof(int));
    if (q->items == NULL) {
        printf("Memory reallocation failed\n");
        exit(1);
    }
}

void vector_enQueue(struct vector_Queue* q, int value) {
    if (vector_isEmpty(q)) {
        q->front = 0;
        q->last = 0;
    }
    else if ((q->last + 1) % q->capacity == q->front) {
        resizeQueue(q);
        q->last = (q->last + 1) % q->capacity;
    }
    else {
        q->last = (q->last + 1) % q->capacity;
    }
    q->items[q->last] = value;
}

void vector_deQueue(struct vector_Queue* q) {
    if (vector_isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    else if (q->front == q->last) {
        q->front = -1;
        q->last = -1;
    }
    else {
        //q->front = (q->front + 1) % q->capacity;
        q->front = (q->front + 1);
    }
}

int vector_front(struct vector_Queue* q) {
    if (vector_isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->items[q->front];
}

int vector_last(struct vector_Queue* q) {
    if (vector_isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->items[q->last];
}

void vector_clearQueue(struct vector_Queue* q) {
    free(q->items);
    free(q);
}

void vector_printQueue(struct vector_Queue* q) {
    if (vector_isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front; i <= q->last; i++) {
        printf("%c ", q->items[i]);
    }
}