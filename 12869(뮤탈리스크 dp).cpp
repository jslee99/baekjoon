#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int a[3];
int n;
int ans = 99999999;
int dp[61][61][61];

class TRI {
public:
	int a;
	int b;
	int c;
};

bool allDie() {
	return a[0] <= 0 && a[1] <= 0 && a[2] <= 0;
}

bool cmp(int a, int b) {
	return a > b;
}

vector<int> getIdx() {
	vector<int> v;
	for (int i = 0; i < 3; i++) {
		if (a[i] > 0) v.push_back(i);
	}
	sort(v.begin(), v.end(), cmp);
	return v;
}

vector<int> clear() {
	vector<int> v;
	for (int i = 0; i < 3; i++) {
		if (a[i] <= 0) v.push_back(0);
		else v.push_back(a[i]);
	}
	return v;
}

void attack(int t) {
	vector<int> c = clear();
	if (dp[c[0]][c[1]][c[2]] > t) {
		dp[c[0]][c[1]][c[2]] = t;
	}
	else {
		return;
	}
	
	if (allDie()) {
		return;
	}
	
	vector<int> v = getIdx();
	if (v.size() == 1) {
		a[v[0]] -= 9;
		attack(t + 1);
		a[v[0]] += 9;
	}
	else if (v.size() == 2) {
		a[v[0]] -= 9;
		a[v[1]] -= 3;
		attack(t + 1);
		a[v[0]] += 9;
		a[v[1]] += 3;

		a[v[0]] -= 3;
		a[v[1]] -= 9;
		attack(t + 1);
		a[v[0]] += 3;
		a[v[1]] += 9;
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j) continue;

				int k = 3 - (i + j);

				a[i] -= 9;
				a[j] -= 3;
				a[k] -= 1;
				attack(t + 1);
				a[i] += 9;
				a[j] += 3;
				a[k] += 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < 61; i++) {
		for (int j = 0; j < 61; j++) {
			for (int k = 0; k < 61; k++) {
				dp[i][j][k] = 99999999;
			}
		}
	}

	attack(0);

	cout << dp[0][0][0] << '\n';
}