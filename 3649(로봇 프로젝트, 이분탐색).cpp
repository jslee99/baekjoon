#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int x, n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> x >> n;
		if (cin.eof())break;
		vector<int> v;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		x = x * 10000000;

		pair<int, int> ans;
		ans.first = -1;
		for (int i = 0; i < v.size(); i++) {
			int a = v[i];
			vector<int>::iterator it = lower_bound(v.begin(), v.end(), x - a);

			if (it == v.end() || x - a != *it || i == it - v.begin()) {
				continue;
			}
			else {
				ans.first = a, ans.second = *it;
				break;
			}
		}

		if (ans.first == -1) {
			cout << "danger" << '\n';
		}
		else {
			cout << "yes " << ans.first << ' ' << ans.second << '\n';
		}
	}

	return 0;
}