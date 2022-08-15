#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int N, M;
bool path_exist[200][200];
vector<pair<int, int>> edge_lst;
queue<int> dest;
int parent[200];

int find(int n) {
	if (n == parent[n]) {
		return n;
	}
	else {
		parent[n] =  find(parent[n]);
		return parent[n];
	}
}

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int a1;
			cin >> a1;

			if (i > j) continue;
			if (a1 == 1) {
				edge_lst.push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 0; i < M; i++) {
		int a1;
		cin >> a1;
		dest.push(a1 - 1);
	}

	for (int i = 0; i < (int)edge_lst.size(); i++) {
		int first_parent = find(edge_lst[i].first);
		int second_parent = find(edge_lst[i].second);
		if (first_parent < second_parent) {
			parent[second_parent] = first_parent;
		}
		else if (first_parent > second_parent) {
			parent[first_parent] = second_parent;
		}
	}


	int a, b;
	b = dest.front();
	dest.pop();
	bool flag = true;
	while (!dest.empty()) {
		a = b;
		b = dest.front();
		dest.pop();
		if (find(a) != find(b)) {
			flag = false;
		}
	}

	if (flag) cout << "YES" << endl;
	else cout << "NO" << endl;
}
