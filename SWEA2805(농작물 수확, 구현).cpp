#include<iostream>

using namespace std;

int T, n;
int map[55][55];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < n; j++) map[i][j] = str[j] - '0';
		}
			

		int ans = 0;
		for (int i = 0; i < n; i++) {
			int a = min(i, n - i - 1);
			for (int j = n / 2 - a; j <= n / 2 + a; j++) {
				ans += map[i][j];
			}
		}

		cout << '#' << t << ' ' << ans << '\n';
	}
}