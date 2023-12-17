#include<iostream>

using namespace std;

int main() {
	string s1;
	string s2;
	cin >> s1 >> s2;

	int ans = 0;
	if (s1.size() != s2.size()) {
		
	}
	else {
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] == s2[i]) {
				if(s1[i] == '8')
					ans++;
			}
			else {
				break;
			}
		}
	}

	cout << ans << '\n';
}