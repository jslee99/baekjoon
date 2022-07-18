#include<stdio.h>
#include<stdlib.h>

long long N, M;
long long A[100000];
int s, e;
long long ans = 2000000001;

int cmp(long long* a, long long* b) {
	if (*a > *b)
		return 1;
	return 0;
}

int main(void) {
	scanf("%lld %lld", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%lld", &A[i]);
	qsort(A, N, sizeof(long long), cmp);
	/*
	s = 0, e = N - 1;
	while (1) {
		//A[e] - A[s] >= M
		if (A[e] - A[s] == M)
			break;
		if (A[e] - A[e - 1] < A[s + 1] - A[s]) {
			if (A[e - 1] - A[s] >= M) {
				e = e - 1;
				continue;
			}
			else {
				break;
			}
		}
		else {
			if (A[e] - A[s + 1] >= M) {
				s = s + 1;
				continue;
			}
			else {
				break;
			}
		}
	}
	printf("%lld\n", A[e] - A[s]);
	*/
	s = 0, e = 0;
	while (e < N) {
		if (A[e] - A[s] < M) {
			e++;
		}
		else if (A[e] - A[s] == M) {
			printf("%lld\n", M);
			return 0;
		}
		else {
			if (A[e] - A[s] < ans)
				ans = A[e] - A[s];
			s++;
		}
	}
	printf("%lld", ans);
}


