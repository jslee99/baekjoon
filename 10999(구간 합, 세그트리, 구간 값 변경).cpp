#include<iostream>

using namespace std;

long long a[1000005];
int n, m, k, q;

class node {
public:
	int l;
	int r;
	long long s;
	long long u;
	int m;
};

node s[4000005];

void build(int nd, int l, int r) {
	s[nd].l = l, s[nd].r = r, s[nd].m = (l + r) / 2, s[nd].u = 0;
	if (l == r) {
		s[nd].s = a[l];
		return;
	}

	build(2 * nd, l, s[nd].m);
	build(2 * nd + 1, s[nd].m + 1, r);
	s[nd].s = s[2 * nd].s + s[2 * nd + 1].s;
}

long long query(int nd, int l, int r) {
	if (s[nd].l == l && s[nd].r == r) {
		return s[nd].s + s[nd].u * (r - l + 1);
	}

	if (r <= s[nd].m) {
		return query(2 * nd, l, r) + s[nd].u * (r - l + 1);
	}
	else if (s[nd].m < l) {
		return query(2 * nd + 1, l, r) + s[nd].u * (r - l +1);
	}
	else {
		return query(2 * nd, l, s[nd].m) + query(2 * nd + 1, s[nd].m + 1, r) + s[nd].u * (r - l +1);
	}
}

void update(int nd, int l, int r, long long u) {
	if (s[nd].l == l && s[nd].r == r) {
		s[nd].u += u;
		return;
	}

	if (r <= s[nd].m) {
		update(2 * nd, l, r, u);
	}
	else if (s[nd].m < l) {
		update(2 * nd + 1, l, r, u);
	}
	else {
		update(2 * nd, l, s[nd].m, u);
		update(2 * nd + 1, s[nd].m + 1, r, u);
	}
	s[nd].s = s[2 * nd].s + (s[2 * nd].r - s[2 * nd].l + 1) * s[2 * nd].u + s[2 * nd + 1].s + (s[2 * nd + 1].r - s[2 * nd + 1].l + 1) * s[2 * nd + 1].u;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];

	build(1, 1, n);

	q = m + k;
	while (q--) {
		int a, b, c;
		long long d;
		cin >> a;
		if (a == 1) {
			//update b ~ c by d
			cin >> b >> c >> d;
			update(1, b, c, d);
		}
		else {
			//qeury b ~ c
			cin >> b >> c;
			cout << query(1, b, c) << '\n';
		}
	}
}