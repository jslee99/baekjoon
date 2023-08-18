#include<iostream>
#include<vector>
#include<algorithm>

class talk {
public:
	int s;
	int e;
	int p;
};

using namespace std;
int n;
vector<talk> v;

int dp[1500055];

bool cmp(talk t1, talk t2) {
	return t1.e < t2.e;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int e, p;
		cin >> e >> p;
		talk t;
		t.s = i, t.e = i + e - 1, t.p = p;
		v.push_back(t);
	}

	sort(v.begin(), v.end(), cmp);


	for (int i = 1; i < v[0].e; i++) {
		dp[i] = 0;
	}

	int e = v[0].e;
	for (int i = 0; i < v.size(); i++) {
		talk x = v[i];
		if (e < x.e) {
			for (int i = e + 1; i <= x.e; i++) {
				dp[i] = dp[i - 1];
			}
			e = x.e;
		}

		dp[e] = max(dp[e], x.p + dp[x.s - 1]);
	}

	cout << dp[n] << '\n';
}