#include<stdio.h>
#include<stdlib.h>

int visit[10];//at dfs1 0 or 1
int side[10]; //0 or 1
int people[10];
int N;
int map[10][10];// no 0   yes 1
int cnt = 0;//connected component
int total_people = 0;
int ans = 98765432;

void dfs1(int x) {
	visit[x] = 1;
	for (int i = 0; i < N; i++) {
		if (map[x][i] == 1 && visit[i] == 0)
			dfs1(i);
	}
}

void dfs2(int x, int check_side) {
	visit[x] = 1;
	for (int i = 0; i < N; i++) {
		if (map[x][i] == 1 && visit[i] == 0 && side[i] == check_side)
			dfs2(i, check_side);
	}
}

void dfs3(int x, int* people_sum) {
	visit[x] = 1;
	*people_sum += people[x];
	for (int i = 0; i < N; i++)
		if (visit[i] == 0 && side[i] == 0)
			dfs3(i, people_sum);
}

void solve(int total_side_num, int cur_side_num, int idx) {//criteria : side 0
	if (cur_side_num < total_side_num) {
		//total - cur
		// i = idx ~  N - (total - cur)
		for (int i = idx; i <= N - (total_side_num - cur_side_num); i++) {
			side[i] = 0;
			solve(total_side_num, cur_side_num + 1, i + 1);
			side[i] = 1;
		}
	}
	else {//base case, solving
		for (int i = 0; i < N; i++) {//checking possible at side 0
			if (side[i] == 0) {
				for (int j = 0; j < N; j++)
					visit[j] = 0;
				dfs2(i, 0);
				break;
			}
		}
		int check = 1;
		for (int i = 0; i < N; i++)
			if (side[i] == 0)
				check *= visit[i];
		if (check == 0)//impossilbe case not connected
			return;

		for (int i = 0; i < N; i++) {//checking possible at side 1
			if (side[i] == 1) {
				for (int j = 0; j < N; j++)
					visit[j] = 0;
				dfs2(i, 1);
				break;
			}
		}
		check = 1;
		for (int i = 0; i < N; i++)
			if (side[i] == 1)
				check *= visit[i];
		if (check == 0)//impossible case not connected
			return;
		//calculate people_num, criteria : side 0
		int* people_sum;
		int num1 = 0;
		people_sum = &num1;
		for (int i = 0; i < N; i++) {
			if (side[i] == 0) {
				for (int j = 0; j < N; j++) {
					visit[j] = 0;
				}
				dfs3(i, people_sum);
				break;
			}
		}
		if(ans > abs((total_people - *people_sum) - *people_sum ))
			ans = abs(total_people - 2 * (*people_sum));
	}
	return;
}

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &people[i]);
		total_people += people[i];
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			map[i][j] = 0;
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		for (int j = 0; j < temp; j++) {
			int temp2;
			scanf("%d", &temp2);
			map[i][temp2 - 1] = 1;
			map[temp2 - 1][i] = 1;
		}
	}
	for (int i = 0; i < N; i++)
		visit[i] = 0;
	for (int i = 0; i < N; i++) {
		if (visit[i] == 0) {
			dfs1(i);
			cnt++;
		}
	}
	if (cnt > 2) {
		printf("%d\n", -1);
	}
	else if (cnt == 2) {
		for (int i = 0; i < N; i++)
			visit[i] = 0;
		dfs1(0);
		int temp_people = 0;
		for (int i = 0; i < N; i++)
			if (visit[i] == 1)
				temp_people += people[i];
		printf("%d\n", abs((total_people - temp_people) - temp_people));
	}
	else {
		for (int i = 0; i < N; i++)
			visit[i] = 0;
		for (int i = 1; i <= N / 2; i++) {
			for (int j = 0; j < N; j++)
				side[j] = 1;
			//solve i, 0, 0
			solve(i, 0, 0);
		}
		printf("%d\n", ans);
	}

}



