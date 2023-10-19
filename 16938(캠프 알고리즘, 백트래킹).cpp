#include<iostream>
#include<algorithm>
#include<queue>
#include<functional>

using namespace std;

int n, l, r, x;
int a[20];
bool c[20];
int ans = 0;

void calc() {
	int s = 0;
	for (int i = 1; i <= n; i++) {
		if (c[i]) s++;
	}
	if (s < 2) return;
	s = 0;

	for (int i = 1; i <= n; i++) {
		if (c[i]) s += a[i];
	}
	if (!(l <= s && s <= r)) return;

	int q = 1000000, w = 0;

	for (int i = 1; i <= n; i++) {
		if (c[i]) {
			q = min(q, a[i]);
			w = max(w, a[i]);
		}
	}
	if (w - q < x) return;

	ans++;
	return;

}

void f(int x) {
	if (x == n + 1) {
		calc();
		return;
	}

	c[x] = true;
	f(x + 1);
	c[x] = false;
	f(x + 1);
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> l >> r >> x;
	for (int i = 1; i <= n; i++) cin >> a[i];

	f(1);

	cout << ans;

	return 0;
}