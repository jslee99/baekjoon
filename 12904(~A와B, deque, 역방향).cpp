#include<iostream>
#include<deque>

using namespace std;

string S, T;
deque<char> dq;
bool front = true;

int main(void){
	cin >> S >> T;
	for (int i = 0; i < (int)T.length(); i++) {
		dq.push_back(T[i]);
	}

	while ((int)dq.size() > (int)S.size()) {
		if (front) {
			if (dq.back() == 'B') {
				dq.pop_back();
				front = !front;
			}
			else {
				dq.pop_back();
			}
		}
		else {
			if (dq.front() == 'B') {
				dq.pop_front();
				front = !front;
			}
			else {
				dq.pop_front();
			}
		}
	}

	bool flag = true;
	if (front) {
		for (int i = 0; i < (int)dq.size(); i++) {
			if (dq[i] != S[i]) flag = false;
		}
	}
	else {
		for (int i = 0; i < (int)dq.size(); i++) {
			if (dq[(int)dq.size() - i - 1] != S[i]) flag = false;
		}
	}
	cout << (int)flag << endl;
}