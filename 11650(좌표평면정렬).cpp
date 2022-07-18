#include<iostream>
#include<algorithm>
using namespace std;

bool My_Compare(const int* a, const int* b) {
	if (a[0] == b[0]) {
		return a[1] < b[1];
	}
	else {
		return a[0] < b[0];
	}
}

int main(void) {
	int n;
	scanf("%d", &n);
	int** coordinate = new int* [n];
	for (int i = 0; i < n; i++) {
		coordinate[i] = new int[2];
	}
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		coordinate[i][0] = x;
		coordinate[i][1] = y;
	}
	sort(coordinate, coordinate + n, My_Compare);
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", coordinate[i][0], coordinate[i][1]);
	}



	for (int i = 0; i < n; i++) {
		delete[] coordinate[i];
	}
	delete[] coordinate;
}