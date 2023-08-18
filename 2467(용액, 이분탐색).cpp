#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std;

int n;
int nearZero = INT_MAX;
pair<int, int> ans;
vector<int> p;
vector<int> m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a < 0) m.push_back(a);
		else p.push_back(a);
	}
	sort(p.begin(), p.end());
	sort(m.begin(), m.end());

	if (p.size() == 0) {
		cout << m[n - 2] << ' ' << m[n - 1] << '\n';
		return 0;
	}
	else if (m.size() == 0) {	
		cout << p[0] << ' ' << p[1] << '\n';
		return 0;
	}

	for (int i = 0; i < m.size(); i++) {
		int c = m[i];
		vector<int>::iterator it = lower_bound(p.begin(), p.end(), -c);

		if (it == p.begin()) {
			if (abs(*it + c) < nearZero) {
				nearZero = abs(*it + c);
				ans.first = c, ans.second = *it;
			}
		}
		else if (it == p.end()) {
			it--;
			if (abs(*it + c) < nearZero) {
				nearZero = abs(*it + c);
				ans.first = c, ans.second = *it;
			}
		}
		else {
			if (abs(*it + c) < nearZero) {
				nearZero = abs(*it + c);
				ans.first = c, ans.second = *it;
			}
			it--;
			if (abs(*it + c) < nearZero) {
				nearZero = abs(*it + c);
				ans.first = c, ans.second = *it;
			}
		}
	}

	if (m.size() >= 2) {
		vector<int>::iterator it = m.end();
		it--;
		int a = *it;
		it--;
		int b = *it;
		if (-(a + b) < nearZero) {
			nearZero = -(a + b);
			ans.first = b, ans.second = a;
		}
	}

	if (p.size() >= 2) {
		vector<int>::iterator it = p.begin();
		int a = *it;
		it++;
		int b = *it;
		if (a + b < nearZero) {
			nearZero = a + b;
			ans.first = a, ans.second = b;
		}
	}

	cout << ans.first << ' ' << ans.second << '\n';
}