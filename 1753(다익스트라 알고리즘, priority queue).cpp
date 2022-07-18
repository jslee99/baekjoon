#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF = 987654321;
int V, E;
int x, w;
vector<vector<pair<int, int>>> edge(20001);//vertex,weight
int dist[20001];
struct cmp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;//a:parent nod, b:child node
	}
};
priority_queue < pair<int, int>, vector<pair<int, int>>, cmp> pq;//vertex,min path

int main(void) {
	scanf("%d %d", &V, &E);
	scanf("%d", &x);
	while (E--) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		edge[u].push_back(make_pair(v, w));
	}
	for (int i = 1; i < V + 1; i++) {
		dist[i] = INF;
	}
	dist[x] = 0;
	pq.push(make_pair(x, 0));
	while (!pq.empty()) {
		x = pq.top().first, w = pq.top().second;
		pq.pop();
		for (int i = 0; i < edge[x].size(); i++) {
			if (w + edge[x][i].second < dist[edge[x][i].first]) {
				dist[edge[x][i].first] = w + edge[x][i].second;
				pq.push(make_pair(edge[x][i].first, dist[edge[x][i].first]));
				/*
				일반적인 다익스트라 알고리즘과 조금 다름.
				일단 vertex를 1에 집중해본다면
				pq에 1,12가 push된이후 1,10이 push될수 있다.(dist는 12 -> 10으로 바뀌게됨_
				그후 pq에서 1,10 pop되게 되면 최소경로(dist[1])은 10으로 고정되게되고 주위 vertex들의 최소경로도 업데이트 된다.
				그다음에 pq에서 1, 12가 pop 되게 되는경우 (이미 이전에 dist[i]와 주위 vertext들의 최소경로가 업데이트 되었기 때문에)
				1, 12가 pop되는 것은 아무런 영향도 미치지 못하게 된다.

				-> 다시 생각해보면 이미 1,10 push된 시점에서  1,12는 삭제가 된것과 마찬가지인셈이다. 즉 1,12 에서 1,10을 key값(경로의 가중치)이 바뀌었다고 볼수 잇다.
				그러므로 decrease key() 없이도 다익스트라 알고리즘과 똑같은 효과를 내게 되는것이다.
				
				->heap, decrease key를 구현해서 똑같이 만들어본다.
				*/
			}
		}
	}
	for (int i = 1; i < V + 1; i++) {
		if (dist[i] == INF) {
			printf("INF\n");
		}
		else {
			printf("%d\n", dist[i]);
		}
	}
}