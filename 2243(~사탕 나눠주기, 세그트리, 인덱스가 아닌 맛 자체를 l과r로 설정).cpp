#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class node {// 사탕의 맛이 l인거부터 r인거까지의 cnt
public:
	int l;
	int r;
	int cnt;
	int m;
};

int n;
node st[4000005];

void build(int nd, int l, int r) {
	st[nd].l = l, st[nd].r = r, st[nd].m = (l + r) / 2, st[nd].cnt = 0;
	if (l != r) {
		build(2 * nd, l, st[nd].m);
		build(2 * nd + 1, st[nd].m + 1, r);
	}
}

int query(int nd, int q) {
	if (st[nd].l == st[nd].r) {
		return st[nd].l;
	}

	if (q <= st[2 * nd].cnt) {
		return query(2 * nd, q);
	}
	else {
		return query(2 * nd + 1, q - st[2 * nd].cnt);
	}
}

void update(int nd, int m, int u) {
	if (m == st[nd].l && m == st[nd].r) {
		st[nd].cnt += u;
		return;
	}

	if (m <= st[nd].m) {
		update(2 * nd, m, u);
	}
	else {
		update(2 * nd + 1, m, u);
	}
	st[nd].cnt = st[2 * nd].cnt + st[2 * nd + 1].cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	build(1, 1, 1000000);

	while (n--) {
		int a, b, c;
		cin >> a;
		if (a == 1) {
			cin >> b;
			int m = query(1, b);
			cout << m << '\n';
			update(1, m, -1);
		}
		else {
			cin >> b >> c;
			update(1, b, c);
		}
	}

	return 0;
}