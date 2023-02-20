#include<iostream>
#include<queue>
#include<climits>

using namespace std;
int N, K;
int s = 0, e = 100000;
int visited[100001];
vector<int> previous_node_v[100001];
queue<int> q;
long long num_of_ways[100001];

long long ways(int k) {
	if (num_of_ways[k] != 0) {
		return num_of_ways[k];
	}

	if (previous_node_v[k].size() == 0) {
		num_of_ways[k] = 1;
		return num_of_ways[k];
	}

	for (int i = 0; i < (int)previous_node_v[k].size(); i++) {
		num_of_ways[k] += ways(previous_node_v[k][i]);
	}
	return num_of_ways[k];
}

bool is_in(int k) {
	return k >= 0 && k <= e;
}

int main() {
	cin >> N >> K;

	for (int i = s; i <= e; i++) visited[i] = -1;

	visited[N] = 0;
	q.push(N);
	
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		int y;

		y = x + 1;
		if (is_in(y)) {
			if (visited[y] == -1) {
				visited[y] = visited[x] + 1;
				q.push(y);
				previous_node_v[y].push_back(x);
			}
			else if (visited[y] == visited[x] + 1) {
				previous_node_v[y].push_back(x);
			}
		}

		y = x - 1;
		if (is_in(y)) {
			if (visited[y] == -1) {
				visited[y] = visited[x] + 1;
				q.push(y);
				previous_node_v[y].push_back(x);
			}
			else if (visited[y] == visited[x] + 1) {
				previous_node_v[y].push_back(x);
			}
		}

		y = 2 * x;
		if (is_in(y)) {
			if (visited[y] == -1) {
				visited[y] = visited[x] + 1;
				q.push(y);
				previous_node_v[y].push_back(x);
			}
			else if (visited[y] == visited[x] + 1) {
				previous_node_v[y].push_back(x);
			}
		}
	}

	cout << visited[K] << endl;
	cout << ways(K) << endl;


	return 0;
}