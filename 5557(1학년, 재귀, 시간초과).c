#include<stdio.h>

int N;
int num[100];

long long solve(int idx, int ans) {
	if (idx == 0) {
		if (num[idx] == ans)
			return 1;
		else
			return 0;
	}

	long long ret = 0;
	//-num[idx]
	if (ans + num[idx] <= 20)
		ret += solve(idx - 1, ans + num[idx]);
	//+num[idx]
	if (ans - num[idx] >= 0)
		ret += solve(idx - 1, ans - num[idx]);

	return ret;
}

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	printf("%lld\n", solve(N - 2, num[N - 1]));

}


