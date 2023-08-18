#include<iostream>
#include<algorithm>

using namespace std;

int n;
int a[55];
int res[55];


bool turnRight(pair<long long, long long> a1, pair<long long, long long> a2, pair<long long, long long> a3) {
	return (a2.first - a1.first) * (a3.second - a1.second) - (a3.first - a1.first) * (a2.second - a1.second) < 0;
}



bool turnLeft(pair<long long, long long> a1, pair<long long, long long> a2, pair<long long, long long> a3) {
	return (a2.first - a1.first) * (a3.second - a1.second) - (a3.first - a1.first) * (a2.second - a1.second) > 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i - 1; j++) {
			bool flag = true;
			for (int k = j + 1; k <= i - 1; k++) {
				if (!turnRight({ j, a[j] }, { i, a[i] }, { k, a[k] })) {
					flag = false;
				}
			}

			if (flag) res[i]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			bool flag = true;
			for (int k = i + 1; k <= j - 1; k++) {
				if (!turnLeft({ j, a[j] }, { i, a[i] }, { k, a[k] })) flag = false;
			}
			
			if (flag) res[i]++;
		}
	}

	sort(res + 1, res + n + 1);

	cout << res[n] << '\n';
}