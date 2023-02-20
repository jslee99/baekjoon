#include<iostream>
#include<algorithm>

using namespace std;
int N;

class PQ {
public:
	bool is_empty() {
		return size == 0;
	}

	int pop() {
		if (size == 0) {
			cout << "err at pop" << endl;
			return -1;
		}

		int ret = A[1];
		A[1] = A[size--];
		int parent = 1, left = 2, right = 3;
		while (1) {
			if (left > size) {
				break;
			}
			else if (left <= size && right > size) {
				if (A[parent] > A[left]) {
					swap(A[parent], A[left]);
					parent = left;
					left = parent * 2;
					right = parent * 2 + 1;
				}
				else {
					break;
				}
			}
			else if (right <= size) {
				int small_idx;
				if (A[left] < A[right]) {
					small_idx = left;
				}
				else {
					small_idx = right;
				}

				if (A[parent] > A[small_idx]) {
					swap(A[parent], A[small_idx]);
					parent = small_idx;
					left = parent * 2;
					right = parent * 2 + 1;
				}
				else {
					break;
				}
			}
		}
		return ret;
	}

	void push(int key) {
		//decrease_key(++size, key);
		A[++size] = key;	
		int i = size;
		while (i > 1 && A[i / 2] > A[i]) {
			swap(A[i / 2], A[i]);
			i = i / 2;
		}
	}

private:
	int size = 0;
	int A[100001];
	void decrease_key(int idx, int key) {
		if (A[idx] < key) {
			cout << "err at decrease key" << endl;
			return;
		}
		A[idx] = key;
		int i = idx;
		while (i > 1 && A[i / 2] > A[i]) {
			swap(A[i / 2], A[i]);
			i = i / 2;
		}
	}
};

int main() {
	scanf("%d", &N);
	PQ pq = PQ();
	int a;
	while (N--) {
		scanf("%d", &a);
		if (a == 0) {
			if (pq.is_empty()) {
				printf("0\n");
			}
			else {
				printf("%d\n", pq.pop());
			}
		}
		else {
			pq.push(a);
		}
	}
}