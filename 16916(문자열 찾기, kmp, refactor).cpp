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
	//p1�� ���� P�� index, p2�� �� ��� P�� index
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

			if (P[p1] == P[p2]) {//��ġ�ϴ� ����, ���λ簡 �����ϴ� ����̴�.
				P_i[p1] = p2 + 1;
				p2++;
			}
			else {//p2�� index�� 0�̸鼭 ��ġ�ϴ� ����, ���λ簡 ���� ����̴�.
				P_i[p1] = 0;
			}
		}
		
	}
}

void kmp() {
	int p = 0;// P�� index
	for (int s = 0; s < S.size(); s++) {//S�� index
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
			else {//p�� index�� 0�̸鼭 ��ġ�ϴ� ����, ���λ簡 ���� ����̴�.
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