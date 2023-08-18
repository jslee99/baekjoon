#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int a[2005];
int lis[2005];
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	v.push_back(-100000001);

	
	for (int i = 1; i <= n; i++) {
		vector<int>::iterator it = lower_bound(v.begin(), v.end(), a[i]);

		if (it == v.end()) {
			v.push_back(a[i]);
			lis[i] = v.size() - 1;
		}
		else {
			*it = a[i];
			lis[i] = it - v.begin();
		}
	}

	cout << v.size() - 1 << '\n';
	int len = v.size() - 1;
	vector<int> ans;
	for (int i = n; i >= 1; i--) {
		if (len == lis[i]) ans.push_back(a[i]), len--;
	}
	
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << ' ';
	}

	return 0;
}