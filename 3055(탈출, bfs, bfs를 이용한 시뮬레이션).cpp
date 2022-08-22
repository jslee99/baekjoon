#include<iostream>
#include<queue>

using namespace std;
char map[50][50];
int memo[50][50];
int R, C;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int cur_time = -1;
int r, c;
bool visited[50][50];
bool visited2[50][50];
struct inform {
	int r, c;
	int time;
};
queue<inform*> q;
queue<inform*> q2;

bool can_enter(inform* tmp) {
	return tmp->r >= 0 && tmp->r < R&& tmp->c >= 0 && tmp->c < C&& map[tmp->r][tmp->c] != 'X' && map[tmp->r][tmp->c] != '*' && !visited[tmp->r][tmp->c];
}

bool can_enter2(inform* tmp) {
	return tmp->r >= 0 && tmp->r < R&& tmp->c >= 0 && tmp->c < C&& map[tmp->r][tmp->c] != 'X' && map[tmp->r][tmp->c] != '*' && map[tmp->r][tmp->c] != 'D' && !visited2[tmp->r][tmp->c];
}

void simulation() {
	inform* cur;
	while (!q2.empty() && q2.front()->time <= cur_time) {
		cur = q2.front();
		q2.pop();
		map[cur->r][cur->c] = '*';

		for (int i = 0; i < 4; i++) {
			inform* tmp = new inform;
			tmp->r = cur->r + dr[i], tmp->c = cur->c + dc[i], tmp->time = cur->time + 1;
			if (can_enter2(tmp)) {
				visited2[tmp->r][tmp->c] = true;
				q2.push(tmp);
			}
		}
	}
}

int main(void) {
	cin >> R >> C;

	inform* cur = new inform;
	cur->time = 0;

	for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) memo[i][j] = -1;

	for (int i = 0; i < R; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < C; j++) {
			map[i][j] = str[j];
			if (map[i][j] == 'S') {
				map[i][j] = '.';
				cur->r = i, cur->c = j;
			}
			else if (map[i][j] == 'D') {
				r = i, c = j;
			}
			else if (map[i][j] == '*') {
				inform* tmp2 = new inform;
				tmp2->r = i, tmp2->c = j, tmp2->time = -1;
				visited2[tmp2->r][tmp2->c] = true;
				q2.push(tmp2);
			}
		}
	}

	q.push(cur);

	while (!q.empty()) {
		cur = q.front();
		q.pop();
		memo[cur->r][cur->c] = cur->time;
		if (cur->time > cur_time) {
			cur_time = cur->time;
			simulation();
		}
		
		for (int i = 0; i < 4; i++) {
			inform* tmp = new inform;
			tmp->r = cur->r + dr[i], tmp->c = cur->c + dc[i], tmp->time = cur->time + 1;
			if (can_enter(tmp)) {
				visited[tmp->r][tmp->c] = true;
				q.push(tmp);
			}
		}
	}

	if (memo[r][c] != -1) cout << memo[r][c] << endl;
	else cout << "KAKTUS" << endl;
}