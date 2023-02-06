#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int N;
int N_3;
int K;
vector<string> star_map;

void draw_star(int r1, int c1, int r2, int c2) {
	if (r2 - r1 + 1 == 3) {//base
		star_map[r1][(c1 + c2) / 2] = '*';
		star_map[r1 + 1][c1 + 1] = '*', star_map[r1 + 1][c2 - 1] = '*';
		for (int j = c1; j <= c2; j++) {
			star_map[r1 + 2][j] = '*';
		}
	}
	else {
		int half_r = (r1 + r2) / 2; //11 -> 11, 11 + 1
		int half_c = (c1 + c2) / 2; // 23 -> 23 - 1, 23 + 1
		int quad_c1 = (c1 + half_c - 1) / 2; // 11 -> 11 - 1, 11 + 1
		int quad_c2 = (half_c + 1 + c2) / 2;

		draw_star(r1, quad_c1 + 1, half_r, quad_c2 - 1);
		draw_star(half_r + 1, c1, r2, half_c - 1);
		draw_star(half_r + 1, half_c + 1, r2, c2);
	}
}

int main(void) {
	cin >> N; // 3 * 2 ^ k
	N_3 = N / 3;
	K = (int)log2((double)N_3);
	for (int i = 0; i < N; i++) {//frame¸¸µé±â
		string str;
		for (int j = 0; j < N_3; j++) {
			str += "      ";
		}
		str.erase(str.end() - 1);
		star_map.push_back(str);
	}

	draw_star(0, 0, N - 1, 6 * N_3 - 2);

	for (int i = 0; i < N; i++) {
		cout << star_map[i] << '\n';
	}

	return 0;
}