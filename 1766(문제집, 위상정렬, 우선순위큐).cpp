#include<iostream>
#include<queue>
#include<vector>

using namespace std;

/*
int post_num[32001];
int post = 1;
vector<int> map[32001];
int N, M;
vector<pair<int, int>> v;

bool cmp1(const int& a, const int& b) {
	return a > b;
}

void dfs(int x) {
	
	for (int i = 0; i < (int)map[x].size(); i++) {
		if (!post_num[map[x][i]]) {
			dfs(map[x][i]);
		}
	}
	post_num[x] = post++;
}

bool cmp2(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second > b.second;
}

int main() {
	cin >> N >> M;

	int a, b;
	while (M--) {
		cin >> a >> b;
		map[a].push_back(b);
	}

	for (int i = 1; i <= N; i++) {
		map[0].push_back(i);
	}

	for (int i = 0; i <= N; i++) {
		sort(map[i].begin(), map[i].end(), cmp1);
	}

	dfs(0);

	for (int i = 0; i <= N; i++) {
		v.push_back(make_pair(i, post_num[i]));
	}

	sort(v.begin(), v.end(), cmp2);

	for (int i = 1; i <= N; i++) {
		cout << v[i].first << ' ';
	}

	return 0;
}
*/
//https://www.acmicpc.net/board/view/33139

struct data {
	int prev;
	int num;
};

struct cmp {
	bool operator() (const struct data& a, const struct data& b) {
		if (a.prev > b.prev) {
			return true;
		}
		else if (a.prev < b.prev) {
			return false;
		}
		else {
			if (a.num > b.num) {
				return true;
			}
			else {
				return false;
			}
		}
	}
};

struct cmp2 {
	bool operator() (const int& a, const int& b) {
		return a > b;
	}
};

int N, M;
vector<int> map[32001];
int previous[32001];
bool solved[32001];
//priority_queue<struct data, vector<struct data>, cmp> pq;
priority_queue<int, vector<int>, cmp2> pq;

int main() {
	cin >> N >> M;
	int a, b;
	while(M--){
		cin >> a >> b;
		map[a].push_back(b);
		previous[b]++;
	}

	for (int i = 1; i <= N; i++) {	
		if (previous[i] == 0) pq.push(i);
	}

	int x;
	while (!pq.empty()) {
		x = pq.top();
		pq.pop();
		cout << x << ' ';

		for (int i = 0; i < (int)map[x].size(); i++) {
			if (--previous[map[x][i]] == 0) {
				pq.push(map[x][i]);
			}
		}
	}
}

//2번조건을 만족하는 놈들 중에서 문제 번호가 가장 작은 놈을 선택하겠다.