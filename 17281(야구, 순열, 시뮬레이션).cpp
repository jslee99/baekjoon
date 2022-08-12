#include<iostream>
#include<vector>

using namespace std;
int sequence[9];
int player[9][50];//[i][j] player iÀÇ j¹øÂ° ÀÌ´×
bool visited[9];
int N;
int ans = 0;

void simulation() {
	int score = 0;
	int seq_idx = 0;
	for (int i = 0; i < N; i++) {//i : inning
		int out_cnt = 0;
		bool base[3];
		for (int i = 0; i < 3; i++) {
			base[i] = false;
		}
		while (out_cnt < 3) {
			int hit = player[sequence[seq_idx]][i];
			if (!hit) {
				out_cnt++;
			}
			else {
				for (int b = 2; b >= 0; b--) {
					if (base[b]) {
						if (b + hit > 2) {
							score++;
							base[b] = false;
						}
						else {
							base[b + hit] = true;
							base[b] = false;
						}
					}
				}

				if (hit == 4) {
					score++;
				}
				else {
					base[hit - 1] = true;
				}
			}

			seq_idx = (seq_idx + 1) % 9;
		}
	}

	ans = max(ans, score);
}

void make_sequence(vector<int> remain_player) {
	if ((int)remain_player.size() == 0) {
		simulation();
	}
	else {
		int size = (int)remain_player.size();
		for (int i = 0; i < size; i++) {
			int player_num = remain_player[i];
			sequence[9 - size] = player_num;
			remain_player.erase(remain_player.begin() + i);
			make_sequence(remain_player);
			remain_player.emplace(remain_player.begin() + i, player_num);
		}
	}
}

void make_sequence2(int cnt) {
	if (cnt == 9) {
		simulation();
		return;
	}

	if (cnt == 3) {
		sequence[cnt] = 0;
		visited[0] = true;
		make_sequence2(cnt + 1);
		visited[0] = false;
	}
	else {
		for (int i = 1; i < 9; i++) {
			if (visited[i]) continue;
			sequence[cnt] = i;
			visited[i] = true;
			make_sequence2(cnt + 1);
			visited[i] = false;
		}
	}
}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> player[j][i];
		}
	}

	vector<int> v;
	for (int i = 0; i < 9; i++) {
		v.push_back(i);
	}

	make_sequence2(0);
	cout << ans << endl;
}
