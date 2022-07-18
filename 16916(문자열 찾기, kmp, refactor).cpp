#include<iostream>
#include<queue>
#include<stack>

using namespace std;
string S, P;
int P_i[1000000];
int ans = 0;

void getPi() {
	P_i[0] = 0;
	int p2 = 0;
	//p1은 기준 P의 index, p2는 비교 대상 P의 index
	for (int p1 = 1; p1 < P.size(); p1++) {
		if (P[p1] == P[p2]) {
			P_i[p1] = P_i[p1 - 1] + 1;
			p2++;
		}
		else {
			while (P[p1] != P[p2]) {
				if (p2 == 0)
					break;
				p2 = P_i[p2 - 1];
			}

			if (P[p1] == P[p2]) {//일치하는 접미, 접두사가 존재하는 경우이다.
				P_i[p1] = p2 + 1;
				p2++;
			}
			else {//p2의 index가 0이면서 일치하는 접미, 접두사가 없는 경우이다.
				P_i[p1] = 0;
			}
		}
		
	}
}

void kmp() {
	int p = 0;// P의 index
	for (int s = 0; s < S.size(); s++) {//S의 index
		if (S[s] == P[p]) {
			p++;
			if (p == P.size()) {
				ans = 1;
				break;
			}
		}
		else {
			while (S[s] != P[p]) {
				if (p == 0)
					break;
				p = P_i[p - 1];
			}

			if (S[s] == P[p]) {
				p++;
			}
			else {//p의 index가 0이면서 일치하는 접미, 접두사가 없는 경우이다.
				//p == 0
			}
		}
	}

}

int main(void) {
	cin >> S >> P;
	getPi();
	kmp();
	cout << ans << endl;
}