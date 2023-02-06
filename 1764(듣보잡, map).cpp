#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;
map<string, bool> m;
vector<string> v;

int N, M;

int main(void) {
	cin >> N >> M;
	while (N--) {
		string str;
		cin >> str;
		m.insert(make_pair(str, 0));
	}

	while (M--) {
		string str;
		cin >> str;
		map<string,bool>::iterator iter = m.find(str);
		if (iter != m.end()) {
			v.push_back(str);
		}
	}

	sort(v.begin(), v.end());

	cout << (int)v.size() << '\n';
	vector<string>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << '\n';
	}
}