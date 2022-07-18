#include<iostream>
#include<queue>
#include<stack>

using namespace std;

int N;
pair<int, int> is_visited[1000001];//연산횟수, 이전 node number
queue<int> q;
stack<int> way;

int main(void) {
	cin >> N;
	for (int i = 0; i <= N; i++) {
		is_visited[i].first = -1;
		is_visited[i].second = -1;
	}

	is_visited[N].first = 0;
	is_visited[N].second = -2;
	q.push(N);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x % 3 == 0) {
			if (is_visited[x / 3].first == -1) {
				q.push(x / 3);
				is_visited[x / 3].first = is_visited[x].first + 1;
				is_visited[x / 3].second = x;
			}
		}

		if (x % 2 == 0) {
			if (is_visited[x / 2].first == -1) {
				q.push(x / 2);
				is_visited[x / 2].first = is_visited[x].first + 1;
				is_visited[x / 2].second = x;
			}
		}

		if (x != 0 && is_visited[x - 1].first == -1) {
			q.push(x - 1);
			is_visited[x - 1].first = is_visited[x].first + 1;
			is_visited[x - 1].second = x;
		}
	}
	
	int y = 1;
	way.push(y);
	while (is_visited[y].second != -2) {
		y = is_visited[y].second;
		way.push(y);
	}
	cout << is_visited[1].first << endl;
	while (!way.empty()) {
		cout << way.top() << " ";
		way.pop();
	}
}