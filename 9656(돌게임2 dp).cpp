#include<iostream>
#include<algorithm>

using namespace std;

int n;
bool dp[1005];

int main() {
	cin >> n;

	dp[1] = false;
	dp[2] = true;;
	dp[3] = false;;

	for (int i = 4; i <= 1000; i++) {
		if (dp[i - 1] == true && dp[i - 3] == true) dp[i] = false;
		else dp[i] = true;
	}

	if (dp[n] == true) {
		cout << "SK";
	}
	else {
		cout << "CY";
	}

	return 0;
}