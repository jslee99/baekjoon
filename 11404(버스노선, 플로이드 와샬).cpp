#include<iostream>
#include<climits>

using namespace std;

int n, m;
int floyd[101][101];

int main(void) {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) floyd[i][j] = INT_MAX;

	for (int i = 1; i <= n; i++) floyd[i][i] = 0;

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		floyd[a][b] = min(floyd[a][b], c);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (floyd[i][k] != INT_MAX && floyd[k][j] != INT_MAX) {
					floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (floyd[i][j] == INT_MAX) {
				cout << 0 << ' ';
			}
			else {
				cout << floyd[i][j] << ' ';
			}
		}
		cout << endl;
	}
}