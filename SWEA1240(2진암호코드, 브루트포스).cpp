#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int m, n, t;
char ch[105][150];

int getNum(string tmp) {
	if (tmp.compare("0001101") == 0) {
		return 0;
	}
	else if (tmp.compare("0011001") == 0) {
		return 1;
	}
	else if (tmp.compare("0010011") == 0) {
		return 2;
	}
	else if (tmp.compare("0111101") == 0) {
		return 3;
	}
	else if (tmp.compare("0100011") == 0) {
		return 4;
	}
	else if (tmp.compare("0110001") == 0) {
		return 5;
	}
	else if (tmp.compare("0101111") == 0) {
		return 6;
	}
	else if (tmp.compare("0111011") == 0) {
		return 7;
	}
	else if (tmp.compare("0110111") == 0) {
		return 8;
	}
	else if (tmp.compare("0001011") == 0) {
		return 9;
	}
	else {
		return -999999;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	for (int i = 1; i <= t; i++) {
		vector<int> v;
		cin >> m >> n;
		for (int i = 1; i <= m; i++) {
			string str;
			cin >> str;
			for (int j = 1; j <= n; j++) {
				ch[i][j] = str[j - 1];
				continue;
			}
		}

		bool flag = false;
		int res;
		for (int i = 1; i <= m; i++) {
			for (int j = n; j >= 1; j--) {
				if (ch[i][j] == '1') {
					flag = true;
				}

				if (flag) {
					int start = j - 7 * 8 + 1;
					
					for (int a = 0; a < 8; a++) {
						int s = start + a * 7;
						int e = s + 6;
						string tmp;
						for (int k = s; k <= e; k++) {
							tmp.push_back(ch[i][k]);
						}
						v.push_back(getNum(tmp));
					}

					int even = 0;
					int odd = 0;
					for (int a = 0; a < 8; a++) {
						if (a % 2 == 0) {
							odd += v[a];
						}
						else {
							even += v[a];
						}
					}
					res = odd * 3 + even;
					break;
				}
			}
			if (flag) {
				break;
			}
		}

		if (res % 10 == 0) {
			int ans = 0;
			for (int i = 0; i < 8; i++) {
				ans += v[i];
			}
			cout << '#' << i << ' ' << ans << '\n';
		}
		else{
			cout << '#' << i << ' ' << 0 << '\n';
		}
	}
	

	return 0;
}