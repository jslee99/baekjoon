#include<iostream>

using namespace std;

bool block[505][505];
bool leftBlock[505][505];
bool rightBlock[505][505];
int h, w;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> h >> w;
	for (int i = 1; i <= w; i++) {
		int a;
		cin >> a;
		for (int j = 1; j <= a; j++) {
			block[i][j] = true;
		}
	}

	for (int j = 1; j <= h; j++) {
		if (!block[1][j]) leftBlock[1][j] = false;
		else leftBlock[1][j] = true;
	}

	for (int j = 1; j <= h; j++) {
		if (!block[w][j]) rightBlock[w][j] = false;
		else rightBlock[w][j] = true;
	}

	for (int i = 2; i <= w; i++) {
		for (int j = 1; j <= h; j++) {
			if (!block[i][j]) {
				if (!block[i - 1][j] && leftBlock[i - 1][j]) {
					leftBlock[i][j] = true;
				}
				else if (block[i - 1][j]) {
					leftBlock[i][j] = true;
				}
				else {
					leftBlock[i][j] = false;
				}
			}
		}
	}

	for (int i = w - 1; i >= 1; i--) {
		for (int j = 1; j <= h; j++) {
			if (!block[i][j]) {
				if (block[i + 1][j]) {
					rightBlock[i][j] = true;
				}
				else if (!block[i + 1][j] && rightBlock[i + 1][j]) {
					rightBlock[i][j] = true;
				}
				else {
					rightBlock[i][j] = false;
				}
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= w; i++) {
		for (int j = 1; j <= h; j++) {
			if (!block[i][j] && leftBlock[i][j] && rightBlock[i][j]) ans++;
		}
	}

	cout << ans << '\n';

	
	return 0;
}