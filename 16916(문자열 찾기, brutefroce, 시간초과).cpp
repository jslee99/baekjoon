#include<iostream>
#include<vector>

using namespace std;

string S, P;
int a[1000000];


int main(void) {
	cin >> S >> P;
	int flag = 0;
	for (int start = 0; start < S.size(); start++) {
		for (int j = 0; j < P.size(); j++) {
			if (S[start + j] == P[j]) {
				if (j == P.size() - 1) {
					flag = 1;
				}
			}
			else {
				break;
			}
		}
	}
	cout << flag << endl;
}