#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class node {
public:
	int w;
	vector<int> prev;
};
node nodes[10005];
vector<pair<int, int>> map[10005];
bool visit[10005];
int n, m;
int post = 0;
int s, e;
vector<pair<int, int>> tp;
int ans = 0;

void dfs(int nd) {
	visit[nd] = true;

	for (int i = 0; i < map[nd].size(); i++) {
		int ch = map[nd][i].first;
		if (visit[ch]) continue;
		dfs(ch);
	}

	tp.push_back(make_pair(post++, nd));
}

void revDfs(int nd) {
	visit[nd] = true;

	for (int i = 0; i < nodes[nd].prev.size(); i++) {
		int prev = nodes[nd].prev[i];
		ans++;
		if (visit[prev]) continue;

		revDfs(prev);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back(make_pair(b, c));
	}
	cin >> s >> e;

	dfs(s);

	sort(tp.begin(), tp.end(), greater<pair<int, int>>());

	for (int i = 0; i < tp.size(); i++) {//max dist�� ���ϰ�, max dist�� �ش��ϴ� prev node�� ��ȣ�� �����ص�
		int nd = tp[i].second;
		for (int j = 0; j < map[nd].size(); j++) {
			int ch = map[nd][j].first;
			int w = map[nd][j].second;
			if (nodes[ch].w < nodes[nd].w + w) {
				nodes[ch].w = nodes[nd].w + w;
				nodes[ch].prev.clear();
				nodes[ch].prev.push_back(nd);
			}
			else if (nodes[ch].w == nodes[nd].w + w) {
				nodes[ch].prev.push_back(nd);
			}
		}
	}

	for (int i = 1; i <= n; i++) visit[i] = false;
	revDfs(e);//������ �����ص� prev node�� ������ s���� e�� �ִ� �Ÿ��� ���� ��ο� ���ԵǾ� �ִ� ��� edge�� ���� ����

	cout << nodes[e].w << '\n' << ans << '\n';

	return 0;
}