#include "headers/stack.h"

void print_stack(StackNode* stk) {
    printf("[ STACK ] : ");
    for(StackNode* curr = stk; curr; curr = curr->link) {
        printf("%d ", curr->data);
    }
    printf("\n");
}

void push(StackNode** stk, element data) {
    StackNode* curr = create_node(data, NULL);
    insert_node(stk, NULL, curr);
}

element pop(StackNode** stk) {
    if(!(*stk)) error("stack is empty in function: pop\n");
    element ret = (*stk)->data;
    remove_node(stk, NULL);
    return ret;
}

int is_stack_empty(StackNode* stk) {
    return !stk;
}