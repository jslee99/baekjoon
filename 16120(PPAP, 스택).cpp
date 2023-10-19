#include<iostream>
#include<stack>

using namespace std;

string a;
stack<char> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a;

	for (int i = 0; i < a.size(); i++) {
		char c = a[i];
		s.push(c);

		while (s.size() >= 4) {
			string tmp;
			for (int i = 0; i < 4; i++) {
				tmp.push_back(s.top());
				s.pop();
			}

			if (tmp == "PAPP") {
				s.push('P');
				continue;
			}
			else {
				for (int i = 3; i >= 0; i--) {
					s.push(tmp[i]);
				}
				break;
			}
		}
	}

	if (s.size() == 1 && s.top() == 'P') {
		cout << "PPAP";
	}
	else {
		cout << "NP";
	}
}