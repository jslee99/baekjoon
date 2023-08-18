#include<iostream>
#include<map>

using namespace std;

//bool visit[1001][1001][1001] = {false, };
map<pair<int, pair<int, int>>, bool> visit;

pair<int, int> f(int a, int b) {
	pair<int, int> r;
	if (a < b) {
		r.first = 2 * a;
		r.second = b - a;
	}
	else {
		r.first = a - b;
		r.second = 2 * b;
	}
	return r;
}

void dfs(int a, int b, int c) {
	map<pair<int, pair<int, int>>, bool>::iterator it;
	it = visit.find({ a, {b, c} });

	if (it != visit.end()) return;

	visit.insert({ { a, {b, c} }, true });

	if (a == b && b == c) {
		cout << 1 << '\n';
		exit(0);
	}

	// a, b
	if (a != b) {
		pair<int,int> r = f(a, b);
		dfs(r.first, r.second, c);
	}

	if (b != c) {
		pair<int, int> r = f(b, c);
		dfs(a, r.first, r.second);
	}

	if (a != c) {
		pair<int, int> r = f(a, c);
		dfs(r.first, b, r.second);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;
	dfs(a, b, c);

	cout << 0 << '\n';

	return 0;
}