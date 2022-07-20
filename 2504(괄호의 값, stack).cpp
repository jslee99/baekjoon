#include<iostream>
#include<stack>
#include<vector>

using namespace std;
string str;
vector<int> v[30];
stack<char> s;
int ans = 0;
bool not_correct = false;
int main(void){
	cin >> str;
	//check


	for (int i = 0; i < (int)str.size(); i++) {
		if (str[i] == '(') {
			s.push('(');
		}
		else if (str[i] == '[') {
			s.push('[');
		}
		else if (str[i] == ')') {
			if (s.empty() || s.top() != '(') {
				not_correct = true;
				break;
			}
			else {
				s.pop();
			}
		}
		else if (str[i] == ']') {
			if (s.empty() || s.top() != '[') {
				not_correct = true;
				break;
			}
			else {
				s.pop();
			}
		}
	}

	if (not_correct) {
		cout << ans << endl;
		exit(0);
	}

	int depth = 0;
	for (int i = 0; i < (int)str.size(); i++) {
		if (str[i] == '(' || str[i] == '[') {
			depth++;
			if (str[i + 1] == ')' || str[i + 1] == ']') {
				v[depth].push_back(1);
			}
		}
		else {
			int res = 0;
			for (int j = 0; j < (int)v[depth].size(); j++) {
				res += v[depth][j];
			}

			if (str[i] == ')') {				
				res *= 2;
			}
			else {
				res *= 3;
			}

			v[depth].clear();
			depth--;
			v[depth].push_back(res);
		}
	}

	for (int i = 0; i < (int)v[0].size(); i++) {
		ans += v[0][i];
	}
	cout << ans << endl;
}