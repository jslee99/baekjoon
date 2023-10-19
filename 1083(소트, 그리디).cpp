#include<iostream>
#include<vector>

using namespace std;

int n, s;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	cin >> s;

	for (int i = 0; i < v.size() && s > 0; i++) {

		int idx = i;
		for (int j = i; j < v.size() && j <= i + s; j++) {
			if (v[j] > v[idx]) {
				idx = j;
			}
		}
		int val = v[idx];
		v.erase(v.begin() + idx);
		v.insert(v.begin() + i, val);
		s = s - (idx - i);
	}

	for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';

	return 0;
}