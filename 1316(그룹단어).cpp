#include<iostream>
#include<string>
using namespace std;

int main(void) {
	/*
	char ch = 'b';
	printf("%d", ch - 97);
	*/
	int n;
	scanf("%d", &n);
	int cnt = 0;
	bool* check = new bool[26];
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < 26; j++) {
			check[j] = false;
		}

		char ch = str[0];
		check[ch - 97] = true;
		for (int j = 1; j < str.length(); j++) {
			if (ch == str[j]) {
				continue;
			}
			else {
				if (check[str[j] - 97] == true) {
					cnt++;
					break;
				}
				else {
					check[str[j] - 97] = true;
					ch = str[j];
				}
			}
		}
	}
	printf("%d\n", n - cnt);


	delete[] check;
}