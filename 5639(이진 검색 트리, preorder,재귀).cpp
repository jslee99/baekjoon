#include<iostream>

using namespace std;

int pre_order[100000];
int N = 0;

void post_order(int p, int r) {
	if (p > r) {
		return;
	}
	else if (p == r) {
		cout << pre_order[p] << '\n';
		return;
	}
	else {
		int root_node = pre_order[p];
		int cut_idx = r;

		for (int i = p + 1; i <= r; i++) {
			if (pre_order[i] > root_node) {
				cut_idx = i - 1;
				break;
			}
		}

		post_order(p + 1, cut_idx);
		post_order(cut_idx + 1, r);
		cout << root_node << '\n';

	}
}

int main() {
	int node;
	while (cin >> node)
		pre_order[N++] = node;

	post_order(0, N - 1);

	return 0;
}