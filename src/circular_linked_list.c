#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListNode *create_node(element data, ListNode* link) {
    ListNode* ret = (ListNode*) malloc(sizeof(ListNode));
    ret->data = data;
    ret->link = link;
    return ret;
}

void insert_node(ListNode** phead, ListNode* p, ListNode* new_node) {
    if(!(*phead)) {
        *phead = new_node;
        (*phead)->link = *phead;
        return;
    }
    if(!p) error("prv is NULL at function: insert_node");
    if(p == *phead) {
        // insert in the back
        new_node->link = p->link;
        p->link = new_node;
        *phead = new_node;
    }
    else {
        new_node->link = p->link;
        p->link = new_node;
    }
}

void remove_node(ListNode** phead, ListNode* p) {
    if(!p) error("prv is NULL at function: remove_node");
    if(!(*phead)) error("list is empty at function: remove_node");
    ListNode* nxt = p->link;
    if(nxt == *phead) {
        // if the target is head
        p->link = nxt->link;
        free(nxt);
        *phead = p;
    }
    else {
        p->link = nxt->link;
        free(nxt);
    }
}

void josephus(int n, int m) {
    ListNode* lst = NULL;
    for(int i=1; i<=n; i++) {
        ListNode* curr = create_node(i, NULL);
        insert_node(&lst, lst, curr);
    }
    ListNode* curr = lst;
    curr = curr->link;
    for(int i=1; i<=n; i++) {
        curr = curr->link;
        printf("%d ", curr->link->data);
        remove_node(&lst, curr);
        curr = curr->link;
    }
}

int main() {
    // solving josephus problem with circluar linked list
    josephus(41, 3);
}