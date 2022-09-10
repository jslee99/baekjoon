#include<iostream>
#include<vector>

using namespace std;
int N, M;
vector<int> true_p;
vector<vector<int>> party;
bool can_lie[51];
int root[51];

int find(int x) {
	if (root[x] == x) return x;
	else {
		return root[x] = find(root[x]);
	}
}

int main(void) {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) root[i] = i, can_lie[i] = true;

	int true_p_num;
	cin >> true_p_num;
	while (true_p_num--) {
		int a1;
		cin >> a1;
		true_p.push_back(a1);
	}

	for (int j = 0; j < M; j++) {
		party.push_back(vector<int>());
		int n;
		cin >> n;
		while (n--) {
			int a1;
			cin >> a1;
			party[j].push_back(a1);
		}
		if ((int)party[j].size() == 1) continue;

		for (int i = 0; i < (int)party[j].size() - 1; i++) {
			int a1, a2;
			a1 = party[j][i], a2 = party[j][i + 1];
			if (a1 > a2) {
				int tmp = a1;
				a1 = a2;
				a2 = tmp;
			}
			if (find(a1) != find(a2)) {
				root[root[a2]] = root[a1];
			}
		}
	}

	for (int i = 0; i < (int)true_p.size(); i++) {
		can_lie[true_p[i]] = false;
	}
	for (int i = 1; i <= N; i++) {
		if (!can_lie[i]) continue;

		for (int j = 0; j < (int)true_p.size(); j++) {
			if (find(i) == find(true_p[j])) can_lie[i] = false;
		}
	}

	int ans = 0;
	for (int i = 0; i < M; i++) {
		bool flag = true;
		for (int j = 0; j < (int)party[i].size(); j++) {
			if (!can_lie[party[i][j]]) {
				flag = false;
				break;
			}
		}
		if (flag) ans++;
	}

	cout << ans << endl;
}