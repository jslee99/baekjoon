#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool Mycompare(const string& str1, const string& str2) {
	if (str1.length() != str2.length()) {
		return str1.length() < str2.length();
	}
	else {
		if (str1.compare(str2) < 0) {
			return true;
		}
		else {
			return false;
		}
	}
}

int main(void) {
	int n;
	scanf("%d", &n);
	string* words = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> words[i];
	}
	sort(words, words + n,Mycompare);
	//Mycompare에서 두인자가 같을떄는 false를 출력해야함
	cout << words[0] << endl;
	for (int i = 1; i < n; i++) {
		if (words[i].compare(words[i - 1]) == 0) {
			continue;
		}
		else {
			cout << words[i] << endl;
		}
	}


	delete[] words;
}