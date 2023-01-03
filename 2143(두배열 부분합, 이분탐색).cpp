#include<iostream>

using namespace std;

int n, m, T;
int A[1000];
int B[1000];
int sum_A[1000][1000];
int sum_B[1000][1000];
int arr_sum_B[1000000];
int arr_sum_B_2[1000000];
int idx = 0;
long res = 0;

int compare(const void* a, const void* b)
{
	const int* x = (int*)a;
	const int* y = (int*)b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;

	return 0;
}

int binary_search(int key) {
	int left = 0;
	int right = idx - 1;
	int mid;

	if (arr_sum_B[left] > key) {
		return -1;
	}
	else if (arr_sum_B[left] == key) {
		return left;
	}
	else if (arr_sum_B[right] < key) {
		return -1;
	}

	while (left + 1 < right) {
		mid = (left + right) / 2;
		if (arr_sum_B[mid] < key) {
			left = mid;
		}
		else {
			right = mid;
		}
	}
	return right;
}

int main(void) {
	cin >> T;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> B[i];
	}

	for (int i = 0; i < n; i++) {
		sum_A[i][i] = A[i];
	}
	for (int k = 1; k < n; k++) {
		for (int i = 0; i < n; i++) {
			if (i + k >= n)break;

			sum_A[i][i + k] = sum_A[i][i + k - 1] + A[i + k];
		}
	}

	for (int i = 0; i < m; i++) {
		sum_B[i][i] = B[i];
		arr_sum_B[idx++] = sum_B[i][i];
	}
	for (int k = 1; k < m; k++) {
		for (int i = 0; i < m; i++) {
			if (i + k >= m)break;

			sum_B[i][i + k] = sum_B[i][i + k - 1] + B[i + k];
			arr_sum_B[idx++] = sum_B[i][i + k];
		}
	}

	qsort(arr_sum_B, idx, sizeof(int), compare);
	
	int x = 0;
	int y = x;
	while (x < idx) {
		if (x == idx - 1 || arr_sum_B[x] != arr_sum_B[x + 1]) {
			arr_sum_B_2[y] = x - y + 1;
			y = x + 1;
		}
		else {

		}
		x++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int key = T - sum_A[i][j];
			int key_idx = binary_search(key);
			if (key_idx == -1) continue;
			if (arr_sum_B[key_idx] == key) {
				res += (long)arr_sum_B_2[key_idx];
			}
		}
	}

	cout << res << endl;

	return 0;
}