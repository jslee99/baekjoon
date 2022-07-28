#include<iostream>

using namespace std;
bool map1[50][50];
bool map2[50][50];
int N, M;
int cnt = 0;

void conversion(int x, int y) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			map1[x + i][y + j] = !map1[x + i][y + j];
		}
	}
}

int main(void){
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			map1[i][j] = (bool)(s[j] - '0');
		}
	}
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			map2[i][j] = (bool)(s[j] - '0');
		}
	}

	for (int i = 0; i < N; i++) {
		bool cant = false;

		for (int j = 0; j < M; j++) {
			if (i > N - 3 || j > M - 3) {
				if (map1[i][j] != map2[i][j]) {
					cnt = -1;
					cant = true;
					break;
				}
			}
			else {
				if (map1[i][j] != map2[i][j]) {
					conversion(i, j);
					cnt++;
				}
			}
		}

		if (cant) {
			break;
		}
	}

	cout << cnt << endl;
}