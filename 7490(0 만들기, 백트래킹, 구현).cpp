#include<iostream>
#include<vector>
#include<string>

using namespace std;

int t, n;
char op[15];
vector<string> ans;

void calc() {
	string s;
	for (int i = 1; i < n; i++) {
		s.push_back(i + '0');
		s.push_back(op[i]);
	}
	s.push_back(n + '0');

	string tmp = s;

	//tmp = "1-2-3 4-5+6 7";

	string::iterator it = tmp.begin();
	while (it != tmp.end()) {
		if (*it == ' ') {
			it = tmp.erase(it);
		}
		else {
			it++;
		}
	}

	string num;
	vector<int> numV;
	vector<char> opV;
	
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] != '+' && tmp[i] != '-') {
			num.push_back(tmp[i]);
		}
		else {
			numV.push_back(stoi(num));
			num.clear();
			opV.push_back(tmp[i]);
		}
	}
	numV.push_back(stoi(num));

	int res = numV[0];

	for (int i = 0; i < opV.size(); i++) {
		if (opV[i] == '+') {
			res += numV[i + 1];
		}
		else {
			res -= numV[i + 1];
		}
	}

	if (res == 0) {
		ans.push_back(s);
	}

	return;
}

void func(int x) {
	if (x == n) {
		calc();
		return;
	}

	op[x] = ' ';
	func(x + 1);

	op[x] = '+';
	func(x + 1);

	op[x] = '-';
	func(x + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	while (t--) {
		cin >> n;
		ans.clear();
		func(1);

		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << '\n';
		}
		
		cout << '\n';
	}
}