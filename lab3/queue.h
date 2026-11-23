#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct Queue {
    int size;
    Node *head;
    Node *tail;
} Queue;

Err create_queue(Queue **queue);
Err push(Queue *q, int value);
Err pop(Queue *q);
Err front(const Queue *q, int *front);
Err free_queue(Queue *q);

#endif