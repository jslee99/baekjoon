#include<iostream>

using namespace std;

int score[21][21];
bool is_team[21];
int N;
int min_dif = 99999999;

void calc() {
	int a_score = 0, b_score = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (is_team[i] == true && is_team[j] == true) {
				a_score += score[i][j];
			}
			else if (is_team[i] == false && is_team[j] == false) {
				b_score += score[i][j];
			}
		}
	}

	min_dif = min(min_dif, abs(a_score - b_score));
}

void combination(int depth, int max_depth, int before) {
	if (depth == max_depth) {
		calc();
	}

	if (before == N) return;

	for (int i = before + 1; i <= N; i++) {
		is_team[i] = true;
		combination(depth + 1, max_depth, i);
		is_team[i] = false;
	}


	return;
}



void reset_is_team() {
	for (int i = 1; i <= N; i++) is_team[i] = false;
}

int main(void) {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> score[i][j];
		}
	}

	for (int max = 1; max <= N / 2; max++) {
		reset_is_team();
		combination(0, max, 0);
	}

	cout << min_dif << endl;
}