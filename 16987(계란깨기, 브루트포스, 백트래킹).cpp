#include<iostream>

using namespace std;

int egg_state[8][2];
int n;
int max_broken_num = 0;

void recur(int before_egg_state[][2], int cur_egg_position, int before_broken_num) {
	if (cur_egg_position == n - 1) {
		if (before_broken_num > max_broken_num) {
			max_broken_num = before_broken_num;
		}
		if (before_egg_state[cur_egg_position][0] <= 0) {
			return;
		}
		else {
			for (int i = 0; i < n; i++) {
				int cur_egg_state[8][2];
				for (int i = 0; i < n; i++) {
					cur_egg_state[i][0] = before_egg_state[i][0];
					cur_egg_state[i][1] = before_egg_state[i][1];
				}
				if (cur_egg_position == i || cur_egg_state[i][0] <= 0) {
					continue;
				}
				int broken_num = before_broken_num;
				cur_egg_state[i][0] -= cur_egg_state[cur_egg_position][1];
				if (cur_egg_state[i][0] <= 0) {
					broken_num++;
				}
				cur_egg_state[cur_egg_position][0] -= cur_egg_state[i][1];
				if (cur_egg_state[cur_egg_position][0] <= 0) {
					broken_num++;
				}
				if (broken_num > max_broken_num) {
					max_broken_num = broken_num;
				}
			}
		}
	}
	else {
		if (before_egg_state[cur_egg_position][0] <= 0) {
			recur(before_egg_state, cur_egg_position + 1, before_broken_num);
		}
		else {
			int is_all_broken = 1;
			for (int i = 0; i < n; i++) {
				if (i != cur_egg_position && before_egg_state[i][0] > 0) {
					is_all_broken = 0;
				}
			}
			if (is_all_broken == 1) {
				if (before_broken_num > max_broken_num) {
					max_broken_num = before_broken_num;
				}
				return;
			}

			for (int i = 0; i < n; i++) {
				int cur_egg_state[8][2];
				for (int i = 0; i < n; i++) {
					cur_egg_state[i][0] = before_egg_state[i][0];
					cur_egg_state[i][1] = before_egg_state[i][1];
				}
				if (cur_egg_position == i || cur_egg_state[i][0] <= 0) {
					continue;
				}
				int broken_num = before_broken_num;
				cur_egg_state[i][0] -= cur_egg_state[cur_egg_position][1];
				if (cur_egg_state[i][0] <= 0) {
					broken_num++;
				}
				cur_egg_state[cur_egg_position][0] -= cur_egg_state[i][1];
				if (cur_egg_state[cur_egg_position][0] <= 0) {
					broken_num++;
				}
				recur(cur_egg_state, cur_egg_position + 1, broken_num);
			}
		}
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> egg_state[i][0] >> egg_state[i][1];
	}

	recur(egg_state, 0, 0);

	cout << max_broken_num;
}