#include<iostream>

using namespace std;

long long a[1000005];
class node {
public:
	int l;
	int r;
	long long res;
	int m;
};

node s[4000010];

int n, m, k;
int q;
long long mod = 1000000007;

void build(int nd, int l, int r) {
	s[nd].l = l, s[nd].r = r, s[nd].m = (l + r) / 2;
	if (l == r) {
		s[nd].res = a[l];
		return;
	}

	build(2 * nd, l, s[nd].m);
	build(2 * nd + 1, s[nd].m + 1, r);
	s[nd].res = (s[2 * nd].res * s[2 * nd + 1].res) % mod;
	return;
}

long long query(int nd, int l, int r) {
	if (s[nd].l == l && s[nd].r == r) {
		return s[nd].res;
	}

	if (r <= s[nd].m) {
		return query(2 * nd, l, r);
	}
	else if (s[nd].m < l) {
		return query(2 * nd + 1, l, r);
	}
	else {
		return (query(2 * nd, l, s[nd].m) * query(2 * nd + 1, s[nd].m + 1, r)) % mod;
	}
}

void update(int nd, int i, long long v) {
	if (s[nd].l == i && s[nd].r == i) {
		s[nd].res = v % mod;
		return;
	}

	if (i <= s[nd].m) {
		update(2 * nd, i, v);
	}
	else {
		update(2 * nd + 1, i, v);
	}

	s[nd].res = (s[2 * nd].res * s[2 * nd + 1].res) % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	q = m + k;
	for (int i = 1; i <= n; i++) {
		int aa;
		cin >> aa;
		a[i] = aa % mod;
	}

	build(1, 1, n);
	while (q--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, b, c);
		}
		else {
			cout << query(1, b, c) << '\n';
		}
	}
}