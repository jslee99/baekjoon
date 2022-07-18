#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	bool* prime;
	prime = (bool*) malloc((n + 1) * sizeof(bool));
	for (int i = 0; i < n + 1; i++) {
		prime[i] = true;
	}
	prime[1] = false;
	int root = (int)sqrt(n);
	for (int i = 2; i <= root; i++) {
		int j = 2;// if j = 1 then 2, 3, 5... is false
		while (j * i <= n) {
			prime[j * i] = false;
			j++;
		}
	}

	for (int i = m; i <= n; i++) {
		if (prime[i] == true) {
			printf("%d\n", i);
		}
	}


	free(prime);
}