#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
long long m;
vector<long long> a;

bool check(long long h) {
	vector<long long>::iterator it =  lower_bound(a.begin(), a.end(), h);

	long long res = 0;
	for (it; it != a.end(); it++) {
		res += *it - h;
	}

	return res >= m;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		long long b;
		cin >> b;
		a.push_back(b);
	} 

	sort(a.begin(), a.end());

	long long l = 0;
	long long r = a[n - 1];
	//int r = 30;
	while (l + 1 < r) {
		long long mid = (l + r) / 2;
		if (check(mid)) {
			l = mid;
		}
		else {
			r = mid;
		}
	}

	cout << l << '\n';

	return 0;
}