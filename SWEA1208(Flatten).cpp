#include<iostream>
#include<algorithm>

using namespace std;

int n;
int b[1005];
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int t = 1; t <= 10; t++) {
		
		cin >> n;
		for (int i = 1; i <= 100; i++) cin >> b[i];
		sort(b + 1, b + 101);

		for (int i = 1; i <= n; i++) {
			if (b[100] - b[1] == 0) {
				break;
			}
			b[1]++;
			b[100]--;
			sort(b + 1, b + 101);
		}

		ans = b[100] - b[1];

		cout << '#' << t << ' ' << ans << '\n';
	}
}