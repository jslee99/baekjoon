#include<iostream>

using namespace std;

int R, C, T;
int r1, c1;
int map[250][250];
int diffusion_map[250][250];
int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { -1, 0, 1, 0 };
int ans = 0;

bool can_diffusion(int i, int j) {
	return i >= 0 && i < R&& j >= 0 && j < C&& map[i][j] != -1;
}


void diffusion() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] > 0) {
				diffusion_map[i][j] = map[i][j] / 5;
				map[i][j] -= 4 * diffusion_map[i][j];
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (diffusion_map[i][j] > 0) {
				int combo = 0;
				for (int k = 0; k < 4; k++) {
					int new_r = i + dr[k], new_c = j + dc[k];
					if (can_diffusion(new_r, new_c)) {
						map[new_r][new_c] += diffusion_map[i][j];
						combo++;
					}
				}
				map[i][j] += diffusion_map[i][j] * (4 - combo);
				diffusion_map[i][j] = 0;
			}
		}
	}
}

bool is_in(int r, int c) {
	return c < C && r >= 0&& c >= 0;
}

bool is_in_anti(int r, int c) {
	return c < C&& r < R&& c >= 0;
}

void clock_circulation(int r, int c, int dir, int before_dust) {
	if (map[r][c] != -1) {
		int my_dust = map[r][c];
		map[r][c] = before_dust;

		if (!is_in(r + dr[dir], c + dc[dir])) {
			dir--;
			if (dir < 0) dir = 3;
		}

		clock_circulation(r + dr[dir], c + dc[dir], dir, my_dust);
	}
	else {
		return;
	}
}

void anti_clock_circulation(int r, int c, int dir, int before_dust) {
	if (map[r][c] != -1) {
		int my_dust = map[r][c];
		map[r][c] = before_dust;

		if (!is_in_anti(r + dr[dir], c + dc[dir])) {
			dir++;
			if (dir > 3) dir = 0;
		}

		anti_clock_circulation(r + dr[dir], c + dc[dir], dir, my_dust);
	}
	else {
		return;
	}
}

void circulation() {
	//clock circulation
	clock_circulation(r1 - 1, c1 + 1, 2, 0);

	//anti clock circulation
	anti_clock_circulation(r1, c1 + 1, 2, 0);
}

int main(void){
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) 
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) 
				r1 = i, c1 = j;
		}
	
	for (int t = 0; t < T; t++) {
		diffusion();
		circulation();
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == -1)continue;
			ans += map[i][j];
		}
	}

	cout << ans << endl;
}


//À½¼ö¾Æ ³ª´°¼À/³ª¸ÓÁö https://jeonggyun.tistory.com/228