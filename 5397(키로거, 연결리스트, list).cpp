#include<iostream>
#include<list>

using namespace std;
int T;

int main(void) {
	cin >> T;
	while (T--) {
		string log;
		cin >> log;
		list<char> pwd;
		list<char>::iterator iter;
		iter = pwd.begin();
		for (int i = 0; i < (int)log.size(); i++) {
			if (log[i] == '<') {
				if (pwd.size() == 0) continue;

				if (iter != pwd.begin()) iter--;
			}
			else if (log[i] == '>') {
				if (pwd.size() == 0) continue;

				if (iter != pwd.end()) iter++;
			}
			else if (log[i] == '-') {
				if (pwd.size() == 0) continue;

				if (iter == pwd.begin()) continue;

				iter--;
				iter = pwd.erase(iter);
			}
			else {
				iter = pwd.insert(iter, log[i]);
				iter++;
			}
		}

		iter = pwd.begin();
		for (iter; iter != pwd.end(); iter++) {
			cout << *iter;
		}
		cout << endl;
	}
}
