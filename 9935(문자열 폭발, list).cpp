#include<iostream>
#include<list>

using namespace std;
string str1, str2;
list<char> lst;

bool finding(list<char>::iterator iter) {
	bool flag = true;
	for (int j = 0; j < (int)str2.size(); j++) {
		if (*iter != str2[j]) {
			flag = false;
			break;
		}
		iter++;
	}
	return flag;
}

list<char>::iterator removing(list<char>::iterator iter) {
	for (int j = 0; j < (int)str2.size(); j++) {
		iter = lst.erase(iter);
	}
	return iter;
}

void solve() {
	int i = 0;
	list<char>::iterator iter = lst.begin();
	while (!((int)lst.size() - (int)str2.size() < i)) {
		if (finding(iter)) {
			iter = removing(iter);
			for (int j = 0; j < (int)str2.size() - 1; j++) {
				if (iter == lst.begin()) break;
				i--, iter--;
			}
		}
		else {
			i++, iter++;
		}
	}
}

int main(void) {
	cin >> str1 >> str2;
	for (int i = 0; i < (int)str1.size(); i++) {
		lst.push_back(str1[i]);
	}

	solve();

	
	if ((int)lst.size() == 0) {
		cout << "FRULA" << endl;
	}
	else {
		list<char>::iterator iter;
		for (iter = lst.begin(); iter != lst.end(); iter++) {
			cout << *iter;
		}
	}
}

//str2�� �ִ���̰� 35�̱� ������ finding�Լ��� naive�ϰ� �����ϰ� ���� �� �� �־���. kmp����� �ʿ� x
//iter�� i(index)�� ��� ����Ͽ���.