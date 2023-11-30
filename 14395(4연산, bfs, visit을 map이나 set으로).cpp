#include <iostream>
#include<map>
#include<queue>

using namespace std;

map<long long, long long> visit; // node, dist
queue<pair<long long, string>> q; // node, 연산
vector<string> ans;

long long s, t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s >> t;

	q.push(make_pair(s, ""));

	while (!q.empty()) {
		pair<long long, string> x = q.front();
		q.pop();

		if (x.first < 1 || x.first > 1000000000) continue;

		map<long long, long long>::iterator it = visit.find(x.first);
		if (it != visit.end()) {
			if (it->second < x.second.size())
				continue;
		}
		else {
			visit.insert(make_pair(x.first, x.second.size()));
		}

		if (x.first == t) {
			ans.push_back(x.second);
		}

		long long new_n;
		new_n = x.first * x.first;
		q.push(make_pair(new_n, x.second + '*'));

		new_n = x.first + x.first;
		q.push(make_pair(new_n, x.second + '+'));

		new_n = x.first - x.first;
		q.push(make_pair(new_n, x.second + '-'));

		new_n = x.first / x.first;
		q.push(make_pair(new_n, x.second + '/'));
	}

	if (ans.size() == 0) {
		cout << -1 << '\n';
	}
	else {
		if (ans.begin()->size() == 0) {
			cout << 0 << '\n';
		}
		else {
			cout << *ans.begin() << '\n';
		}
		
	}


	return 0;
}