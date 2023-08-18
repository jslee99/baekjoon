#include<iostream>
#include<unordered_map>

using namespace std;

long long n, p, q;
unordered_map<long long, long long> m;

long long func(long long x) {
	if (x == 0) return 1;

	long long y;
	unordered_map<long long, long long>::iterator it = m.find(x);
	if (it == m.end()) {
		y = func(x / p) + func(x / q);
		m.insert(make_pair(x, y));
		return y;
	}
	else {
		return (*it).second;
	}

	
}

int main() {
	cin >> n >> p >> q;
	cout << func(n) << endl;
}