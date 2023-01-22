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
		case ')': {// ���� ��ȣ�� ������ ���ÿ� �ִ� ( �������� ��� ���꿡 �켱������ �����Ƿ� ó���Ѵ�.
			while (s.top() != '(') {
				ans.push_back(s.top());
				s.pop();
			}
			s.pop();

			break;
		}
		case '*': 
		case '/': {// �������� �ִ� *, /�� �켱������ �����Ƿ� �̰͵��� ó�����ش�.
			while (s.top() == '*' || s.top() == '/') {
				ans.push_back(s.top());
				s.pop();
			}

			s.push(str[i]);
			break;
		}
		case '+':
		case '-': {// �������� �ִ� ��� ���꿡 �켱������ ����Ƿ� �̰͵��� ó�����ش�.
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
