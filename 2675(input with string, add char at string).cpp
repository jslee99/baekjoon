#include<iostream>
#include<string>
using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	int* R = new int[n];
	string* str = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> R[i] >> str[i]; // input with string , split with white space at input data
	}
	for (int i = 0; i < n; i++) { // each test case
		string temp = "";
		for (int j = 0; j < str[i].size(); j++) { // at each char of string
			for (int k = 0; k < R[i]; k++) {
				temp += str[i][j]; // string += char -> append one char at string
			}
		}
		str[i] = temp;
	}
	for (int i = 0; i < n; i++) {
		cout << str[i] << endl;
	}
	return 0;
}