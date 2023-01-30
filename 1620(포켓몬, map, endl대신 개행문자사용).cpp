#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

int N, M;
unordered_map<string, int> str_to_int;
//map<int, string> int_to_str;
string int_to_str[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		str_to_int.insert(make_pair(str, i));
		//int_to_str.insert(make_pair(i, str));
		int_to_str[i] = str;
	}

	while (M--) {
		string str;
		cin >> str;
		if (str[0] <= 'Z' && str[0] >= 'A') {
			cout << (*str_to_int.find(str)).second <<  '\n';
		}
		else {
			cout << int_to_str[stoi(str)] << '\n';
		}
	}
}