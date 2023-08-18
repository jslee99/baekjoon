#include<iostream>

using namespace std;

class TRI {
public:
	int a;
	int b;
	long long w;
};

int n, m;
long long inf = 600000001;

long long dist[505];
TRI edge[6005];
long long ans[505];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		long long w;
		cin >> a >> b >> w;
		edge[i].a = a, edge[i].b = b, edge[i].w = w;
	}

	for (int i = 1; i <= n; i++) dist[i] = inf;
	dist[1] = 0;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			int a = edge[j].a, b = edge[j].b;
			long long w = edge[j].w;

			if (dist[a] != inf && dist[a] + w < dist[b]) {
				dist[b] = dist[a] + w;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dist[i] == inf) ans[i] = -1;
		else ans[i] = dist[i];
	}

	bool flag = false;
	for (int j = 0; j < m; j++) {
		int a = edge[j].a, b = edge[j].b;
		long long w = edge[j].w;

		if (dist[a] != inf && dist[a] + w < dist[b]) {
			flag = true;
		}
	}

	if (flag) {
		cout << -1 << '\n';
	}
	else {
		for (int i = 2; i <= n; i++) cout << ans[i] << '\n';
	}


	return 0;
}