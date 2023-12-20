#include<iostream>
#include<map>

using namespace std;
int n;
map<string, int> m;
bool visit[1005];

int ans = 0;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		m.insert(make_pair(str, i));
	}

	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		map<string, int>::iterator it = m.find(s);

		visit[it->second] = true;
		for (int j = 1; j < it->second; j++) {
			if (!visit[j]){
				ans++; 
				break;
			}
				
		}
	}

	cout << ans << '\n';
}