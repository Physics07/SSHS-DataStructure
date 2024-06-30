#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char val;
    struct TreeNode* l;
    struct TreeNode* r;
} TreeNode;

TreeNode* root;

TreeNode* create_node(int x) {
    TreeNode* curr = (TreeNode*) malloc(sizeof(TreeNode));
    curr->val = x;
    curr->l = curr->r = NULL;
    return curr;
}

TreeNode* insert(TreeNode* tree, int x) {
    if(!tree) return create_node(x);
    TreeNode* curr = tree;
    while(curr) {
        if(curr->val == x) return tree;
        if(curr->val > x) {
            if(!curr->l) {
                curr->l = create_node(x);
                return tree;
            }
            curr = curr->l;
        }
        else {
            if(!curr->r) {
                curr->r = create_node(x);
                return tree;
            }
            curr = curr->r;
        }
    }
}

TreeNode* delete(TreeNode* tree, int x) {
    if(!tree) return NULL;
    if(tree->val > x) {
        tree->l = delete(tree->l, x);
        return tree;
    }
    if(tree->val < x) {
        tree->r = delete(tree->r, x);
        return tree;
    }

    if(!tree->l) {
        TreeNode* nxt = tree->r;
        free(tree);
        return nxt;        
    }
    if(!tree->r) {
        TreeNode* nxt = tree->l;
        free(tree);
        return nxt;
    }

    TreeNode* curr = tree->l;
    while(curr->r) curr = curr->r;
    tree->val = curr->val;
    tree->l = delete(tree->l, curr->val);

    return tree;
}

TreeNode* search(TreeNode* tree, int x) {
    if(!tree) return NULL;
    TreeNode* curr = tree;
    while(curr) {
        if(curr->val == x) return curr;
        if(curr->val > x) curr = curr->l;
        else curr = curr->r;
    }
    return NULL;
}

void inorder(TreeNode* tree) {
    if(!tree) return;
    inorder(tree->l);
    printf("%c ", tree->val);
    inorder(tree->r);
}

void menu() {
	printf(" \n*---------------------------*");
	printf(" \n \t1 : print");
    printf(" \n \t2 : insert");
	printf(" \n \t3 : delete");
    printf(" \n \t4 : search");
	printf(" \n \t5 : end");
	printf(" \n*---------------------------*");
	printf(" \ninput >> ");
}

int main() {
	TreeNode* root = NULL;
	TreeNode* foundedNode = NULL;
	char choice, val;

	root = insert(root, 'G'); // 트리 만들기
	insert(root, 'I'); 	insert(root, 'H');
	insert(root, 'D'); 	insert(root, 'B');
	insert(root, 'M'); 	insert(root, 'N');
	insert(root, 'A'); 	insert(root, 'J');
	insert(root, 'E'); 	insert(root, 'Q');

	while (1) {
		menu();
		choice = getchar(); getchar();
		switch (choice) {
		case '1': 
            printf(" \t[ BST ] ");
			inorder(root); printf(" \n");
			break;

		case '2':
			val = getchar(); getchar();
			insert(root, val);
			break;

		case '3':
			val = getchar(); getchar();
			root = delete(root, val);
			break;

		case '4':
			val = getchar(); getchar();
			foundedNode = search(root, val);
			if (foundedNode != NULL)
				printf(" \n found: %c \n", foundedNode->val);
			else printf(" \n search faild \n");
			break;

		case '5': return 0;
		default: 
            printf("wrong input \n");
			break;
		}
	}
}
