#include<iostream>

using namespace std;

bool can_state[201][201][201];
int _max[3];
bool ans[201];

bool is_visited(int arg_state[3]) {
	return can_state[arg_state[0]][arg_state[1]][arg_state[2]];
}

void dfs(int cur_state[3]) {
	can_state[cur_state[0]][cur_state[1]][cur_state[2]] = true;
//	ans[cur_state[2]] = true;
	if (cur_state[0] == 0)
		ans[cur_state[2]] = true;

	for (int from = 0; from < 3; from++) {
		if (cur_state[from] == 0)
			continue;

		for (int j = 1; j < 3; j++) {
			int to = (from + j) % 3;
			if (cur_state[to] == _max[to])
				continue;

			int next_state[3];
			//to를 가득 채우거나 from를 다 비우거나
			if (cur_state[from] < _max[to] - cur_state[to]) {//from을 비운다
				next_state[from] = 0;
				next_state[to] = cur_state[from] + cur_state[to];
				next_state[3 - from - to] = cur_state[3 - from - to];
				if (!is_visited(next_state))
					dfs(next_state);
			}
			else {//to를 채운다 from에는 남는다.
				next_state[to] = _max[to];
				next_state[from] = cur_state[from] - (_max[to] - cur_state[to]);
				next_state[3 - from - to] = cur_state[3 - from - to];
				if (!is_visited(next_state))
					dfs(next_state);
			}
		}
	}
}

int main(void) {
	cin >> _max[0] >> _max[1] >> _max[2];
	int cur_state[3] = { 0, 0, _max[2] };
	dfs(cur_state);

	for (int i = 0; i <= _max[2]; i++)
		if (ans[i])
			cout << i << ' ';
}