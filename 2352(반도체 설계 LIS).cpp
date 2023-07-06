#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int a[400005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	vector<int> v;
	v.push_back(-1);
	for (int i = 1; i <= n; i++) {
		vector<int>::iterator it = lower_bound(v.begin(), v.end(), a[i]);
		if (it == v.end()) {
			v.push_back(a[i]);
		}
		else {
			*it = a[i];
		}
	}

	cout << v.size() - 1 << '\n';
}