#include<iostream>
#include<queue>

using namespace std;
int N, M;
int map[1000][1000];
int is_visited_chance[1000][1000]; // ���� �ѹ��̶�(�Ⱥμ�����°� �ȵ� ������ �ѹ� �ν��ߵ�) �μ� ��쿡���� �ּ� ���
int is_visited_not_chance[1000][1000]; // ���� �ѹ��� �μ��� ���� ��쿡���� �ּҰ��
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };

struct node {
	int r, c;
	bool use_chance;// ����� �ö����� �ѹ��̶� ���� �μ����°�?
	int block_cnt;
};

bool is_in(int r, int c) {
	return r >= 0 && r < M && c >= 0 && c < N;
}

int main(void) {
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			map[i][j] = str[j] - '0';
		}
	}

	queue<node> q;
	node start;
	start.r = 0, start.c = 0, start.use_chance = false, start.block_cnt = 1;
	q.push(start);

	while (!q.empty()) {
		node x;
		x = q.front();
		q.pop();

		if (x.use_chance) {

			if (is_visited_chance[x.r][x.c]) continue;

			is_visited_chance[x.r][x.c] = x.block_cnt;

			node y;
			for (int i = 0; i < 4; i++) {
				y.r = x.r + dr[i], y.c = x.c + dc[i];
				if (!is_in(y.r, y.c)) continue;

				if (map[y.r][y.c] == 1) {
					continue;
				}
				else {
					y.block_cnt = x.block_cnt + 1;
					y.use_chance = true;
					q.push(y);
				}

				
			}
		}
		else {

			if (is_visited_not_chance[x.r][x.c]) continue;

			is_visited_not_chance[x.r][x.c] = x.block_cnt;

			node y;
			for (int i = 0; i < 4; i++) {
				y.r = x.r + dr[i], y.c = x.c + dc[i];
				if (!is_in(y.r, y.c))continue;

				if (map[y.r][y.c] == 1) {
					y.block_cnt = x.block_cnt + 1;
					y.use_chance = true;
					q.push(y);
				}
				else {
					y.block_cnt = x.block_cnt + 1;
					y.use_chance = false;
					q.push(y);
				}
			}

		}	
	}

	if (!is_visited_chance[M - 1][N - 1] && !is_visited_not_chance[M - 1][N - 1]) {
		cout << -1 << endl;
	}
	else if (is_visited_chance[M - 1][N - 1] && !is_visited_not_chance[M - 1][N - 1]) {
		cout << is_visited_chance[M - 1][N - 1] << endl;
	}
	else if (!is_visited_chance[M - 1][N - 1] && is_visited_not_chance[M - 1][N - 1]) {
		cout << is_visited_not_chance[M - 1][N - 1] << endl; //���� ���� map�� ��� �����ϴ�.
	}
	else {
		cout << min(is_visited_chance[M - 1][N - 1], is_visited_not_chance[M - 1][N - 1]) << endl;
	}

}