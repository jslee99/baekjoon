#include<stdio.h>

int dp[500001];
int tower[500001];
int N;
#define INF 1000000001;

int main(void) {
	tower[0] = INF;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &tower[i]);
	}
	for (int i = 1; i <= N; i++) {
		if (tower[i - 1] > tower[i]) {
			dp[i] = i - 1;
		}
		else {
			int tw = dp[i - 1];
			while (tower[tw] < tower[i]) {
				tw = dp[tw];
			}
			dp[i] = tw;
		}
	}
	for (int i = 1; i <= N; i++) {
		printf("%d ", dp[i]);
	}
	
}