#include "queue.h"
#include "err.h"
#include <stdio.h>
#include <stdlib.h>

Err create_queue(Queue **queue) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL) {
        return ERR_ALLOC;
    }
    q->size = 0;
    q->head = NULL;
    q->tail = NULL;
    *queue = q;
    return ERR_OK;
}

Err push(Queue *q, int value) {
    if (q == NULL) {
        return ERR_ARGUMENT;
    }

    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        return ERR_ALLOC;
    }

    node->value = value;
    node->next = NULL;

    if (q->tail == NULL) {
        q->head = node;
        q->tail = node;
    } else {
        q->tail->next = node;
        q->tail = node;
    }
    q->size++;
    return ERR_OK;
}

Err pop(Queue *q) {
    if (q == NULL || q->head == NULL) {
        return ERR_ARGUMENT;
    }

    Node *temp = q->head;
    q->head = q->head->next;
    free(temp);

    if (q->head == NULL) {
        q->tail = NULL;
    }
    q->size--;
    return ERR_OK;
}

Err front(const Queue *q, int *front) {
    if (q == NULL || q->head == NULL) {
        return ERR_ARGUMENT;
    }
    *front = q->head->value;
    return ERR_OK;
}

void free_queue(Queue *q) {
    if (q == NULL) {
        return;
    }
    Node *current = q->head;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }
    free(q);
}