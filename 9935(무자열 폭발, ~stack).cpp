#include<iostream>
#include<stack>

using namespace std;
string str1, str2;
stack<char> s;

void check_remove() {
	bool is_removing = true;
	int i;
	for (i = (int)str2.size() - 1; i >= 0; i--) {
		if (!s.empty() && s.top() == str2[i]) {
			s.pop();
		}
		else {
			is_removing = false;
			break;
		}
	}

	if (!is_removing) {
		for (i = i + 1; i < (int)str2.size(); i++) {
			s.push(str2[i]);
		}
	}
}

int main(){
	cin >> str1 >> str2;
	

	for (int i = 0; i < (int)str1.size(); i++) {
		s.push(str1[i]);
		check_remove();
	}

	string ans;
	while (!s.empty()) {
		ans.push_back(s.top());
		s.pop();
	}

	if ((int)ans.size() == 0) {
		cout << "FRULA" << endl;
	}
	else {
		for (int i = (int)ans.size() - 1; i >= 0; i--) cout << ans[i];
	}
}