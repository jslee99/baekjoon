#include<iostream>

using namespace std;

int n, m;
int set[1000001];

int find(int x) {
	if (set[x] == x) {
		return x;
	}
	else {
		int p = find(set[x]);
		set[x] = p;
		return p;
	}
}

void uni(int x, int y) {
	int px = find(x);
	int py = find(y);

	if (px > py) {
		set[px] = py;
	}
	else if (px < py) {
		set[py] = px;
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i <= n; i++) set[i] = i;

	for (int i = 0; i < m; i++) {
		int op, a, b;
		scanf("%d %d %d", &op, &a, &b);
		if (op == 0) {
			uni(a, b);
		}
		else {
			if (find(a) == find(b)) printf("YES\n");
			else printf("NO\n");
		}
	}
}