#include "headers/simply_linked_list.h"

void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListNode* create_node(element data, ListNode* link) {
    ListNode* ret = (ListNode*) malloc(sizeof(ListNode));
    ret->data = data;
    ret->link = link;
    return ret;
}

void insert_node(ListNode** phead, ListNode* p, ListNode* new_node) {
    if(!p) {
        new_node->link = *phead;
        *phead = new_node;
    }
    else {
        new_node->link = p->link;
        p->link = new_node;
    }
}

void remove_node(ListNode** phead, ListNode* p) {
    if(!p) {
        ListNode* nxt = (*phead)->link;
        free(*phead);
        *phead = nxt;
    }
    else if(p->link) {
        ListNode* nxt = p->link;
        p->link = nxt->link;
        free(nxt);
    }
    else error("prv has no next node in function: remove_node");
}

void display(ListNode* head) {
    while(head) {
        printf("%d ", head->data);
        head = head->link;
    }
    printf("\n");
}

ListNode* search(ListNode* head, element x) {
    while(head) {
        if(head->data == x) {
            printf("search succeeded: %d\n", x);
            return head;
        }
        head = head->link;
    }
    printf("search failed: %d\n", x);
    return NULL;
}

ListNode* concat(ListNode* head1, ListNode* head2) {
    ListNode* curr = head1;
    while(curr->link) curr = curr->link;
    curr->link = head2;
    return head1;
}

ListNode* reverse(ListNode* head) {
    ListNode* trail = NULL;
    ListNode* middle = NULL;
    while(head) {
        trail = middle;
        middle = head;
        head = head->link;
        middle->link = trail;
    }
    return middle;
}

/*
int main() {
    ListNode* list1 = NULL;
    ListNode* list2 = NULL;

	printf("\n [ insert ] \n");
    
	insert_node(&list1, NULL, create_node(10, NULL));
	insert_node(&list1, NULL, create_node(20, NULL));
	insert_node(&list1, NULL, create_node(30, NULL));
    
    //list1: 30 -> 20 -> 10
	printf("list1: ");
	display(list1);

	printf("\n[ delete ] \n");
	remove_node(&list1, NULL);
	printf("list1: ");
	display(list1);

	printf("\n[ search ] \n");
	search(list1, 20);
	search(list1, 90);

	printf("\n[ insert ] \n");
	insert_node(&list2, NULL, create_node(60, NULL));
	insert_node(&list2, NULL, create_node(70, NULL));
	insert_node(&list2, NULL, create_node(80, NULL));
	printf("list2: ");
	display(list2);

	//list1 = list1 + list2
	printf("\n[ concat ]\n");
	list1 = concat(list1, list2);
	printf("list1: ");
	display(list1);

	printf("\n[ reverse ]\n");
	list1= reverse(list1);
	printf("list1: ");
	display(list1);
	return 0;
}
*/