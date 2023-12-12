#include <iostream>
#include<set>
#include<vector>

using namespace std;

int a[25];
int s[25];
int n;
set<int> sss;

void calc(vector<int>& v) {
	vector<int>::iterator it;
	int res = 0;
	for (it = v.begin(); it != v.end(); it++) {
		res += *it;
	}
	sss.insert(res);
}

void func(int idx, int selected_num, int max_num, vector<int>& v) {
	if (selected_num == max_num) {
		calc(v);
		return;
	}

	for (int i = idx + 1; i <= n; i++) {
		v.push_back(a[i]);
		func(i, selected_num + 1, max_num, v);
		v.erase(--v.end());
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++) {
		vector<int> v;
		func(0, 0, i, v);
	}

	for (int i = 1; i <= 2000001; i++) {
		if (sss.find(i) == sss.end()) {
			cout << i << '\n';
			return 0;
		}
	}
}