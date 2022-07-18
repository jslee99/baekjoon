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
				�Ϲ����� ���ͽ�Ʈ�� �˰���� ���� �ٸ�.
				�ϴ� vertex�� 1�� �����غ��ٸ�
				pq�� 1,12�� push������ 1,10�� push�ɼ� �ִ�.(dist�� 12 -> 10���� �ٲ�Ե�_
				���� pq���� 1,10 pop�ǰ� �Ǹ� �ּҰ��(dist[1])�� 10���� �����ǰԵǰ� ���� vertex���� �ּҰ�ε� ������Ʈ �ȴ�.
				�״����� pq���� 1, 12�� pop �ǰ� �Ǵ°�� (�̹� ������ dist[i]�� ���� vertext���� �ּҰ�ΰ� ������Ʈ �Ǿ��� ������)
				1, 12�� pop�Ǵ� ���� �ƹ��� ���⵵ ��ġ�� ���ϰ� �ȴ�.

				-> �ٽ� �����غ��� �̹� 1,10 push�� ��������  1,12�� ������ �ȰͰ� ���������μ��̴�. �� 1,12 ���� 1,10�� key��(����� ����ġ)�� �ٲ���ٰ� ���� �մ�.
				�׷��Ƿ� decrease key() ���̵� ���ͽ�Ʈ�� �˰���� �Ȱ��� ȿ���� ���� �Ǵ°��̴�.
				
				->heap, decrease key�� �����ؼ� �Ȱ��� ������.
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