#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int V, E;
struct edge {
	int n1, n2;
	int weight;
};
struct edge edge_list[100000];//, weight, n1, n2
int parent[10000];
bool compare(const struct edge& e1, const struct edge& e2) {
	return e1.weight < e2.weight;
}
int find(int n) {
	if (n == parent[n])
		return n;
	else {
		parent[n] = find(parent[n]);
		return parent[n];
	}
}
int ans = 0;

int main(void) {
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a1, a2, w;
		cin >> a1 >> a2 >> w;
		a1--, a2--;
		edge_list[i].n1 = a1, edge_list[i].n2 = a2, edge_list[i].weight = w;
	}

	for (int i = 0; i < V; i++) {
		parent[i] = i;
	}

	sort(edge_list, edge_list + E, compare);



	for (int i = 0; i < E; i++) {
		int p1 = find(edge_list[i].n1);
		int p2 = find(edge_list[i].n2);
		if (p1 == p2) {

		}
		else if (p1 < p2) {
			parent[p2] = p1;
			ans += edge_list[i].weight;
		}
		else {// p1 > p2
			parent[p1] = p2;
			ans += edge_list[i].weight;
		}
	}

	cout << ans << endl;
}