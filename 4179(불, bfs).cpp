#include<iostream>
#include<queue>

using namespace std;

class TRI {
public:
	int r;
	int c;
	int w;
};

int r, c;
char map[1005][1005];
int fire[1005][1005];
int sam[1005][1005];
int dr[4] = { -1, 0 , 1, 0 };
int dc[4] = { 0, -1, 0, 1 };
queue<TRI> q;

bool isIn(int rr, int cc) {
	return rr >= 0 && rr < r&& cc >= 0 && cc < c;
}

//���̰ų�, fire���� �ʰų�, �̹� �Ǿ� �ְų�, �ٱ��̰ų�
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;

	TRI s;
	vector<TRI> ff;
	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < c; j++) {
			map[i][j] = str[j];
			if (map[i][j] == 'J') {
				s.r = i, s.c = j, s.w = 0;
			}
			else if (map[i][j] == 'F') {
				TRI f;
				f.r = i, f.c = j, f.w = 0;
				ff.push_back(f);
			}
		}
	}

	for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) {
		fire[i][j] = -1;
		sam[i][j] = -1;
	}

	for (int i = 0; i < ff.size(); i++) {
		q.push(ff[i]);
	}
	while (!q.empty()) {
		TRI x = q.front();
		q.pop();

		if (!isIn(x.r, x.c) || fire[x.r][x.c] != -1 || map[x.r][x.c] == '#') continue;

		fire[x.r][x.c] = x.w;
		for (int k = 0; k < 4; k++) {
			TRI y;
			y.r = x.r + dr[k], y.c = x.c + dc[k], y.w = x.w + 1;
			q.push(y);
		}
	}

	q.push(s);
	while (!q.empty()) {
		TRI x = q.front();
		q.pop();

		if (!isIn(x.r, x.c) || sam[x.r][x.c] != -1 || map[x.r][x.c] == '#' || (fire[x.r][x.c] != -1 && x.w >= fire[x.r][x.c])) continue;

		sam[x.r][x.c] = x.w;
		for (int k = 0; k < 4; k++) {
			TRI y;
			y.r = x.r + dr[k], y.c = x.c + dc[k], y.w = x.w + 1;
			q.push(y);
		}
	}

	int ans = 5000;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (i == 0 || i == r - 1 || j == 0 || j == c - 1) {
				if (sam[i][j] != -1) {
					ans = min(ans, sam[i][j]);
				}
			}
		}
	}
	ans++;
	if (ans == 5001) {
		cout << "IMPOSSIBLE" << '\n';
	}
	else {
		cout << ans << '\n';
	}
}

//bfs�� �ι��Ѵ� ó������ �ұ��� bfs�Ͽ� �ұ��� Ư�� ĭ�� ���ؼ� ��� �ð��뿡 �����ϴ��� �˾Ƴ���
//�״��� �����̿� ���Ͽ� bfs�� �ϴµ�    �̶� Ư�� ĭ�� ���� �ұ��� �����ϴ� �ð����� �����̰� �����ϴ� �ð��� ���ų� ��ũ�� �� ĭ���δ� ������ �� ����.