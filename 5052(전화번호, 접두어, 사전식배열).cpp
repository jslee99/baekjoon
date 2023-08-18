#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, t;

void check(const string& s1, const string& s2, bool& flag) {
	if (s1.size() <= s2.size()) {
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] != s2[i]) return;
		}
		flag = true;
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n;
		vector<string> v;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			v.push_back(s);
		}

		sort(v.begin(), v.end());

		bool flag = false;

		for (int i = 0; i < n - 1; i++) {
			check(v[i], v[i + 1], flag);
		}

		if (flag) cout << "NO" << '\n';
		else cout << "YES" << '\n';
	}

	return 0;
}