#include<stdio.h>

int a[50][50];
int m, n;
int r, c;
int d;
int dm[4] = { -1, 0, 1, 0 };
int dn[4] = { 0, 1, 0, -1 };

int main() {
	scanf("%d %d", &m, &n);
	scanf("%d %d %d", &r, &c, &d);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	a[r][c] = 2;
	while (!(a[r + 1][c] != 0 && a[r - 1][c] != 0 && a[r][c + 1] != 0 && a[r][c - 1] != 0 && a[r + dm[(d + 2) % 4]][c + dn[(d + 2) % 4]] == 1)) {
		int new_d;
		int i;
		for (i = 1; i <= 4; i++) {
			new_d = (d + 4 - i) % 4;
			if (a[r + dm[new_d]][c + dn[new_d]] == 0) {
				r = r + dm[new_d], c = c + dn[new_d];
				a[r][c] = 2;
				d = new_d;
				break;
			}
		}
		if (i < 5) {
			continue;
		}
		r = r + dm[(d + 2) % 4], c = c + dn[(d + 2) % 4];
	}
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 2) {
				cnt++;
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}

