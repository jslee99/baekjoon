#include<iostream>
#include<vector>

using namespace std;

int n, m, k;
int a[305][305];
int buf[305][305];

void rotation(const int r1, const int c1, const int r2, const int c2) {

	int num = (r2 - r1) * 2 + (c2 - c1) * 2;
	int rot_num = k % num;

	while (rot_num--) {
		for (int j = c1; j < c2; j++)
			buf[r1][j] = a[r1][j];
		for (int i = r1; i < r2; i++)
			buf[i][c2] = a[i][c2];
		for (int j = c2; j > c1; j--)
			buf[r2][j] = a[r2][j];
		for (int i = r2; i > r1; i--)
			buf[i][c1] = a[i][c1];

		for (int j = c1; j < c2; j++)
			a[r1][j] = buf[r1][j + 1];
		for (int i = r1; i < r2; i++)
			a[i][c2] = buf[i + 1][c2];
		for (int j = c2; j > c1; j--)
			a[r2][j] = buf[r2][j - 1];
		for (int i = r2; i > r1; i--)
			a[i][c1] = buf[i - 1][c1];
	}

}

int main() {
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	
	int r1 = 1, c1 = 1;
	int r2 = n, c2 = m;
	while (r1 < r2 && c1 < c2) {
		rotation(r1++, c1++, r2--, c2--);	
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
		



	return 0;
}