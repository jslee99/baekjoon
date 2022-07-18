#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
vector<int> prime_set;
bool is_prime[1000001];

int binary_search(const int n,int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		if (prime_set[mid] < n)
			left = mid;
		else
			right = mid;
		return binary_search(n, left, right);
	}
	else {
		return left;
	}
}

int main(void) {
	for (int i = 0; i <= 1000000; i++)
		is_prime[i] = true;

	is_prime[0] = false;
	is_prime[1] = false;
	int root = sqrt(1000000);
	for (int i = 2; i <= root; i++) {
		if (is_prime[i]) {
			int j = 2;
			while (i * j <= 1000000) {
				is_prime[i * j] = false;
				j++;
			}
		}
	}

	for (int i = 2; i <= 1000000; i++) {
		if (is_prime[i])
			prime_set.push_back(i);
	}


	while (1) {
		int n;
		scanf("%d", &n);
		if (!n)
			break;

		int a = -1, b = -1;

		/*
		 prime_set.push_back(1000003);
		int idx_prime_set = binary_search(n, 0, prime_set.size() - 1);//0 ~ idx : lessthan n    idx + 1 ~ prime_set.size() - 1 : greater than n
		for (int i = 0; i <= idx_prime_set; i++) {
			if (is_prime[n - prime_set[i]] && prime_set[i] > n - prime_set[i]) {
				b = prime_set[i];
				a = n - prime_set[i];
				break;
			}
		}*/

		
		for (int i = 0; i < prime_set.size(); i++) {
			if (prime_set[i] < n && is_prime[n - prime_set[i]]) {
				a = prime_set[i];
				b = n - prime_set[i];
				break;
			}
		}

		if (a == -1 || a >= b) {
			printf("%s\n", "Goldbach's conjecture is wrong.");
		}
		else {
			printf("%d = %d + %d\n", n, a, b);
		}
	}
}
