#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int a[1000005];
int lis[1000005];
int lds[1000005];
int n;
vector<int> v;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	v.push_back(-1000000001);
	for (int i = 1; i <= n; i++) {
		vector<int>::iterator it =  lower_bound(v.begin(), v.end(), a[i]);
		if (it == v.end()) {
			lis[i] = v.size();
			v.push_back(a[i]);
		}
		else {
			lis[i] = it - v.begin();
			*it = a[i];
		}
	}

	v.clear();
	v.push_back(1000000001);
	for (int i = n; i >= 1; i--) {
		vector<int>::iterator it = lower_bound(v.begin(), v.end(), a[i], cmp);
		if (it == v.end()) {
			lds[i] = v.size();
			v.push_back(a[i]);
		}
		else {
			lds[i] = it - v.begin();
			*it = a[i];
		}
	}

	v.clear();
	int ans = -1;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, lis[i] + lds[i] - 1);
	}

	cout << ans << '\n';
	for (int i = 1; i <= n; i++) {
		if (lis[i] + lds[i] - 1 == ans) v.push_back(a[i]);
	}

	vector<int> vv;
	vv.push_back(-1000000001);
	for (int i = 0; i < v.size(); i++) {
		if (vv.back() < v[i]) vv.push_back(v[i]);
	}

	for (int i = 1; i < vv.size(); i++) {
		cout << vv[i] << ' ';
	}
	cout << '\n';

	return 0;
}