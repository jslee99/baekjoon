#include<iostream>
#include<queue>

int ladder[100];// ladder[2] = 3 : from 2 to 3
int snake[100];
int board[100];
int N, M;

bool is_in_and_is_not_checked(int num) {
	return num < 100 && board[num] == -1;
}

int main(void) {
	for (int i = 0; i < 100; i++) {
		ladder[i] = -1;
		snake[i] = -1;
		board[i] = -1;
	}
	std::cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int a1, a2;
		std::cin >> a1 >> a2;
		ladder[a1 - 1] = a2 - 1;
	}
	for (int i = 0; i < M; i++) {
		int a1, a2;
		std::cin >> a1 >> a2;
		snake[a1 - 1] = a2 - 1;
	}

	std::queue<int> q;
	board[0] = 0;
	q.push(0);
	while (!q.empty()) {
		int cur_position = q.front();
		q.pop();
		for (int dice = 1; dice < 7; dice++) {
			int new_position;
			if (ladder[cur_position + dice] != -1) {
				new_position = ladder[cur_position + dice];
			}
			else if(snake[cur_position + dice] != -1){
				new_position = snake[cur_position + dice];
			}
			else {
				new_position = cur_position + dice;
			}

			if (is_in_and_is_not_checked(new_position)) {
				board[new_position] = board[cur_position] + 1;
				q.push(new_position);
			}
		}
	}
	std::cout << board[99] << std::endl;
}
