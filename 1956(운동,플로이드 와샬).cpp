#include<iostream>
#include<limits>
#include<vector>

using namespace std;
int V, E;
int FW[400][400];
int map[400][400];
int ans = numeric_limits<int>::max();
const int INF = numeric_limits<int>::max();

int main(void) {
	cin >> V >> E;
	for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) FW[i][j] = INF, map[i][j] = INF;

	for (int i = 0; i < E; i++) {
		int a1, a2, w;
		cin >> a1 >> a2 >> w;
		a1--, a2--;
		map[a1][a2] = w;
		FW[a1][a2] = w;
	}

	for (int mid = 0; mid < V; mid++) {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (FW[i][mid] != INF && FW[mid][j] != INF) {
					FW[i][j] = min(FW[i][j], FW[i][mid] + FW[mid][j]);
				}
			}
		}
	}

	for (int i = 0; i < V; i++) ans = min(ans, FW[i][i]);

	if (ans == numeric_limits<int>::max()) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}
}