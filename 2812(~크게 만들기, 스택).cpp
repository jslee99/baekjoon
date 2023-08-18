#include<iostream>
#include<stack>
#include<string>

using namespace std;

int n, k;
string a;
int d = 0;
stack<char> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	cin >> a;

	for (int i = 0; i < a.size(); i++) {
		while (d < k && !s.empty() && s.top() < a[i]) {
			d++;
			s.pop();
		}
		s.push(a[i]);
	}

	while (d < k) {
		d++;
		s.pop();
	}

	string revAns;
	while (!s.empty()) {
		revAns.push_back(s.top());
		s.pop();
	}

	for (int i = revAns.size() - 1; i >= 0; i--) {
		cout << revAns[i];
	}
	cout << '\n';
}