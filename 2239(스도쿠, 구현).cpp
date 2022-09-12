#include<iostream>

using namespace std;

int sdk[9][9];

bool row_check(int r, int c, int num) {
	bool flag = true;
	for (int j = 0; j < 9; j++) {
		if (sdk[r][j] == num) {
			flag = false;
			break;
		}
	}
	return flag;
}

bool col_check(int r, int c, int num) {
	bool flag = true;
	for (int i = 0; i < 9; i++) {
		if (sdk[i][c] == num) {
			flag = false;
			break;
		}
	}
	return flag;
}

bool rec_check(int r, int c, int num) {
	bool flag = true;
	r = (r / 3) * 3, c = (c / 3) * 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (sdk[r + i][c + j] == num) {
				flag = false;
				break;
			}
		}
	}
	return flag;
}

bool check(int r, int c, int num) {
	return row_check(r, c, num) && col_check(r, c, num) && rec_check(r, c, num);
}

void print_sdk() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << sdk[i][j];
		}
		cout << endl;
	}
	exit(0);
}

void solve(int r, int c) {
	if (r == 9 && c == 0) print_sdk();

	int new_r = r;
	int new_c = (c + 1) % 9;
	if (new_c == 0) new_r++;

	if (sdk[r][c] == 0) {
		for (int i = 1; i <= 9; i++) {
			if (check(r, c, i)) {
				sdk[r][c] = i;
				solve(new_r, new_c);	
			}
		}
		sdk[r][c] = 0;
	}
	else {
		solve(new_r, new_c);
	}
}

int main(void) {
	for (int i = 0; i < 9; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < 9; j++) {
			sdk[i][j] = (int)(str[j] - '0');
		}
	}

	solve(0, 0);
}