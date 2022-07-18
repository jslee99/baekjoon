#include<iostream>
#include<string>
#include<bitset>
using namespace std;
/*
class Set {
private:
	bool* lst;
public:
	Set() {
		lst = new bool[21];
		for (int i = 0; i < 21; i++) {
			lst[i] = false;
		}
	}
	~Set() {
		delete[] lst;
	}
	void add(int x) {
		this->lst[x] = true;
	}
	void remove(int x) {
		this->lst[x] = false;
	}
	int check(int x) {
		if (this->lst[x] == true) {
			return 1;
		}
		else {
			return 0;
		}
	}
	void toggle(int x) {
		if (this->lst[x] == true) {
			this->lst[x] = false;
		}
		else {
			this->lst[x] = true;
		}
	}
	void all() {
		for (int i = 1; i < 21; i++) {
			this->lst[i] = true;
		}
	}
	void empty() {
		for (int i = 1; i < 21; i++) {
			this->lst[i] = false;
		}
	}
};

int main(void) {
	Set* S = new Set();
	int t;
	scanf("%d", &t);
	string str;
	int x;
	for (int i = 0; i < t; i++) {
		cin >> str;
		if (str == "add") {
			cin >> x;
			S->add(x);
		}
		else if(str == "remove"){
			cin >> x;
			S->remove(x);
		}
		else if(str == "check"){
			cin >> x;
			printf("%d\n", S->check(x));
		}
		else if (str == "toggle") {
			cin >> x;
			S->toggle(x);
		}
		else if(str == "all"){
			S->all();
		}
		else {
			S->empty();
		}
	}



	delete S;
}*/

//cin:입력 받을떄 공백과 띄어쓰기에서 끊는다.(무시한다)

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int bit = 0;
	int t;
	cin >> t;
	char str[10];
	int x;
	int temp = 0;
	for (int i = 0; i < 20; i++) {
		temp = temp | (1 << i);
	}
	while(t--) {
		cin >> str;
		if (str[1] == 'd') {
			cin >> x;
			bit = bit | (1 << x - 1);
		}
		else if (str[0] == 'r') {
			cin >> x;
			bit = bit & ~(1 << x - 1);
		}
		else if (str[0] == 'c') {
			cin >> x;
			int check = bit >> x - 1;
			if (check % 2 == 1) {
				printf("%d\n", 1);
			}
			else {
				printf("%d\n", 0);
			}
		}
		else if (str[0] == 't') {
			cin >> x;
			bit = bit ^ (1 << x - 1);
		}
		else if (str[1] == 'l') {
			bit = bit | temp;
		}
		else {
			bit = 0;
		}
	}
}