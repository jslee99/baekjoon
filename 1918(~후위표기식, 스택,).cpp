#include<iostream>
#include<stack>

using namespace std;
string str;
string ans;

int main(void){
	cin >> str;
	str.insert(0, "(");
	str.push_back(')');
	stack<char> s;

	//G*(A-B*(C/D+E)/F)  GABCD/E+*F/-*
	for (int i = 0; i < (int)str.size(); i++) {
		switch (str[i]) {
		case '(': {
			s.push(str[i]);
			break;
		}
		case ')': {// 닫힌 괄호는 그전에 스택에 있는 ( 전까지의 모든 연산에 우선순위가 있으므로 처리한다.
			while (s.top() != '(') {
				ans.push_back(s.top());
				s.pop();
			}
			s.pop();

			break;
		}
		case '*': 
		case '/': {// 이전까지 있던 *, /에 우선순위가 있으므로 이것들을 처리해준다.
			while (s.top() == '*' || s.top() == '/') {
				ans.push_back(s.top());
				s.pop();
			}

			s.push(str[i]);
			break;
		}
		case '+':
		case '-': {// 이전까지 있던 모든 연산에 우선순위가 생기므로 이것들을 처리해준다.
			while (s.top() != '(') {
				ans.push_back(s.top());
				s.pop();
			}

			s.push(str[i]);
			break;
		}
		default: {//when alpahbet
			ans.push_back(str[i]);
			break;
		}
		}
	}

	cout << ans << endl;
}
