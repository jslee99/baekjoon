#include<stdio.h>

#define INF 1000000001;

int S[500000];
int tower[500001];
int res[500001];
int N;
int top = -1;

int main(void) {
	tower[0] = INF;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &tower[i]);
	}
	res[1] = 0;
	top++;
	S[top] = 0;
	for (int i = 2; i <= N; i++) {
		if (tower[i - 1] > tower[i]) {
			res[i] = i - 1;
			top++;
			S[top] = i - 1;
		}
		else {
			while (tower[S[top]] < tower[i])
				top--;
			res[i] = S[top];
		}
	}
	for (int i = 1; i <= N; i++)
		printf("%d ", res[i]);
	
}