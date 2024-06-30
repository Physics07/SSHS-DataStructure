#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* prv;
    struct ListNode* nxt;
} ListNode;

void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListNode* create_node(element data) {
    ListNode* ret = (ListNode*) malloc(sizeof(ListNode));
    ret->data = data;
    ret->nxt = ret->prv = NULL;
    return ret;
}

ListNode* create_list() {
    ListNode* curr = create_node(0);
    curr->nxt = curr->prv = curr;
    return curr;
}

void insert_node(ListNode* p, ListNode* new_node) {
    new_node->nxt = p->nxt;
    new_node->prv = p;
    p->nxt->prv = new_node;
    p->nxt = new_node;
}

void remove_node(ListNode* p) {
    p->prv->nxt = p->nxt;
    p->nxt->prv = p->prv;
    free(p);
}

void display(ListNode* head) {
    ListNode* curr = head->nxt;
    while(curr != head) {
        printf("%d ", curr->data);
        curr = curr->nxt;
    }
    printf("\n");
}

ListNode* search(ListNode* head, element x) {
    ListNode* curr = head->nxt;
    while(curr != head) {
        if(curr->data == x) {
            printf("search succeeded: %d\n", x);
            return curr;
        }
        curr = curr->nxt;
    }
    printf("search failed: %d\n", x);
    return NULL;
}

int main() {
    ListNode* list1 = create_list();

	printf("\n [ insert ] \n");
    
	insert_node(list1, create_node(10));
	insert_node(list1, create_node(20));
	insert_node(list1, create_node(30));

    //list1: 30 -> 20 -> 10
	printf("list1: ");
	display(list1);

	printf("\n[ delete ] \n");
	remove_node(list1->nxt);
	printf("list1: ");
	display(list1);

	printf("\n[ search ] \n");
	search(list1, 20);
	search(list1, 90);

	return 0;
}