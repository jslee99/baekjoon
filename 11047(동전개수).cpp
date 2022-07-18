#include<iostream>
using namespace std;

int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);
	int* val = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &val[i]);
	}
	int cnt = 0;
	int idx = n - 1;
	for (idx; idx > 0; idx--) {
		if (val[idx] <= k) {
			break;
		}
	}
	for (int i = idx; i > -1; i--) {
		cnt += k / val[i];
		k = k % val[i];
	}
	printf("%d", cnt);



	delete[] val;
}