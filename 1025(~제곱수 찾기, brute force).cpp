#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
#include<string>
#include<cmath>

using namespace std;

int n, m;
int ans = -1;
char a[15][15];

bool isIn(int r, int c) {
	return r >= 0 && r < n&& c >= 0 && c < m;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			a[i][j] = str[j];
		}
	}

	for (int a1 = 0; a1 < n; a1++) {
		for (int d1 = -(n - 1); d1 <= n - 1; d1++) {
			for (int a2 = 0; a2 < m; a2++) {
				for (int d2 = -(m - 1); d2 <= m - 1; d2++) {
					string s;
					if (d1 == 0 && d2 == 0) {
						s.push_back(a[a1][a2]);
						int res = stoi(s);
						if (sqrt(res) == (double)((int)sqrt(res))) {
							ans = max(ans, res);
						}
					}
					else {
						int r = a1, c = a2;
						int i = 1;
						while (isIn(r, c)) {
							s.push_back(a[r][c]);
							int res = stoi(s);
							if (sqrt(res) == (double)((int)sqrt(res))) {
								ans = max(ans, res);
							}
							r = a1 + i * d1;
							c = a2 + i * d2;
							i++;
						}
					}
				}
			}
		}
	}

	cout << ans << '\n';

	return 0; 
}