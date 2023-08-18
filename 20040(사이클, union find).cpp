#include<iostream>
#include<algorithm>

using namespace std;
int n, m;

int p[500005];
int ans = 0;

void check(int& a, int& b) {
	if (a > b) swap(a, b);
}

int find(const int& a) {
	if (p[a] == a) return a;

	int x = find(p[a]);
	p[a] = x;
	return x;
}

void uni(const int& a, const int& b) {
	int aa = find(a);
	int bb = find(b);
	if (aa > bb) {
		p[aa] = bb;
	}
	else {
		p[bb] = aa;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++) p[i] = i;

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		check(a, b);

		if (find(a) == find(b)) {
			ans = i;
			break;
		}
		else {
			uni(a, b);
		}
	}

	cout << ans << '\n';
}