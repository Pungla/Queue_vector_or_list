#include <stdio.h>
#include <stdlib.h>

// ��������� �������� �������
struct Node {
    int data;
    struct Node* next;
};

// ��������� �������
struct list_Queue {
    struct Node* first, * last;
};

// ������� ��� �������� ������ ��������
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// ������� ��� �������� ������ �������
struct list_Queue* list_createQueue() {
    struct list_Queue* q = (struct list_Queue*)malloc(sizeof(struct list_Queue));
    q->first = q->last = NULL;
    return q;
}

// ������� ��� ���������� �������� � �������
void list_enQueue(struct list_Queue* q, int data) {
    struct Node* temp = newNode(data);

    if (q->last == NULL) {
        q->first = q->last = temp;
        return;
    }

    q->last->next = temp;
    q->last = temp;
}

// ������� ��� �������� �������� �� �������
void list_deQueue(struct list_Queue* q) {
    if (q->first == NULL)
        return;

    struct Node* temp = q->first;
    q->first = q->first->next;

    if (q->first == NULL)
        q->last = NULL;

    free(temp);
}

// ������� ��� ��������� �������� �������� � ������ �������
int list_front(struct list_Queue* q) {
    if (q->first == NULL)
        return -1; // ��������� ������, ���� ������� �����
    return q->first->data;
}

// ������� ��� ��������� �������� �������� � ����� �������
int list_last(struct list_Queue* q) {
    if (q->last == NULL)
        return -1; // ��������� ������, ���� ������� �����
    return q->last->data;
}

// ������� ��� ��������, ����� �� �������
int list_isEmpty(struct list_Queue* q) {
    return (q->first == NULL && q->last == NULL);
}

// � ����� queue_vector.c ��������� ���������� �������
void list_printQueue(struct list_Queue* q) {
    if (q == NULL || list_isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* current = q->first;
    while (current != NULL) {
        printf("%c ", current->data);
        current = current->next;
    }
}

void list_clearQueue(struct list_Queue* q) {
    struct Node* current = q->first;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(q);
}