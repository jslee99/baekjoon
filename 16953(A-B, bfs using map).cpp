#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;
queue<int> q;
int A, B;
unordered_map<int, int> m;

bool is_in(long long x) {
	return x >= 1 && x <= 1000000000;
}

int main() {

	cin >> A >> B;

	q.push(A);
	m.insert(make_pair(A, 1));

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		int y;
		y = 2 * x;
		if (is_in((long long)y) && m.find(y) == m.end()) {
			m.insert(make_pair(y, m.at(x) + 1));
			q.push(y);
		}

		long long z;
		z = 10 * (long long)x + 1;
		if (is_in(z) && m.find((int)z) == m.end()) {
			m.insert(make_pair((int)z, m.at(x) + 1));
			q.push((int)z);
		}
	}

	int ans;
	if (m.find(B) == m.end()) {
		ans = -1;
	}
	else {
		ans = m.at(B);
	}

	cout << ans << endl;
}