#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
	int p_node_num;
	Node* p;
	vector<Node*> child;
};
int N;
Node* arr[50];
int remove_node_num;
Node* root;

int leaves(Node* ptr) {
	if (ptr->child.size() == 0) {
		return 1;
	}
	else {
		int sum = 0;
		for (int i = 0; i < ptr->child.size(); i++) {
			sum += leaves(ptr->child[i]);
		}
		return sum;
	}
}

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		arr[i] = new Node();
		arr[i]->p = NULL;
		scanf("%d", &arr[i]->p_node_num);
	}
	scanf("%d", &remove_node_num);
	for (int i = 0; i < N; i++) {
		if (arr[i]->p_node_num == -1) {
			root = arr[i];
		}
		else {
			arr[i]->p = arr[arr[i]->p_node_num];
			arr[arr[i]->p_node_num]->child.push_back(arr[i]);
		}
	}

	Node* parent = arr[remove_node_num]->p;
	if (parent == NULL) {
		printf("0\n");
	}
	else {
		int i;
		for (i = 0; i < parent->child.size(); i++) {
			if (parent->child[i] == arr[remove_node_num]) {
				break;
			}
		}
		parent->child.erase(parent->child.begin() + i);
		arr[remove_node_num]->p = NULL;
		printf("%d\n", leaves(root));
	}

	return 0;
}


