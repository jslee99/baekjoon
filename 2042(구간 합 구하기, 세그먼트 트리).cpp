#include<iostream>

using namespace std;

class node {
public:
	int left;
	int right;
	int mid;
	long long sum;
};

int n, m, k;
int t;
long long A[1000005];
node seg[4000005];

void build(int nd, int l, int r) {
	seg[nd].left = l, seg[nd].right = r, seg[nd].mid = (l + r) / 2;

	if (seg[nd].left == seg[nd].right) {
		seg[nd].sum = A[l];
		return;
	}

	build(2 * nd, seg[nd].left, seg[nd].mid);
	build(2 * nd + 1, seg[nd].mid + 1, seg[nd].right);
	seg[nd].sum = seg[2 * nd].sum + seg[2 * nd + 1].sum;
	return;
}

void update(int nd, int i, long long c) {
	if (i == seg[nd].left && i == seg[nd].right) {
		seg[nd].sum = c;
		return;
	}

	if (i <= seg[nd].mid) {
		update(2 * nd, i, c);
	}
	else {
		update(2 * nd + 1, i, c);
	}

	seg[nd].sum = seg[2 * nd].sum + seg[2 * nd + 1].sum;
	return;
}

long long sum(int nd, int l, int r) {
	if (l == seg[nd].left && r == seg[nd].right) {
		return seg[nd].sum;
	}

	if (r <= seg[nd].mid) {
		return sum(2 * nd, l, r);
	}
	else if (seg[nd].mid < l) {
		return sum(2 * nd + 1, l, r);
	}
	else {
		return sum(2 * nd, l, seg[nd].mid) + sum(2 * nd + 1, seg[nd].mid + 1, r);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	t = m + k;
	for (int i = 1; i <= n; i++) cin >> A[i];

	build(1, 1, n);

	while (t--) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, b, c);
		}
		else {
			int r = (long long)c;
			cout << sum(1, b, r) << '\n';
		}
	}

	return 0;
}