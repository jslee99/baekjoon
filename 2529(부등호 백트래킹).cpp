#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int nn;
char op[15];
bool use[10];
int m[15];
vector<string> v;

void clear() {
	for (int i = 0; i < 10; i++) use[i] = false;
}

void g() {
	string s;
	for (int i = 0; i < nn + 1; i++) s.push_back('0' + m[i]);
	v.push_back(s);
}

void f(int x) {
	if (x == nn + 1) {
		g();
		return;
	}


	if (x == 0) {
		for (int i = 0; i < 10; i++) {
			use[i] = true;
			m[x] = i;
			f(x + 1);
			use[i] = false;
		}
	}
	else {
		for (int i = 0; i < 10; i++) {
			if (use[i]) continue;
			
			if (op[x - 1] == '<' && m[x - 1] > i) continue;

			if (op[x - 1] == '>' && m[x - 1] < i) continue;

			m[x] = i;
			use[i] = true;
			f(x + 1);
			use[i] = false;


		}
	}
	
}

int main() {
	cin >> nn;
	for (int i = 0; i < nn; i++) {
		cin >> op[i];
	}

	clear();
	f(0);

	sort(v.begin(), v.end());

	cout << v.back() << '\n' << *(v.begin()) << '\n';

	return 0;
}