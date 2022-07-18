#include<iostream>

using namespace std;

long long n;
long long t;
long long k;
long long arr[20];
int used[21] = { 0, };
;
long long factorial(long long n) {
	long long ret = 1;
	for (long long i = n; i >= 1; i--) {
		ret *= i;
	}
	return ret;
}

int main(void) {
	scanf("%d", &n);
	scanf("%d", &t);
	if (t == 1) {
		cin >> k;
		for (long long i = 0; i < n; i++) {
			long long fac = factorial(n - i - 1);
			for (long long j = 1; j <= n; j++) {
				if (used[j] == 1) {
					continue;
				}

				if (k > fac) {
					k -= fac;
				}
				else {
					arr[i] = j;
					used[j] = 1;
					break;
				}
				/*if ((j - 1) * fac < k && k <= j * fac) {
					int index = 0;
					for (long l = 1; l < 21; l++) {
						while (1) {
							index++;
							if (used[index] == 1) {
								continue;
							}
							else {
								break;
							}
						}
						if (l == j) {
							break;
						}
					}
					arr[i] = index;
					used[index] = 1;
					k -= j * fac;
					break;
				}*/
			}
		}
		for (int i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		}
	}
	else {
		k = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		for (long long i = 0; i < n; i++) {
			/*
			long long cnt = 0;
			for (long long j = 0; j < arr[i]; j++) {
				if (used[j] == 1) {
					cnt++;
				}
			}
			used[arr[i]] = 1;
			k += (arr[i] - 1 - cnt) * factorial(n - i - 1);*/
			long long fac = factorial(n - i - 1);
			for (long long j = 1; j < arr[i]; j++) {
				if (used[j] == 0) {
					k += fac;
				}
			}
			used[arr[i]] = 1;
		}
		cout << k + 1 << endl;
	}
}

