#include<iostream>
#include<unordered_map>

using namespace std;
int c, n;
unordered_map<string, bool> m;

string s, t;
int ans = 0;

string reverse(string x) {
	x.push_back('B');
	for (int i = 0; i < x.size() / 2; i++) {
		swap(x[i], x[x.size() - 1 - i]);
	}
	return x;
}

void f(string x) {
	if (x.size() == t.size()) {
		if (x == t) ans = 1;
		return;
	}

	unordered_map<string, bool>::iterator it = m.find(x);
	if (it != m.end()) {
		return;
	}
	else {
		m.insert({ x, true });
	}

	string y = x;
	y.push_back('A');
	f(y);

	string z = reverse(x);
	f(z);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s;
	cin >> t;

	f(s);

	cout << ans << '\n';

	return 0;
}