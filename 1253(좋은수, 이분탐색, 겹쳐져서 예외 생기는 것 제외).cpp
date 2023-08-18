#include<iostream>
#include<algorithm>

using namespace std;

int n;
int a[2005];
bool good[2005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) good[i] = false;

	sort(a, a + n);

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {
			if (i == j) continue;

			int y = a[i] - a[j];
			int idx = lower_bound(a, a + n, y) - a;

			if (idx == n || a[idx] != y) continue;

			for (int k = idx; k < n && a[k] == y; k++) {
				if (k != i && k != j) {
					good[i] = true;
				}
			}

			if (good[i]) break;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (good[i]) ans++;
	}

	cout << ans << '\n';
}


/*
			if (idx == i) {
				if (idx < n - 1) {
					idx++;
					if (a[i] == a[j] + a[idx]) {
						good[i] = true;
						break;
					}
				}
			}
			else if (idx == j) {
				if (idx < n - 1) {
					idx++;
					if (a[i] == a[j] + a[idx]) {
						good[i] = true;
						break;
					}
				}
			}
			else {
				good[i] = true;
				break;
			}
*/