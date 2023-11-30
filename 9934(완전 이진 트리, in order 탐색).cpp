#include <iostream>
#include<vector>
#include<cmath>

using namespace std;

int k, n;
int a[1100];
vector<int> v[20];

void f(int l, int r, int lvl) {
	if (l == r) {
		v[lvl].push_back(a[l]);
		return;
	}
	int m = (l + r) / 2;
	v[lvl].push_back(a[m]);
	f(l, m - 1, lvl + 1);
	f(m + 1, r, lvl + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> k;
	
	n = pow(2, k) - 1;

	for (int i = 1; i <= n; i++) cin >> a[i];

	f(1, n, 1);

	for (int i = 1; i <= k; i++) {
		vector<int>::iterator it;
		for (it = v[i].begin(); it != v[i].end(); it++) {
			cout << *it << ' ';
		}
		cout << '\n';
	}

	return 0;
}