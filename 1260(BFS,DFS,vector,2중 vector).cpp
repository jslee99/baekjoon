#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

void reset(bool* visit, int n) {
	for (int i = 0; i < n; i++) {
		visit[i] = false;
	}
}

void dfs(bool* visit,const vector<vector<int>>&  a,int v) {
	printf("%d ", v);
	visit[v] = true;
	for (int i = 0; i < a[v].size(); i++) {
		if (visit[a[v][i]] == false) {
			dfs(visit, a, a[v][i]);
		}		
	}
}
void bfs(bool* visit, const vector<vector<int>>& a, int v) {
	queue<int> q;
	q.push(v);
	visit[v] = true;
	while (!q.empty()) { //front ,dequeue
		int x = q.front();
		q.pop();
		printf("%d ", x);
		visit[x] = true;
		for (int i = 0; i < a[x].size(); i++) {
			if (visit[a[x][i]] == false) {
				q.push(a[x][i]);
				visit[a[x][i]] = true;
			}
		}
	}
}
int main(void) {
	int n, m, v;
	scanf("%d %d %d", &n, &m, &v);
	vector<vector<int>> a(n + 1,vector<int>());
	bool* visit = new bool[n + 1];
	reset(visit, n + 1);

	while (m--) {
		int a1, a2;
		scanf("%d %d", &a1, &a2);
		a[a1].push_back(a2);
		a[a2].push_back(a1);
	}
	for (int i = 1; i < a.size(); i++) {
		sort(a[i].begin(), a[i].end());
	}
	dfs(visit, a, v);
	reset(visit, n + 1);
	printf("\n");
	bfs(visit, a, v);


	delete[] visit;
	/*
	bool* visit = new bool[n + 1];
	for (int i = 0; i < n + 1; i++) {
		visit[i] = false;
	}
	*/

	/*
	while (!s.empty()) {
		v = s.top();
		s.pop();
		printf("%d ", v);
		vector<int> vec;
		for (int i = 0; i < a[v].size(); i++) {
			if (visit[a[v][i]] == false) {
				vec.push_back(a[v][i]);
				visit[a[v][i]] = true;
			}
		}
		sort(vec.begin(), vec.end());
		for (int i = vec.size() - 1; i >= 0; i--) {
			s.push(vec[i]);
		}
	}*/




	

}