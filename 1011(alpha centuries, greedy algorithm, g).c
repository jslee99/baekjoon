#include<stdio.h>
#include<stdlib.h>

int t;
int x, y;
int n;
int to_sum;
int dx;
int cnt;
int remain;

int main(void) {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &x, &y);
		n = y - x;

		remain = n - 1;//remain : remain of distance
		cnt = 1;
		dx = 1;
		to_sum = 1;//  to_sum :  sum of 1 ~ dx;

		while (remain > 0) {
			if (remain - (dx + 1) >= to_sum) {//when we move dx + 1 we can! arrive end point so we move dx + 1
				remain -= dx + 1;
				to_sum += dx + 1;
				dx = dx + 1;
				cnt++;
			}
			else if (remain - dx >= to_sum - dx) {//when we move dx + 1 we can't arrive endpoint but when we move dx we can arrive endpoint so we move dx
				remain -= dx;
				cnt++;
			}
			else {//when we move dx +1 or dx we never arrive endpoint so we need to shrink dx and we move dx - 1
				remain -= dx - 1;
				to_sum -= dx;
				dx = dx - 1;
				cnt++;
			}
		}//this while loop is like greedy algorithm. For minimum move(cnt) we need to move far as possible at each moving
		//example, at previos move, suppose we move dx 
		//if{}: when we can move dx + 1 this time we move dx + 1 to make cnt less as possible(even though we move dx + 1 this time remaining distance(remain - dx + 1) is less than dx + dx - 1 + ...... + 1 so we can arrive endpoint if we want. Thus it is reasonable(safe) that we move dx + 1)
		//this is similar to else if{}(when we move dx + ! this time, we can't arrive end point but when we move dx we can arrive endpoint. Thus we move dx this time)
		//else{}: when we move dx + 1 or dx we can't arrive end point. so we move dx - 1(we need to shrink dx this time)
		printf("%d\n", cnt);
	}
}

/*
int t;
int x, y;
int n;
int* to_sum;
int remain;
int* to_sum;
int dx;
int cnt;


int main(void) {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &x, &y);
		n = y - x;// 0 ~ n
		remain = n;
		to_sum = (int*)malloc(sizeof(int) * (n + 1));
		for (int i = 0; i < n + 1; i++) {
			to_sum[i] = -1;
		}
		to_sum[0] = 0;
		to_sum[1] = 1;

		dx = 1, remain -= 1, cnt = 1;
		while (remain > 0) {
			if (to_sum[dx] == -1) {
				to_sum[dx] = to_sum[dx - 1] + dx;
			 }

			if (remain - (dx + 1) >= to_sum[dx]) {
				remain = remain - (dx + 1);
				dx = dx + 1;
				cnt++;
			}
			else if (remain - dx >= to_sum[dx - 1]) {
				remain = remain - dx;
				cnt++;
			}
			else {
				remain = remain - (dx - 1);
				dx = dx - 1;
				cnt++;
			}
		}
		printf("%d\n", cnt);

	}
}
*/



/*
int n;
int* visit;
int** q;
int tail, head;
int t;

int main(void) {
	scanf("%d", &t);
	while (t--) {
		int x, y;
		scanf("%d %d", &x, &y);
		n = y - x;// 0 ~ n
		visit = (int*)malloc(sizeof(int) * (n + 1));
		q = (int**)malloc(sizeof(int*) * n);
		for (int i = 0; i < n; i++) {
			q[i] = (int*)malloc(sizeof(int) * 2);//coordinate, dx by previous move
		}
		for (int i = 0; i <= n; i++) {
			visit[i] = -1;
		}
		visit[0] = 0;
		visit[1] = 1;
		tail = 0, head = 0;
		q[tail][0] = 1, q[tail][1] = 1;
		tail++;
		int dx;
		int new_x;
		while (tail != head) {//bfs
			x = q[head][0], dx = q[head][1];
			head++;
			for (int i = -1; i <= 1; i++) {
				new_x = x + dx + i;
				if (new_x <= n && visit[new_x] == -1) {
					visit[new_x] = visit[x] + 1;
					q[tail][0] = new_x, q[tail][1] = dx + i;
					tail++;
				}
			}
		}
		printf("%d\n", visit[n]);
		for (int i = 0; i < n; i++) {
			free(q[i]);
		}
		free(q);
		free(visit);
	}
}*/