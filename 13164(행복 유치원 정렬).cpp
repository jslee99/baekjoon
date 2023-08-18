#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long a[300005];
int n, k;
vector<pair<int, long long>> v;
vector<pair<int, long long>> v2;

bool cmp(pair<int, long long>& a, pair<int, long long>& b) {
	return a.second > b.second;
}

bool cmp2(pair<int, long long>& a, pair<int, long long>& b) {
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;

	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i < n; i++) {
		v.push_back(make_pair(i, a[i + 1] - a[i]));
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < k - 1; i++) {
		v2.push_back(v[i]);
	}

	sort(v2.begin(), v2.end(), cmp2);


	long long ans = 0;
	int s = 1;
	int e;
	for (int i = 0; i < k - 1; i++) {
		e = v2[i].first;
		ans += a[e] - a[s];
		s = e + 1;
	}

	ans += a[n] - a[s];

	cout << ans << '\n';
}