#include<iostream>

using namespace std;

int T;
int INF = 99999999;
int cost[500][500];
int file_size[500][500];

int main(void){
	cin >> T;
	while (T--) {
		int N;
		cin >> N;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cost[i][j] = INF;
			}
		}

		for (int i = 0; i < N; i++) {
			cin >> file_size[i][i];
			cost[i][i] = 0;
		}
		for (int k = 1; k < N; k++) {
			for (int i = 0; i + k < N; i++) {// i ~ i + k
				file_size[i][i + k] = file_size[i][i] + file_size[i + 1][i + k];
			}
		}


		for (int k = 1; k < N; k++) {
			for (int i = 0; i + k < N; i++) {// i ~ i + k
				for (int j = i; j < i + k; j++) {// i ~ j  j + 1 ~ i + k
					cost[i][i + k] = min(cost[i][i + k], cost[i][j] + cost[j + 1][i + k] + file_size[i][j] + file_size[j + 1][i + k]);
				}
			}
		}

		cout << cost[0][N - 1] << endl;
;	}
}
