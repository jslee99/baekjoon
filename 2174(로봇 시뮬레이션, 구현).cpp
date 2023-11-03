#include<iostream>

class robot {
public:
	int r;
	int c;
	int dir;
};

using namespace std;
int R, C, N, M;
robot robots[105];
int map[105][105];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};



bool isIn(int r, int c) {
	return r > 0 && r <= R && c > 0 && c <= C;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> C >> R;
	for (int i = 1; i <= R; i++) 
		for (int j = 1; j <= C; j++) {
			map[i][j] = -1;
		}
			

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int a, b;
		char c;
		cin >> a >> b;
		cin >> c;
		robots[i].r = R - b + 1;
		robots[i].c = a;
		switch (c) {
		case 'N':
			robots[i].dir = 0;
			break;
		case 'E':
			robots[i].dir = 1;
			break;
		case 'S':
			robots[i].dir = 2;
			break;
		case 'W':
			robots[i].dir = 3;
			break;
		}
		map[robots[i].r][robots[i].c] = i;
	}

	bool crash = false;
	while (M--) {
		int n, it;
		char c;
		cin >> n;
		cin >> c;
		cin >> it;
		
		switch (c) {
			case 'F': {
				int dir = robots[n].dir;
				int r = robots[n].r;
				int c = robots[n].c;
				for (int i = 1; i <= it; i++) {
					int new_r = r + dr[dir] * i, new_c = c + dc[dir] * i;
					if (!isIn(new_r, new_c)) {
						crash = true;
						cout << "Robot " << n << " crashes into the wall" << endl;
						break;
					}
					else if (map[new_r][new_c] != -1) {
						cout << "Robot " << n << " crashes into robot " << map[new_r][new_c] << endl;
						crash = true;
						break;
					}
				}
				if (!crash) {
					map[r][c] = -1;
					map[r + dr[dir] * it][c + dc[dir] * it] = n;
					robots[n].r = r + dr[dir] * it;
					robots[n].c = c + dc[dir] * it;
				}
				break;
			}
			case 'L':{
				for (int i = 0; i < it; i++) {
					robots[n].dir--;
					if (robots[n].dir < 0) robots[n].dir = 3;
				}
				break;
			}
			case 'R':{
				for (int i = 0; i < it; i++) {
					robots[n].dir++;
					if (robots[n].dir > 3) robots[n].dir = 0;
				}
				break;
			}
		}


		if (crash) {
			break;
		}
	}

	if (!crash) {
		cout << "OK" << endl;
	}
}