#include<stdio.h>

int heap[1000001];
int heap_size = 0;
int n;
int key;


int parent(i) {
	return i / 2;
}

int left(i) {
	return 2 * i;
}

int right(i) {
	return 2 * i + 1;
}

void heap_insert(int key) {
	heap_size++;
	int i = heap_size;
	heap[heap_size] = key;
	int temp;
	while (i / 2 > 0 && heap[parent(i)] < key) {
		temp = heap[parent(i)];
		heap[parent(i)] = heap[i];
		heap[i] = temp;
		i = parent(i);
	}
}


void max_heapify(int i) {
	int temp;
	while (left(i) <= heap_size) {
		if (right(i) <= heap_size) {//right child exist
			if (heap[i] >= heap[left(i)] && heap[i] >= heap[right(i)]) {
				break;
			}
			else if (heap[left(i)] >= heap[right(i)]) {
				temp = heap[i];
				heap[i] = heap[left(i)];
				heap[left(i)] = temp;
				i = left(i);
			}
			else {
				temp = heap[i];
				heap[i] = heap[right(i)];
				heap[right(i)] = temp;
				i = right(i);
			}
		}
		else {//no right child
			if (heap[i] >= heap[left(i)]) {
				break;
			}
			else {
				temp = heap[i];
				heap[i] = heap[left(i)];
				heap[left(i)] = temp;
				i = left(i);
			}
		}
	}
}

int extract_max() {
	if (heap_size == 0) {
		return 0;
	}
	int max = heap[1];
	heap[1] = heap[heap_size];
	heap_size--;
	max_heapify(1);
	return max;
}


int main(void) {
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &key);
		if (key == 0) {
			printf("%d\n", extract_max());
		}
		else {
			heap_insert(key);
		}
	}
}