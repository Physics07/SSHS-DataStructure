#ifndef QUEUE
#define QUEUE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "simply_linked_list.h"

#ifndef QueueNode
#define QueueNode ListNode
#endif /* QueueNode */


void print_queue(QueueNode*);
void enQueue(QueueNode**, QueueNode**, element);
element deQueue(QueueNode**, QueueNode**);
int is_queue_empty(QueueNode*);


#endif /* QUEUE */