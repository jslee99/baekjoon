#include<iostream>
#include<string>

using namespace std;
int n;

bool ok(const string& s) {
	for (int size = 1; size * 2 <= s.size(); size++) {
		string ss2 = s.substr(s.size() - size, size);
		string ss1 = s.substr(s.size() - size * 2, size);
		if (ss1 == ss2) return false;
	}
	return true;
}

void func(string& s) {
	if (s.size() == n) {
		cout << s << '\n';
		exit(0);
		return;
	}

	s.push_back('0');
	s[s.size() - 1] = '1';
	if (ok(s)) func(s);

	s[s.size() - 1] = '2';
	if (ok(s)) func(s);

	s[s.size() - 1] = '3';
	if (ok(s)) func(s);
	s.erase(s.end() - 1);

	return;
}

int main() {
	
	cin >> n;
	string s = "";

	func(s);
}	