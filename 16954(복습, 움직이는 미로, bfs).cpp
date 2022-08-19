#include<iostream>
#include<queue>

using namespace std;
char map[8][8];
struct inform {
	pair<int, int> x_y;
	int time;
};
queue<inform*> q;
int dr[9] = { 0, -1, -1, -1, 0, 1, 1, 1, 0 };
int dc[9] = { -1, -1, 0, 1, 1, 1, 0, -1, 0 };
bool can_enter(inform* tmp) {
	if (tmp->x_y.first >= 0 && tmp->x_y.first < 8 && tmp->x_y.second >= 0 && tmp->x_y.second < 8) {
		bool flag1 = true, flag2 = true;
		if (tmp->x_y.first - (tmp->time - 1) >= 0 && map[tmp->x_y.first - (tmp->time - 1)][tmp->x_y.second] == '#') {
			flag1 = false;
		}

		if (tmp->x_y.first - tmp->time >= 0 && map[tmp->x_y.first - tmp->time][tmp->x_y.second] == '#') {
			flag2 = false;
		}


		if (flag1 && flag2) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int ans = 0;

int main(void) {
	for (int i = 0; i < 8; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < 8; j++) {
			map[i][j] = str[j];
		}
	}

	inform* s;
	s = new inform;
	s->x_y.first = 7;
	s->x_y.second = 0;
	s->time = 0;
	q.push(s);
	while (!q.empty()) {
		inform* tmp = q.front();
		q.pop();
		if (tmp->x_y.first == 0 && tmp->x_y.second == 7) {
			ans = 1;
			break;
		}

		for (int i = 0; i < 9; i++) {
			inform* _new = new inform;
			_new->x_y.first = tmp->x_y.first + dr[i];
			_new->x_y.second = tmp->x_y.second + dc[i];
			_new->time = tmp->time + 1;
			if (can_enter(_new)) {
				q.push(_new);
			}

		}
	}

	cout << ans << endl;
}
