#include<iostream>
#include<map>

using namespace std;
int c, n;
map<string, bool> m;

string s, t;
int ans = 0;

string reverse(string x) {
	for (int i = 0; i < x.size() / 2; i++) {
		swap(x[i], x[x.size() - 1 - i]);
	}
	return x;
}

void f(string x) {
	if (x.size() == s.size()) {
		if (x == s) ans = 1;
		return;
	}

	string::iterator b = x.begin();
	string::iterator e = x.end();
	e--;
	if (*b == 'A' && *e == 'A') {	
		x.erase(e);
		f(x);
	}
	else if (*b == 'A' && *e == 'B') {
		return;
	}
	else if (*b == 'B' && *e == 'A') {
		x.erase(e);
		f(x);
		x.push_back('A');
		string y = reverse(x);
		string::iterator it = y.end();
		it--;
		y.erase(it);
		f(y);
	}
	else {
		string y = reverse(x);
		string::iterator it = y.end();
		it--;
		y.erase(it);
		f(y);
		//
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s;
	cin >> t;

	f(t);

	cout << ans << '\n';
}