#include<iostream>
#include<cmath>
using namespace std;

void Merge(int* arr, int p, int q, int r) {
	int* ptr1 = new int[q - p + 2];
	int* ptr2 = new int[r - q + 1];
	for (int i = 0; i < q - p + 1; i++) {
		ptr1[i] = arr[p + i];
	}
	ptr1[q - p + 1] = 1000001;//sentinel
	for (int i = 0; i < r - q; i++) {
		ptr2[i] = arr[q + 1 + i];
	}
	ptr2[r - q] = 1000001;
	int j = 0;
	int k = 0;
	for (int i = 0; i < r - p + 1; i++) {
		if (ptr1[j] <= ptr2[k]) {
			arr[p + i] = ptr1[j];
			j++;
		}
		else {
			arr[p + i] = ptr2[k];
			k++;
		}
	}
	delete[] ptr1;
	delete[] ptr2;
}
/*
* 
29978445	jslee99	2751	맞았습니다!!	131300	572	C++17 / 수정	968	56초 전  when not using delete
29978332	jslee99	2751	맞았습니다!!	9844	484	C++17 / 수정	999	         when using delete

*/

void Merge_Sort(int* arr, int p, int r) {
	if (p < r) {
		int q = ((p + r) / 2); // p ~ q     q + 1 ~ r
		Merge_Sort(arr, p, q);
		Merge_Sort(arr, q + 1, r);
		Merge(arr, p, q, r);
	}

	else {
		return;
	}

}

int main(void) {
	int n;
	scanf("%d", &n);
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	Merge_Sort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}

}