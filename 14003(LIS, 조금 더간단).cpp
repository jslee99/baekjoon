#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int a[1000005];
int lis[1000005];
int n;
vector<int> v;
int maxLen;

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
		vector<int>::iterator it = lower_bound(v.begin(), v.end(), a[i]);
		if (it == v.end()) {
			lis[i] = v.size();
			v.push_back(a[i]);
		}
		else {
			lis[i] = it - v.begin();
			*it = a[i];
		}
	}

	maxLen = v.size() - 1;

	int len = maxLen;
	v.clear();
	for (int i = n; i >= 1; i--) {// lis가 maxLen인 놈, maxLen - 1인 놈..... 을 뒤에서부터 찾는다.
		if (lis[i] == len) v.push_back(a[i]), len--;
	}
	sort(v.begin(), v.end());
	cout << maxLen << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
}