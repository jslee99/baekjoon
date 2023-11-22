#include <iostream>

using namespace std;

string str;
int q;
int num[200005][26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> str;
	cin >> q;

	num[0][str[0] - 'a'] = 1;
	for (int i = 1; i < str.size(); i++) {
		int a = str[i] - 'a';
		for (int j = 0; j < 26; j++)
			num[i][j] = num[i - 1][j];
		num[i][a]++;
	}
	

	while (q--) {
		char ch;
		int l, r;
		cin >> ch;
		cin >> l >> r;
		int a = ch - 'a';
		if (l == 0) {
			cout << num[r][a] << '\n';
		}
		else {
			cout << num[r][a] - num[l - 1][a] << '\n';
		}
	}

	return 0;
}