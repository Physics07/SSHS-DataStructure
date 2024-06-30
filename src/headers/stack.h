#ifndef STACK
#define STACK

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "simply_linked_list.h"

#ifndef StackNode
#define StackNode ListNode
#endif /* StackNode */


void print_stack(StackNode*);
void push(StackNode**, element);
element pop(StackNode**);
int is_stack_empty(StackNode*);


#endif /* STACK */