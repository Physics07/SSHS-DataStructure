#include "headers/queue.h"

void print_queue(QueueNode* front) {
    printf("[ QUEUE ] : ");
    for(QueueNode* curr = front; curr; curr = curr->link) {
        printf("%d ", curr->data);
    }
    printf("\n");
}

void enQueue(QueueNode** front, QueueNode** back, element data) {
    QueueNode* curr = create_node(data, NULL);
    if(!(*front)) *front = *back = curr;
    else {
        (*back)->link = curr;
        *back = curr;
    }
}

element deQueue(QueueNode** front, QueueNode** back) {
    if(!(*front)) error("queue is empty in function: pop\n");
    element ret = (*front)->data;
    remove_node(front, NULL);
    if(!(*front)) *back = NULL;
    return ret;
}

int is_queue_empty(QueueNode* front) {
    return !front;
}