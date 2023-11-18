#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

int n, m;
int dp[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	map<string, string> mm;

	cin >> n >> m;

	while (n--) {
		string site, pwd;
		cin >> site;
		cin >> pwd;
		mm.insert(make_pair(site, pwd));
	}

	while (m--) {
		string site;
		cin >> site;
		map<string, string>::iterator it = mm.find(site);
		cout << (*it).second << '\n';
	}

}