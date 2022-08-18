#include<iostream>
#include<list>

using namespace std;
string str;
int M;
list<char> txt;
char command;
char ch;

int main(void) {
	cin >> str;

	for (int i = 0; i < (int)str.length(); i++) {
		txt.push_back(str[i]);
	}

	list<char>::iterator iter = txt.end();

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> command;
		if (command == 'P') {
			cin >> ch;
			txt.insert(iter, ch);
		}
		else if (command == 'L') {
			if (iter != txt.begin()) iter--;
		}
		else if (command == 'D') {
			if (iter != txt.end()) iter++;
		}
		else if (command == 'B') {
			if (iter != txt.begin()) {
				iter--;
				iter = txt.erase(iter);
			}
		}

	}

	iter = txt.begin();
	for (iter; iter != txt.end(); iter++) {
		cout << *iter;
	}
}

//iterator : https://leemoney93.tistory.com/66
//list : https://blockdmask.tistory.com/76