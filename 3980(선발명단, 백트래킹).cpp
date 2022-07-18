#include<iostream>

using namespace std;

int T;
int member_status[11][11];
int member_used[11];
int who_at_postion[11];
int max_status_sum;

void back_track(int determined_position) {
	if (determined_position < 11) {
		for (int i = 0; i < 11; i++) {
			if (member_status[i][determined_position] != 0 && member_used[i] == 0) {
				member_used[i] = 1;
				who_at_postion[determined_position] = i;
				back_track(determined_position + 1);
				member_used[i] = 0;
				who_at_postion[determined_position] = -1;
			}
		}
	}
	else {//sum all status
		int status_sum = 0;
		for (int i = 0; i < 11; i++) {
			status_sum += member_status[who_at_postion[i]][i];
		}
		if (status_sum > max_status_sum) {
			max_status_sum = status_sum;
		}
	}
}




int main(void) {
	cin >> T;
	for (int t = 0; t < T; t++) {
		for (int i = 0; i < 11; i++) {
			cin >> member_status[i][0] >> member_status[i][1] >> member_status[i][2] >> member_status[i][3] >> member_status[i][4] >> member_status[i][5] >> member_status[i][6] >> member_status[i][7] >> member_status[i][8] >> member_status[i][9] >> member_status[i][10];
		}
		for (int i = 0; i < 11; i++) {
			member_used[i] = 0;
			who_at_postion[i] = -1;
		}
		max_status_sum = 0;

		back_track(0);
		cout << max_status_sum << endl;
	}
}
