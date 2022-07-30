#include<iostream>
#include<string>

using namespace std;
string crypt;
int dp[5000];

bool is_zero(int i) {
	return crypt[i] == '0';
}

bool is_over(int i) {//tmp[i - 1 : i + 1]을 검사하는 함수
	string tmp;
	tmp.push_back(crypt[i - 1]);
	tmp.push_back(crypt[i]);
	return stoi(tmp) > 26 || stoi(tmp) < 1 || is_zero(i - 1);
}

bool is_impossible(int i) {
	return is_zero(i) && is_over(i);
}



int main(void){
	cin >> crypt;
	if (crypt[0] == '0') {
		cout << 0 << endl;
		exit(0);
	}
	else {
		dp[0] = 1;
	}

	if (is_impossible(1)) {
		cout << 0 << endl;
		exit(0);
	}
	else {
		if (!is_zero(1)) {
			dp[1] += dp[0];
		}
		if (!is_over(1)) {
			dp[1] += 1;
		}
	}

	for (int i = 2; i < (int)crypt.length(); i++) {
		if (is_impossible(i)) {
			cout << 0 << endl;
			exit(0);
		}

		if (!is_zero(i)) {
			dp[i] = (dp[i] + dp[i - 1]) % 1000000;
		}

		if (!is_over(i)) {
			dp[i] = (dp[i] + dp[i - 2]) % 1000000;
		}
	}

	cout << dp[(int)crypt.length() - 1] << endl;
}