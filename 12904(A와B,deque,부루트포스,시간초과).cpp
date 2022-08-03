#include<iostream>
#include<deque>

using namespace std;

string S, T;
bool front = true;
deque<char> dq;

void solve() {

	if (dq.size() == T.size()) {
		bool flag = true;
		if (front) {
			for (int i = 0; i < (int)dq.size(); i++) {
				if (dq[i] != T[i]) {
					flag = false;
					break;
				}
			}
		}
		else {
			for (int i = 0; i < (int)dq.size(); i++) {
				if (dq[dq.size() - i - 1] != T[i]) {
					flag = false;
					break;
				}
			}
		}
		if (flag) {
			cout << 1 << endl;
			exit(0);
		}
		return;
	}

	if (front) {
		dq.push_back('A');
		solve();
		dq.pop_back();
	}
	else {
		dq.push_front('A');
		solve();
		dq.pop_front();
	}

	if (front) {
		front = !front;
		dq.push_front('B');
		solve();
		front = !front;
		dq.pop_front();
	}
	else {
		front = !front;
		dq.push_back('B');
		solve();
		front = !front;
		dq.pop_back();
	}
}

int main(void){
	cin >> S >> T;
	for (int i = 0; i < (int)S.length(); i++) {
		dq.push_back(S[i]);
	}
	solve();
	cout << 0 << endl;
}