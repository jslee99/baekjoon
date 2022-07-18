#include<iostream>
#include<string>
using namespace std;

int main(void) {
	int n;
	scanf("%d", &n); 
	string* strs = new string[n];
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		strs[i] = str;
	}
	string str = "";
	for (int i = 0; i < strs[0].length(); i++) {
		char ch = strs[0][i];
		int cnt = 1;//cnt  1~ n
		for (int j = 1; j < n; j++) {
			if (ch == strs[j][i]) {
				cnt++;
			}
			else {
				break;
			}
		}
		if (cnt < n) {
			str += '?';
		}
		else {
			str += ch;
		}
	}
	cout << str;
}