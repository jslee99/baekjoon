#include <iostream>

using namespace std;

class node {
public:
	int l;
	int m;
	int r;
	int num[26];
};

node t[800005];
string str;
int q;

void init(int x, int l, int r) {
	t[x].l = l, t[x].r = r, t[x].m = (l + r) / 2;
	if (l == r) {
		t[x].num[str[l] - 'a'] = 1;
		return;
	}

	init(2 * x, t[x].l, t[x].m);
	init(2 * x + 1, t[x].m + 1, t[x].r);
	for (int i = 0; i < 26; i++) {
		t[x].num[i] = t[2 * x].num[i] + t[2 * x + 1].num[i];
	}
}

int query(int x, int a, int l, int r) {
	if (t[x].l == l && t[x].r == r) {
		return t[x].num[a];
	}

	if (r <= t[x].m) {
		return query(2 * x, a, l, r);
	}
	else if (t[x].m < l) {
		return query(2 * x + 1, a, l, r);
	}
	else {
		return query(2 * x, a, l, t[x].m) + query(2 * x + 1, a, t[x].m + 1, r);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> str;
	cin >> q;

	init(1, 0, str.size() - 1);

	while (q--) {
		char ch;
		int l, r;
		cin >> ch;
		cin >> l >> r;
		cout << query(1, ch - 'a', l, r) << '\n';
	}

	return 0;
}