#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#define INF 99999999;

using namespace std;

int N, M;
int cost[1001];
vector<vector<pair<int,int>>> adj;//weight endpoint
int S, E;
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i <= N; i++)
		adj.push_back(vector<pair<int, int>>()), cost[i] = INF;
	scanf("%d", &M);
	while (M--) {
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);
		adj[s].push_back(make_pair(w, e));
	}
	scanf("%d %d", &S, &E);
	cost[S] = 0;
	pq.push(make_pair(0, S));
	while (!pq.empty()) {
		if (pq.top().first > cost[pq.top().second]) {
			pq.pop();
			continue;
		}

		for (int i = 0; i < adj[pq.top().second].size(); i++) 
			if (pq.top().first + adj[pq.top().second][i].first < cost[adj[pq.top().second][i].second]){
				cost[adj[pq.top().second][i].second] = pq.top().first + adj[pq.top().second][i].first;
				pq.push(make_pair(cost[adj[pq.top().second][i].second], adj[pq.top().second][i].second));
			}
		pq.pop();
	}
	printf("%d", cost[E]);
}


