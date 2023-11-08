#include<iostream>

using namespace std;

int n;
int b[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int t = 1; t <= 10; t++) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> b[i];

		int ans = 0;
		for (int i = 3; i <= n - 2; i++) {
			int m = max(b[i - 2], max(b[i - 1], max(b[i + 1], b[i + 2])));
			if (m >= b[i]) {

			}
			else {
				ans += b[i] - m;
			}
		}

		cout << '#' << t << ' ' << ans << '\n';
	}
}