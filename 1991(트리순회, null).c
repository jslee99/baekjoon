#include<stdio.h>
#include<stdlib.h>

int n;
char pkey, lkey, rkey;

struct Node{
	char key;
	struct Node *l ;
	struct Node* r ;
	struct Node* p;
};

struct Node* root;
struct Node* q[26];
int tail, head;
struct Node* x;

struct Node* search(struct Node* x, char skey) {
	tail = 0, head = 0;
	q[tail] = x;
	tail++;
	while (head != tail) {
		x = q[head];
		head++;
		if (x->key == skey) {
			break;
		}
		if (x->l != NULL) {
			q[tail] = x->l;
			tail++;
		}
		if (x->r != NULL) {
			q[tail] = x->r;
			tail++;
		}
	}
	return x;
}

void preorder(struct Node* x) {
	printf("%c", x->key);
	if (x->l != NULL) {
		preorder(x->l);
	}
	if (x->r != NULL) {
		preorder(x->r);
	}
}

void inorder(struct Node* x) {
	if (x->l != NULL) {
		inorder(x->l);
	}
	printf("%c", x->key);
	if (x->r != NULL) {
		inorder(x->r);
	}
}

void postorder(struct Node* x) {
	if (x->l != NULL) {
		postorder(x->l);
	}
	if (x->r != NULL) {
		postorder(x->r);
	}
	printf("%c", x->key);
}


int main(void) {
	scanf("%d", &n);
	root = malloc(sizeof(struct Node));
	root->key = 'A';
	while (n--) {
		getchar();
		scanf("%c", &pkey);
		getchar();
		scanf("%c", &lkey);
		getchar();
		scanf("%c", &rkey);
		x = search(root, pkey);
		if (lkey != '.') {
			x->l = malloc(sizeof(struct Node));
			x->l->key = lkey;
		}
		else {
			x->l = NULL;
		}
		if (rkey != '.') {
			x->r = malloc(sizeof(struct Node));
			x->r->key = rkey;
		}
		else {
			x->r = NULL;
		}
	}
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);

}

/*
#include<stdio.h>
#include<stdlib.h>

struct Node {
	struct Node* l;
};

int main(void) {
	struct Node* ptr = malloc(sizeof(struct Node));
	if (ptr->l != NULL) {
		printf("yes");
	}
}

reuslt:yes
so at intializtion of structure,  pointer in structure is not NULL;
NULL로 초기화된 포인터와 초기화되지 않은 포인터는 다르다!!
*/