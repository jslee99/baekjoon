#include<iostream>
#include<vector>

using namespace std;

int TC;

void func(int building, int dp[], vector<int> before_building[], int build_time[]) {
	if (dp[building] != -1) {
		return;
	}

	int max_before_build_time = 0;
	for (int i = 0; i < (int)before_building[building].size(); i++) {
		func(before_building[building][i], dp, before_building, build_time);
		max_before_build_time = max(max_before_build_time, dp[before_building[building][i]]);
	}

	dp[building] = max_before_build_time + build_time[building];
	return;
}

int main(void) {
	cin >> TC;

	while (TC--) {
		int N, K, W;
		int build_time[1001];
		vector<int> before_building[1001];
		int dp[1001];

		cin >> N >> K;

		for (int i = 1; i <= N; i++) dp[i] = -1;
		
		for (int i = 1; i <= N; i++) cin >> build_time[i];

		while (K--) {
			int X, Y;
			cin >> X >> Y;
			before_building[Y].push_back(X);
		}
		cin >> W;

		func(W, dp, before_building, build_time);
		
		cout << dp[W] << endl;
	}
}