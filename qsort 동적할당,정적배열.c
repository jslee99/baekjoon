#include<stdio.h>
#include<stdlib.h>

int** a;
int n;
int b[10][2];

int compare(const void* a, const void* b) {
	return (*(int**)a)[0] - (*(int**)b)[0];
}

int main(void) {
	scanf("%d", &n);
	/*
	a = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		a[i] = (int*)malloc(sizeof(int) * 2);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i][0], &a[i][1]);
	}
	qsort(a, n, sizeof(int*), compare);*/
	//correct
	
	printf("");
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &b[i][0], &b[i][1]);
	}
	qsort(b, n, sizeof(int*), compare);
	//connot
	//a : ���� ,  b:���(b[0]��� ���)(�ڽſ��� ����Ǿ��ִ� �ּҰ��� ���� �� �� ����)
	printf("");

}

