#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

int t;
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n;
		map<string, int> m;
		while (n--) {
			string name;
			cin >> name;
			string type;
			cin >> type;
			if (m.find(type) == m.end()) {
				m.insert(make_pair(type, 1));
			}
			else {
				map<string, int>::iterator it = m.find(type);
				(*it).second++;
			}
		}

		map<string, int>::iterator it = m.begin();
		int ans = 1;
		for (it; it != m.end(); it++) {
			ans *= (*it).second + 1;
		}
		cout << ans - 1 << '\n';
	}
}