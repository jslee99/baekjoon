#include<iostream>

using namespace std;

string S;
int N, M;
int _count = 0;

int main(void){
	cin >> N;
	cin >> M;
	cin >> S;

	int p = 0;
	bool finding = false;
	for (int s = 0; s < S.size(); s++) {
		if (finding) {
			if ((p % 2 == 1 && S[s] == 'O') || (p % 2 == 0 && S[s] == 'I')) {
				p++;
				if (p == 2 * N + 1) {
					_count++;
					p = 2 * N - 1;
				}
			}
			else {
				if (S[s] == 'O') {
					finding = false;
					p = 0;
				}
				else {// S[s] == 'I'
					//finding = true
					p = 1;//p = 0, p++
				}
			}
		}
		else {
			if (S[s] == 'I') {
				finding = true;
				p++;//p == 1
			}
		}
	}

	cout << _count << endl;
}