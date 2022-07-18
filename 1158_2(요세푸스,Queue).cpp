#include<iostream>
using namespace std;

class My_Queue {
private:
	int* lst;
	int tail = 0;
	int head = 0;
	int length;
	// tail == head : empty 
public:
	My_Queue(int n) {
		this->lst = new int[n + 1];
		this->length = n + 1;
	}
	~My_Queue() {
		delete[] this->lst;
	}
	bool isEmpty() {
		return this->head == this->tail;
	}
	bool isFull() {
		return (this->tail + 1 == this->head) || (this->head == 0 && this->tail == this->length - 1);
	}
	void Enqueue(int key) {
		if (this->isFull()) {
			printf("Full");
			return;
		}
		this->lst[this->tail] = key;
		if (this->tail == this->length - 1) {
			this->tail = 0;
		}
		else {
			this->tail += 1;
		}
	}
	int Dequeue() {
		if (this->isEmpty()) {
			printf("isEmpty");
			return -10000;
		}
		int x = this->lst[this->head];
		if (this->head == this->length - 1) {
			this->head = 0;
		}
		else {
			this->head += 1;
		}
		return x;		
	}
};


int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);
	My_Queue* Q = new My_Queue(n);
	int* result = new int[n];
	for (int i = 1; i <= n; i++) {
		Q->Enqueue(i);
	}
	int index = 0;
	while (!(Q->isEmpty())) {
		
		for (int i = 0; i < k - 1; i++) {
			Q->Enqueue(Q->Dequeue());
		}
		result[index] = Q->Dequeue();
		index++;
	}
	printf("<");
	for (int i = 0; i < n - 1; i++) {
		printf("%d, ", result[i]);
	}
	printf("%d>", result[n - 1]);
	delete Q;
	delete[] result;
}