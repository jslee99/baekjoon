#include<stdio.h>

int a[51][51];
int visit[51];
int score[51];
int N;
int q[50];
int tail, head;
int fin_score = 987654321;
int fin_p_num = 0;
int fin_arr[50] = { 0, };

int main(void) {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			a[i][j] = 0;//no relationship
		}
	}
	while (1) {
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		if (n1 == -1) {
			break;
		}
		else {
			a[n1][n2] = 1;//relationship exists
			a[n2][n1] = 1;
		}
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visit[j] = -1;
		}
		tail = 0, head = 0;
		visit[i] = 0;
		q[tail] = i;
		tail++;
		int max = -1;
		while (tail != head) {
			int cur;
			cur = q[head];
			head++;
			for (int j = 1; j <= N; j++) {
				if (a[cur][j] == 1 && visit[j] == -1) {
					visit[j] = visit[cur] + 1;
					if (visit[j] > max)
						max = visit[j];
					q[tail] = j;
					tail++;
				}
			}
		}
		score[i] = max;
		if (score[i] < fin_score) {
			fin_score = score[i];
		}
	}

	for (int i = 1; i <= N; i++) {
		if (fin_score == score[i]) {
			fin_arr[fin_p_num] = i;
			fin_p_num++;
		}
	}
	printf("%d %d\n", fin_score, fin_p_num);
	for (int i = 0; i < fin_p_num; i++) {
		printf("%d ", fin_arr[i]);
	}
}


