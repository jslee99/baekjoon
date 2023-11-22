#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int, pair<int, int>>> v;//학생 번호, 추천, query순서

int n, m;

bool isIn(int a) {
	vector<pair<int, pair<int, int>>>::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		if (it->first == a) {
			it->second.first++;
			return true;
		}
	}
	return false;
}

bool cmp(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
	if (a.second.first > b.second.first) {
		return true;
	}
	else if (a.second.first < b.second.first) {
		return false;
	}
	else {
		if (a.second.second > b.second.second)
			return true;
		else
			return false;
	}
}

bool cmp2(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int q = 1; q <= m; q++) {
		int a;
		cin >> a;

		if (isIn(a)) {
			sort(v.begin(), v.end(), cmp);
		}
		else {
			if (v.size() >= n) 
				v.erase(--v.end());
			v.push_back(make_pair(a, make_pair(1, q)));
			sort(v.begin(), v.end(), cmp);
		}
	}
	
	sort(v.begin(), v.end(), cmp2);

	for (vector<pair<int, pair<int, int>>>::iterator it = v.begin(); it != v.end(); it++) {
		cout << it->first << ' ';
	}

	return 0;
}