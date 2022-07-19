#include<iostream>
#include<queue>
#include<string>

//거리가 1인 node(99,101, 한자리 숫자인 node) q에 저장하고 이 node들 모두에 대해 bfs(즉 거리가 1인 node에서 부터 +,-버튼을 통해 이동 될 수 있는 node(거리가 2)) 
//다시 거리가 2인 node(from 거리가 1인 node, 두자리 숫자인 node) queue에 저장하고 이에대해 bfs(즉 거리가 2인 node에서 부터 +,-버튼을 통해 이동 될 수 있는 node(거리가 3)) 
//반복.... 
//bfs를 모두 돌린후에 일반적인 bfs(bfs_2)를 다시 돌림

using namespace std;
bool cant[10];
vector<char> v;
int N;
int M;
int visited[1000000];
queue<int> q;

bool is_in(int a) {
	return a >= 0 && a < 1000000;
}

void bfs(int a) {
	while (!q.empty() && visited[q.front()] <= a) {
		int x = q.front();
		q.pop();
		if (is_in(x - 1) && visited[x - 1] == -1) {
			visited[x - 1] = visited[x] + 1;
			q.push(x - 1);
		}
		if (is_in(x + 1) && visited[x + 1] == -1) {
			visited[x + 1] = visited[x] + 1;
			q.push(x + 1);
		}
	}
}

void bfs_2() {
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (is_in(x - 1) && visited[x - 1] == -1) {
			visited[x - 1] = visited[x] + 1;
			q.push(x - 1);
		}
		if (is_in(x + 1) && visited[x + 1] == -1) {
			visited[x + 1] = visited[x] + 1;
			q.push(x + 1);
		}
	}
}

void back_track(int index, int depth, string s) {
	if (depth < index) {
		int a = stoi(s);
		if (is_in(a) && visited[a] == -1)  {
			q.push(a);
			visited[a] = 6 - index;
		}
	}
	else {
		string tmp = s;
		for (int i = 0; i < v.size(); i++) {
			tmp[depth] = v[i];
			back_track(index, depth - 1, tmp);
		}
	}
}

int main(void) {
	for (int i = 0; i < 1000000; i++) {
		visited[i] = -1;
	}

	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a1;
		cin >> a1;
		cant[a1] = true;
	}
	for (int i = 0; i < 10; i++) {
		if (!cant[i])
			v.push_back(i + 48);
	}




	visited[100] = 0;
	visited[99] = 1;
	visited[101] = 1;
	q.push(99);
	q.push(101);

	for (int i = 5; i >= 0; i--) {
		string s = "      ";
		back_track(i, 5, s);
		bfs(6 - i);
	}

	bfs_2();

	cout << visited[N] <<endl;
}