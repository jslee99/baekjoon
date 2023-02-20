#include<iostream>

using namespace std;
int map[64][64];
int N;

pair<bool, bool> can_compress(int r0, int c0, int r1, int c1) {
	pair<bool, bool> x;
	x.first = true, x.second = true;
	for (int i = r0; i <= r1; i++) {
		for (int j = c0; j <= c1; j++) {
			if (map[i][j] == 1) x.first = false;
			if (map[i][j] == 0) x.second = false;
		}
	}
	return x;
}

string quad(int r0, int c0, int r1, int c1) {
	pair<bool, bool> can_0_1_compress = can_compress(r0, c0, r1, c1);

	if (can_0_1_compress.first == true) {
		return "0";
	}
	else if (can_0_1_compress.second == true) {
		return "1";
	}

	int half_r = (r0 + r1) / 2;
	int half_c = (c0 + c1) / 2;
	string ret_str = "(";
	ret_str += quad(r0, c0, half_r, half_c);
	ret_str += quad(r0, half_c + 1, half_r, c1);
	ret_str += quad(half_r + 1, c0, r1, half_c);
	ret_str += quad(half_r + 1, half_c + 1, r1, c1);
	ret_str += ")";
	return ret_str;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			map[i][j] = (int)(str[j] - '0');
		} 
	}

	cout << quad(0, 0, N - 1, N - 1) << endl;
}