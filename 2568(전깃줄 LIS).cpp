#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int n;
pair<int, int> a[100005];
int lis[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		a[i].first = v[i].second;
		a[i].second = v[i].first;
	}

	vector<int> tv;
	tv.push_back(-1);
	for (int i = 0; i < n; i++) {
		vector<int>::iterator it = lower_bound(tv.begin(), tv.end(), a[i].first);
		if (it == tv.end()) {
			lis[i] = tv.size();
			tv.push_back(a[i].first);
		}
		else {
			lis[i] = it - tv.begin();
			*it = a[i].first;
		}
	}

	int maxLen = tv.size() - 1;
	int len = maxLen;
	vector<int> ans;
	for (int i = n - 1; i >= 0; i--) {
		if (lis[i] == len) len--;
		else ans.push_back(a[i].second);
	}

	cout << n - maxLen << '\n';

	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << '\n';
	}
	

	return 0;
}