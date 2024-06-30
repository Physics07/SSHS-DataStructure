#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/stack.h"

StackNode* stk;
char eq[100], res[100];

static char* oper = "()+-*/%";
static int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0 };
static int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 };

int to_idx(char c) {
    switch(c) {
        case '(': return 0;
        case ')': return 1;
        case '+': return 2;
        case '-': return 3;
        case '*': return 4;
        case '/': return 5;
        case '%': return 6;
        default: return 7;
    }
}

int main() {
    scanf("%s", eq); // infix equation with only one digit numbers
    int n = strlen(eq);

    // transforming into postfix equation
    int idx = 0;
    for(int i=0; i<=n; i++) {
        if(eq[i] - '0' >= 0 && eq[i] - '0' <= 9) {
            res[idx++] = eq[i];
            continue;
        }
        int curr = to_idx(eq[i]);
        if(eq[i] != ')') {
            while(!is_stack_empty(stk) && isp[to_idx((char) stk->data)] >= icp[curr]) {
                if((char) stk->data != '(') res[idx++] = (char) stk->data;
                pop(&stk);
            }
            push(&stk, eq[i]);
        }
        else {
            while(!is_stack_empty(stk) && (char) stk->data != '(') {
                res[idx++] = (char) stk->data;
                pop(&stk);
            }
            pop(&stk);
        }
    }
    while(!is_stack_empty(stk)) pop(&stk);
    printf("%s\n", res);

    // calculating the postfix equation
    n = strlen(res);
    for(int i=0; i<n; i++) {
        if(res[i] - '0' >= 0 && res[i] - '0' <= 9) {
            push(&stk, res[i] - '0');
            continue;
        }
        int right = pop(&stk);
        int left = pop(&stk);
        int curr = 0;
        if(res[i] == '+') curr = left + right;
        if(res[i] == '-') curr = left - right;
        if(res[i] == '*') curr = left * right;
        if(res[i] == '/') curr = left / right;
        if(res[i] == '%') curr = left % right;
        push(&stk, curr);
    }
    printf("%d\n", stk->data);
}