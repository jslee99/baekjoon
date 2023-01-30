#include<iostream>
#include<string>

using namespace std;

string dp[101][101];
int n, m;

string add_string(string n1, string n2) {
	int max_len = max((int)n1.size(), (int)n2.size());

	while (max_len > (int)n1.size()) {
		n1.insert(n1.begin(), '0');
	}
	while (max_len > (int)n2.size()) {
		n2.insert(n2.begin(), '0');
	}

	string ans;
	int carry = 0, add, mod;
	for (int i = max_len - 1; i >= 0; i--) {
		add = (n1[i] - '0') + (n2[i] - '0') + carry;
		if (add > 9) {
			carry = 1;
		}
		else {
			carry = 0;
		}
		mod = add % 10;
		ans.insert(ans.begin() , mod + '0');
	}
	if (carry == 1) {
		ans.insert(ans.begin(), '1');
	}

	return ans;
}

void comb(int n, int m) {
	if (dp[n][m] != "0") {
		return;
	}

	if (m == 1) {
		dp[n][m] = to_string(n);
		return ;
	}
	else if (n == m) {
		dp[n][m] = to_string(1);
		return;
	}
	else {
		comb(n - 1, m - 1);
		comb(n - 1, m);
		dp[n][m] = add_string(dp[n - 1][m - 1], dp[n - 1][m]);
		return ;
	}
}

int main(void) {
	for (int i = 0; i < 101; i++) for (int j = 0; j < 101; j++) dp[i][j] = "0";

	cin >> n >> m;
	comb(n, m);
	cout << dp[n][m] << endl;
}