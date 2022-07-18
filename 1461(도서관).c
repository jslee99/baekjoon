#include<stdio.h>
#include<stdlib.h>

int N, M;
int books[10000];
int negative = 0, positive = 0;
int res = 0;

int cmp(int* a, int* b) {
	return *a - *b;
}


int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &books[i]);
		if (books[i] < 0)
			negative++;
		else
			positive++;
	}
	qsort(books, N, sizeof(int), cmp);

	if (positive == 0) {
		int p = 0;
		while (p < negative)
			p += M;
		p -= M;
		while (p != 0) {
			res += 2 * abs(books[p]);
			p -= M;
		}
		res += abs(books[0]);
		printf("%d\n", res);
	}
	else if (negative == 0) {
		int r = N - 1;
		while (r >= N - positive)
			r -= M;
		r += M;
		while (r != N - 1) {
			res += 2 * books[r];
			r += M;
		}
		res += books[N - 1];
		printf("%d\n", res);
	}
	else {
		int p = 0;
		while (p < negative)
			p += M;
		p -= M;
		while (p != 0) {
			res += 2 * abs(books[p]);
			p -= M;
		}
		int r = N - 1;
		while (r >= N - positive)
			r -= M;
		r += M;
		while (r != N - 1) {
			res += 2 * books[r];
			r += M;
		}

		if (abs(books[0]) < books[N - 1]) 
			res += 2 * abs(books[0]) + books[N - 1];
		else 
			res += 2 * books[N - 1] + abs(books[0]);
		printf("%d\n", res);
	}



	/*
	int r = N - positive, p = negative - 1;

	//positive
	while (N - r + 1 >= M) {
		res += 2 * books[r + M - 1];
		r = r + M;
	}
	//negative
	while (p + 1 >= M) {
		res += 2 * abs(books[p - M + 1]);
		p = p - M;
	}

	if (p == 0 && r == N - 1) {
		printf("%d\n", res);
	}
	else if (p == 0) {// r < N - 1
		res += books[N - 1];
		printf("%d\n", res);
	}
	else if (r == N - 1) {// p > 0
		res += abs(books[0]);
		printf("%d\n", res);
	}
	else {//
		if (abs(books[0]) < books[N - 1])
			res += 2 * abs(books[0]) + books[N - 1];
		else
			res += 2 * books[N - 1] + abs(books[0]);
	}
	return 0;
	*/
}

