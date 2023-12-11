#include <iostream>

using namespace std;

class t {
public:
	int a[8];
	int l;
	int r;
};
int n, k;
t ls[1005];

int mi(int x) {
	x--;
	if (x < 0) x = 7;
	return x;
}

int pl(int x) {
	x++;
	if (x > 7) x = 0;
	return x;
}

int convert(int b) {
	if (b == 1) return -1;
	else return 1;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < 8; j++) {
			if (j == 0) {
				ls[i].a[0] = str[j] - '0';
			}
			else {
				ls[i].a[7 - j + 1] = str[j] - '0';
			}
			
		}
		ls[i].l = 2;
		ls[i].r = 6;
	}

	cin >> k;
	while (k--) {
		int a, b;
		cin >> a >> b;
		if (b == 1) {//시계방향
			ls[a].l = pl(ls[a].l);
			ls[a].r = pl(ls[a].r);

			//left
			int dir = b;
			for (int i = a - 1; i > 0; i--) {
				int prev_left_g;
				if (dir == 1) {
					prev_left_g = ls[i + 1].a[mi(ls[i + 1].l)];
				}
				else {
					prev_left_g = ls[i + 1].a[pl(ls[i + 1].l)];
				}
				if (ls[i].a[ls[i].r] == prev_left_g) break;

				dir = convert(dir);
				if (dir == 1) {
					ls[i].l = pl(ls[i].l);
					ls[i].r = pl(ls[i].r);
				}
				else {
					ls[i].l = mi(ls[i].l);
					ls[i].r = mi(ls[i].r);
				}

			}

			//right
			dir = b;
			for (int i = a + 1; i <= n; i++) {
				int prev_right_g;
				if (dir == 1) {
					prev_right_g = ls[i - 1].a[mi(ls[i - 1].r)];
				}
				else {
					prev_right_g = ls[i - 1].a[pl(ls[i - 1].r)];
				}
				if (ls[i].a[ls[i].l] == prev_right_g) break;

				dir = convert(dir);
				if (dir == 1) {
					ls[i].l = pl(ls[i].l);
					ls[i].r = pl(ls[i].r);
				}
				else {
					ls[i].l = mi(ls[i].l);
					ls[i].r = mi(ls[i].r);
				}

			}
		}
		else {
			ls[a].l = mi(ls[a].l);
			ls[a].r = mi(ls[a].r);

			//left
			int dir = b;
			for (int i = a - 1; i > 0; i--) {
				int prev_left_g;
				if (dir == 1) {
					prev_left_g = ls[i + 1].a[mi(ls[i + 1].l)];
				}
				else {
					prev_left_g = ls[i + 1].a[pl(ls[i + 1].l)];
				}
				if (ls[i].a[ls[i].r] == prev_left_g) break;

				dir = convert(dir);
				if (dir == 1) {
					ls[i].l = pl(ls[i].l);
					ls[i].r = pl(ls[i].r);
				}
				else {
					ls[i].l = mi(ls[i].l);
					ls[i].r = mi(ls[i].r);
				}

			}

			//right
			dir = b;
			for (int i = a + 1; i <= n; i++) {
				int prev_right_g;
				if (dir == 1) {
					prev_right_g = ls[i - 1].a[mi(ls[i - 1].r)];
				}
				else {
					prev_right_g = ls[i - 1].a[pl(ls[i - 1].r)];
				}
				if (ls[i].a[ls[i].l] == prev_right_g) break;

				dir = convert(dir);
				if (dir == 1) {
					ls[i].l = pl(ls[i].l);
					ls[i].r = pl(ls[i].r);
				}
				else {
					ls[i].l = mi(ls[i].l);
					ls[i].r = mi(ls[i].r);
				}

			}

		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int ll = ls[i].l;
		for (int j = 0; j < 2; j++) ll = mi(ll);
		if (ls[i].a[ll] == 1)ans++;
	}
	
	cout << ans << '\n';

	return 0;
}