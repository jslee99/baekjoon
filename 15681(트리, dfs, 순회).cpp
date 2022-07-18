#include<iostream>
#include<vector>

using namespace std;
int N, R, Q;
vector<int> map[100000];
int ans[100000];
int visit[100000];

int postorder(int node) {
	if (map[node].size() == 1 && node != R) {
		//leaves
		visit[node] = 1;
		return 1;
	}
	else {
		visit[node] = 1;
		for (int i = 0; i < map[node].size(); i++) {
			if (visit[map[node][i]] == 0)
				ans[node] += postorder(map[node][i]);
		}
		return ans[node];
	}
}

int main(void) {
	scanf("%d %d %d", &N, &R, &Q);
	R = R - 1;
	for (int i = 0; i < N - 1; i++) {
		int a1, a2;
		scanf("%d %d", &a1, &a2);
		map[a1 - 1].push_back(a2 - 1);
		map[a2 - 1].push_back(a1 - 1);
	}

	for (int i = 0; i < N; i++) {
		visit[i] = 0;
		ans[i] = 1;
	}

	postorder(R);

	for (int i = 0; i < Q; i++) {
		int a1;
		scanf("%d", &a1);
		printf("%d\n", ans[a1 - 1]);
	}
}