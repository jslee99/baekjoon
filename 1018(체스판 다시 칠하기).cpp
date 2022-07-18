#include<iostream>
using namespace std;

int main(void) {
	int m, n;
	scanf("%d %d", &m, &n);
	int** board = new int* [m];
	for (int i = 0; i < m; i++) {
		board[i] = new int[n];
	}

	for (int i = 0; i < m; i++) {
		string colors;
		cin >> colors;
		for (int j = 0; j < n; j++) {
			if (colors[j] == 'W') {
				board[i][j] = 0;
			}
			else {
				board[i][j] = 1;
			}
		}
	}
	int min = 64;
	for (int i = 0; i <= m - 8; i++) {//start i,j
		for (int j = 0; j <= n - 8; j++) {
			int check = (i + j) % 2;
			int cnt = 0;
			for (int ro = i; ro < i + 8; ro++) { // black
				for (int co = j; co < j + 8; co++) {
					if ((ro + co) % 2 == check) {//should black
						if (board[ro][co] == 0) {
							cnt++;
						}
					}
					else {
						if (board[ro][co] == 1) {
							cnt++;
						}
					}
				}
			}
			if (cnt < min) {
				min = cnt;
			}
			cnt = 0;
			for (int ro = i; ro < i + 8; ro++) {
				for (int co = j; co < j + 8; co++) {
					if ((ro + co) % 2 == check) {
						if (board[ro][co] == 1) {
							cnt++;
						}
					}
					else {
						if (board[ro][co] == 0) {
							cnt++;
						}
					}
				}
			}
			if (cnt < min) {
				min = cnt;
			}
		}
	}
	
	printf("%d", min);




	for (int i = 0; i < m; i++) {
		delete[] board[i];
	}
	delete[] board;
}