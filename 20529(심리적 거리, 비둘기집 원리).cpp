#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int t;
int n;
string a[100005];
vector<int> v;
int ans;

int dif(string s1, string s2) {
	int res = 0;
	for (int i = 0; i < 4; i++) {
		if (s1[i] != s2[i]) res++;
	}
	return res;
}

void calc() {
	int res = 0;
	res += dif(a[v[0]], a[v[1]]);
	res += dif(a[v[1]], a[v[2]]);
	res += dif(a[v[0]], a[v[2]]);
	ans = min(ans, res);
}

void func(int idx) {
	if (v.size() == 3) {
		calc();
		return;
	}

	for (int i = idx + 1; i < n; i++) {
		v.push_back(i);
		func(i);
		v.erase(--v.end());
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];

		if (n > 32) {
			cout << 0 << '\n';
			continue;
		}

		ans = 999999;
		func(-1);
		cout << ans << '\n';
	}
}