#include<iostream>

using namespace std;

int belt[205];
bool isRobot[205];
int stage = 0;
int n, k;
int s, e;

int goFront(int i) {
	i--;
	if (i == 0) return 2 * n;
	else return i;
}

bool check() {
	int cnt = 0;
	for (int i = 1; i <= 2 * n; i++) {
		if (belt[i] == 0) cnt++;
	}
	return cnt < k;
}

void moveBelt() {
	s--, e--;
	if (s == 0) {
		s = 2 * n;
	}
	if (e == 0) {
		e = 2 * n;
	}
}

void moveRobot() {
	int i = goFront(e);
	while (i != s) {
		if (i != 2 * n) {
			if (isRobot[i] && !isRobot[i + 1] && belt[i + 1] > 0) {
				isRobot[i + 1] = true;
				isRobot[i] = false;
				belt[i + 1]--;
			}
		}
		else {
			int next = 1;
			if (isRobot[i] && !isRobot[next] && belt[next] > 0) {
				isRobot[next] = true;
				isRobot[i] = false;
				belt[next]--;
			}
		}
		if (isRobot[e]) {
			isRobot[e] = false;
		}
		i = goFront(i);
	}

	if (belt[i] > 0) {
		isRobot[i] = true;
		belt[i]--;
	}


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= 2 * n; i++) {
		cin >> belt[i];
	}
	s = 1, e = n;

	while (1) {
		stage++;
		moveBelt();
		if (isRobot[e]) {
			isRobot[e] = false;
		}
		moveRobot();
		if (!check())break;
	}

	cout << stage << '\n';
}