#include<iostream>
#include<string>
#include<cmath>

using namespace std;

string ans[50][5];

struct round_set {
	int first_round, second_round, third_round;
};

int calc_final_val(int first, int second, int third) {
	int start_val = pow(2 * (first - 1) + 1, 2) + 1;
	int final_val = start_val + second * (2 * first) + third;
	return final_val;
}

int calc_first_round(int r, int c) {
	return max(abs(r), abs(c));
}

int calc_second_round(int first_round, int r, int c) {
	if (first_round == c && r != c) {
		return 0;
	}
	else if (first_round == -r) {
		return 1;
	}
	else if (first_round == -c) {
		return 2;
	}
	else {
		return 3;
	}
}

int calc_third_round(int first_round, int second_round, int r, int c) {
	if (second_round == 0) {
		return first_round - 1 - r;
	}
	else if (second_round == 1) {
		return first_round - 1 - c;
	}
	else if (second_round == 2) {
		return r + (first_round - 1);
	}
	else {
		return c + (first_round - 1);
	}
}

string calc_val(int r, int c) {
	round_set s;
	s.first_round = calc_first_round(r, c);
	if (s.first_round == 0) return to_string(1);

	s.second_round = calc_second_round(s.first_round, r, c);//0 ~ 3

	s.third_round = calc_third_round(s.first_round, s.second_round, r, c);

	return to_string(calc_final_val(s.first_round, s.second_round, s.third_round));
}

int main(void) {
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	int max_len = 0;
	for (int i = 0; i + r1 <= r2; i++) {
		for (int j = 0; j + c1 <= c2; j++) {
			ans[i][j] = calc_val(r1 + i, c1 + j);
			max_len = max(max_len, (int)ans[i][j].length());
		}
	}

	for (int i = 0; i + r1 <= r2; i++) {
		for (int j = 0; j + c1 <= c2; j++) {
			int differ = max_len - (int)ans[i][j].length();
			while (differ--) {
				ans[i][j].insert(0, " ");
			}
		}
	}

	for (int i = 0; i + r1 <= r2; i++) {
		for (int j = 0; j + c1 <= c2; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}
