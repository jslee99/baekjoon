#include<iostream>
using namespace std;

/*
int func(int* arr, int n) {
	int* cnt = new int[3];
	if (n % 3 == 0 && n % 2 == 0) {
		if (arr[n / 3] != -1) {
			cnt[2] = arr[n / 3];
		}
		else {
			cnt[2] = func(arr, n / 3);
		}

		if (arr[n / 2] != -1) {
			cnt[1] = arr[n / 2];
		}
		else {
			cnt[1] = func(arr, n / 2);
		}

		if (arr[n - 1] != -1) {
			cnt[0] = arr[n - 1];
		}
		else {
			cnt[0] = func(arr,n - 1);
		}

		int min = 1000000;
		for (int i = 0; i < 3; i++) {
			if (min > cnt[i]) {
				min = cnt[i];
			}
		}
		arr[n] = min + 1;
		delete[] cnt;
		return arr[n];
	}
	else if (n % 3 == 0 && n % 2 != 0) {
		if (arr[n / 3] != -1) {
			cnt[2] = arr[n / 3];
		}
		else {
			cnt[2] = func(arr, n / 3);
		}

		if (arr[n - 1] != -1) {
			cnt[0] = arr[n - 1];
		}
		else {
			cnt[0] = func(arr, n - 1);
		}

		if (cnt[0] < cnt[2]) {
			arr[n] = cnt[0] + 1;
			delete[] cnt;
			return arr[n];
		}
		else {
			arr[n] = cnt[2] + 1;
			delete[] cnt;
			return arr[n];
		}
	}
	else if (n % 3 != 0 && n % 2 == 0) {
		if (arr[n / 2] != -1) {
			cnt[1] = arr[n / 2];
		}
		else {
			cnt[1] = func(arr, n / 2);
		}

		if (arr[n - 1] != -1) {
			cnt[0] = arr[n - 1];
		}
		else {
			cnt[0] = func(arr, n - 1);
		}

		if (cnt[0] < cnt[1]) {
			arr[n] = cnt[0] + 1;
			delete[] cnt;
			return arr[n];
		}
		else {
			arr[n] = cnt[1] + 1;
			delete[] cnt;
			return arr[n];
		}
	}
	else {
		if (arr[n - 1] != -1) {
			cnt[0] = arr[n - 1];
		}
		else {
			cnt[0] = func(arr, n - 1);
		}

		arr[n] = cnt[0] + 1;
		delete[] cnt;
		return arr[n];
	}
}

int main(void) {
	int n;
	scanf("%d", &n);
	int* arr = new int[n + 1];
	for (int i = 0; i < n + 1; i++) {
		arr[i] = -1;
	}
	arr[1] = 0;
	printf("%d\n", func(arr, n));
}*/

// stackoverflow 메모리 초과

int main(void) {
	int n;
	scanf("%d", &n);
	int* dp = new int[1000001];
	dp[1] = 0;
	for (int i = 2; i < 1000001; i++) {
		if (i % 3 == 0 and i % 2 == 0) {
			if (dp[i - 1] < dp[i / 2] && dp[i - 1] < dp[i / 3]) {
				dp[i] = dp[i - 1] + 1;
			}
			else if(dp[i / 2] < dp[i - 1] && dp[i / 2] < dp[ i / 3]){
				dp[i] = dp[i / 2] + 1;
			}
			else {
				dp[i] = dp[i / 3] + 1;
			}
		}
		else if(i % 3 == 0 && i % 2 != 0){
			if (dp[i - 1] < dp[i / 3]) {
				dp[i] = dp[i - 1] + 1;
			}
			else {
				dp[i] = dp[i / 3] + 1;
			}
		}
		else if (i % 3 != 0 && i % 2 == 0) {
			if (dp[i - 1] < dp[i / 2]) {
				dp[i] = dp[i - 1] + 1;
			}
			else {
				dp[i] = dp[i / 2] + 1;
			}
		}
		else {
			dp[i] = dp[i - 1] + 1;
		}

		if (i == n) {
			break;
		}
	}
	printf("%d\n", dp[n]);

	delete[] dp;
}