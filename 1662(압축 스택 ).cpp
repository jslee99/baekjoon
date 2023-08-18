#include<iostream>
#include<stack>

using namespace std;

stack<pair<char, int>> s; // ch, -1 or 0, n
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;
	
	

	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (c == ')') {
			int n = 0;
			while (s.top().first != '(') {
				pair<char, int> e = s.top();
				s.pop();

				if (e.first == 0) {
					n += e.second;
				}
				else {
					n++;
				}
			}
			s.pop();
			pair<char, int> e = s.top();
			s.pop();
			pair<char, int> x = { 0, 0 };
			x.second = (e.first - '0') * n;
			s.push(x);
		}
		else {
			s.push({c, -1});
		}
	}

	int ans = 0;
	while (!s.empty()) {
		pair<char, int> x = s.top();
		s.pop();
		if (x.first == 0) {
			ans += x.second;
		}
		else {
			ans++;
		}
	}

	cout << ans;

	return 0;
}