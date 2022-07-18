#include<iostream>
#include<vector>

using namespace std;

string S, P;
int Pi[1000000];//Pi[7] == 5 -> index가 7인 문자까지 봤을때 5글자의 접두, 접미사가 겹친다.
int ans = 0;

void getPi() {
	int i = 1, j = 0;
	Pi[0] = 0;
	while (i < P.size()) {
		if (P[i] == P[j]) {
			Pi[i] = Pi[i - 1] + 1;
			i++;
			j++;
		}
		else {
			j = Pi[i - 1];
			bool flag = true;
			while (P[i] != P[j]) {
				if (j == 0) {
					flag = false;
					break;
				}
				j = Pi[j - 1];
			}

			if (flag) {
				Pi[i] = j + 1;
				j++;
				i++;
			}
			else {
				Pi[i] = 0;
				i++;
				j = 0;
			}

		}
	}
}

void kmp() {
	int i = 0, j = 0;//각각 S, P의 index
	while (i < S.size()) {
		if (S[i] == P[j]) {
			i++;
			j++;
			if (j == P.size()) {
				ans = 1;
				break;
			}
		}
		else {
			if (j == 0) {
				i++;
				j = 0;
				continue;
			}
			j = Pi[j - 1];
			bool flag = true;
			while (S[i] != P[j]) {
				if (j == 0) {
					flag = false;
					break;
				}
				j = Pi[j - 1];
			}

			if (flag) {
				i++;
				j++;
			}
			else {
				i++;
				j = 0;
			}
		}
	}
}

int main(void) {
	cin >> S >> P;
	//Pi
	getPi();
	kmp();
	cout << ans << endl;
}
//https://bowbowbow.tistory.com/6