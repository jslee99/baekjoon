#include<iostream>
#include<iostream>
using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	int max = -1000001;
	int min = 1000001;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]); //�Է�: 23 45 12 �̷�������
	}
	for (int i = 0; i < n; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
		if (min > arr[i]) {
			min = arr[i];
		}
	}
	printf("%d %d", min, max);
}