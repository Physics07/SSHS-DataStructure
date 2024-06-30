#ifndef SIMPLY_LINKED_LIST
#define SIMPLY_LINKED_LIST

#ifndef element
#define element int
#endif /* element */

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

void error(char*);
ListNode* create_node(element, ListNode*);
void insert_node(ListNode**, ListNode*, ListNode*);
void remove_node(ListNode**, ListNode*);
void display(ListNode*);
ListNode* search(ListNode*, element);
ListNode* concat(ListNode*, ListNode*);
ListNode* reverse(ListNode*);

#endif /* SIMPLY_LINKED_LIST */