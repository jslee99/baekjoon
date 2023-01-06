#include<iostream>

using namespace std;

string str;
int depth = 0;
int cnt = 0;

int main(void) {

	cin >> str;

	for (int i = 0; i < (int)str.size(); i++) {
		if (i < (int)str.size() - 1 && str[i] == '(' && str[i + 1] == ')') cnt += depth, i++;
		else if (str[i] == '(') depth++;
		else if (str[i] == ')') cnt++, depth--;
	}

	cout << cnt << endl;

	return 0;
}