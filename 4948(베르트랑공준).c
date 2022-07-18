#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void) {
	int n;
	int* prime;
	int root2n;
	int cnt = 0;
	scanf("%d", &n);
	while (n != 0) {
		prime = (int*)malloc(((2 * n) + 1) * sizeof(int));
		prime[0] = 0;
		prime[1] = 0;
		for (int i = 2; i < (2 * n) + 1; i++) {
			prime[i] = 1;
		
		} 
		root2n = (int)sqrt(2 * n);
		for (int j = 2; j * 2 <= root2n; j++) {
			prime[j * 2] = 0;
		}
		for (int i = 3; i <= root2n / 2; i += 2) {
			for (int j = 2; j * i <= root2n; j ++) {
				prime[j * i] = 0;
			}
		}

		// ~root2n(including)
		for (int i = 2; i <= root2n; i++) {
			if (prime[i] == 1) {
				for (int j = 2; j * i <= 2 * n; j++) {
					prime[j * i] = 0;
				}
			}
		}
		// ~2n(including)
		cnt = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (prime[i] == 1) {
				cnt++;
			}
		}
		printf("%d\n", cnt);

		free(prime);
		scanf("%d", &n);
	}
}