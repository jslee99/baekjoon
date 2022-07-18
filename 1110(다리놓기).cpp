#include<iostream>
using namespace std;
/*
int dp(int n, int m) {
	if (n == m) {
		return 1;
	}
	else if (n == 1) {
		return m;
	}
	else {
		return dp(n, m - 1) + dp(n - 1, m - 1);
	}
}
*/
/*
double dp2(int n, int m) {
	if (n == m) {
		return 1;
	}
	else if (n == 1) {
		return m;
	}
	else {
		return dp2(n - 1, m - 1) + dp2(n , m - 1);
	}
}

int main(void) {
	int c, n, m;
	scanf("%d", &c);
	for (int i = 0; i < c; i++) {
		scanf("%d %d", &n, &m);
		printf("%.1f\n", dp2(n, m));
	}
}*/

int dp(int** com,int m, int n) {
	if (com[m][n] != -1) {
		return com[m][n];
	}

	if (m == n) {
		com[m][n] = 1;
		return com[m][n];
	}
	else if(n == 1){
		com[m][n] = m;
		return com[m][n];
	}
	else {
		com[m][n] = dp(com, m - 1 , n) + dp(com, m - 1, n - 1);
		return com[m][n];
	}
}

int main(void) {
	int** com = new int* [31];
	for (int i = 0; i < 31; i++) {
		com[i] = new int[31];
	}
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			com[i][j] = -1;
		}
	}
	int t, n, m;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &n, &m);
		printf("%d\n", dp(com, m, n));
	}
	for (int i = 0; i < 31; i++) {
		delete[] com[i];
	}
	delete[] com;
}