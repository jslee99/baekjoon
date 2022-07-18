#include<stdio.h>
#include<stdlib.h>

struct Node {
	int p_Node_num;
	struct Node* p;
	struct Node* l;
	struct Node* r;
};
struct Node* arr[50];
int N;
struct Node* root;
int remove_Node;
int res;

int leaves(struct Node* ptr) {
	if (ptr->l == NULL && ptr->r == NULL) {
		return 1;
	}
	else {
		if (ptr->l == NULL) {
			return leaves(ptr->r);
		}
		else if (ptr->r == NULL) {
			return leaves(ptr->l);
		}
		else {
			return leaves(ptr->r) + leaves(ptr->l);
		}
	}
}

int main(void) {
	scanf("%d", &N);
	/*
	for (int i = 0; i < N; i++) {
		
		int p_Node;
		scanf("%d", &p_Node);
		arr[i] = (struct Node*)malloc(sizeof(struct Node));
		arr[i]->p = NULL, arr[i]->l = NULL, arr[i]->r = NULL;
		if (p_Node == -1) {
			root = arr[i];
		}
		else {
			if (arr[p_Node]->l == NULL) {
				arr[p_Node]->l = arr[i];
				arr[i]->p = arr[p_Node];
			}
			else {
				arr[p_Node]->r = arr[i];
				arr[i]->p = arr[p_Node];
			}
		}
		
	}
	*/
	for (int i = 0; i < N; i++) {
		arr[i] = (struct Node*)malloc(sizeof(struct Node));
		arr[i]->p = NULL, arr[i]->l = NULL, arr[i]->r = NULL;
		scanf("%d", &(arr[i]->p_Node_num));
	}
	for (int i = 0; i < N; i++) {
		if (arr[i]->p_Node_num == -1) {
			root = arr[i];
		}
		else {
			arr[i]->p = arr[arr[i]->p_Node_num];
			if (arr[arr[i]->p_Node_num]->l == NULL) {
				arr[arr[i]->p_Node_num]->l = arr[i];
			}
			else {
				arr[arr[i]->p_Node_num]->r = arr[i];
			}
		}
	}

	scanf("%d", &remove_Node);
	//printf("%d\n", leaves(root) - leaves(arr[remove_Node]));
	//wrong longic
	struct Node* parent = arr[remove_Node]->p;
	if (parent == NULL)//root
		printf("0\n");
	else {
		if (parent->l == arr[remove_Node]) {//left child
			parent->l = NULL;
			arr[remove_Node]->p = NULL;
		}
		else {
			parent->r = NULL;
			arr[remove_Node]->p = NULL;
		}
		printf("%d\n", leaves(root));
	}
}



