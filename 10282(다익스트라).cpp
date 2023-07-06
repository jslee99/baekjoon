#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class TRI {
public:
	int a;
	int b;
	int w;
};

struct cmp {
	bool operator() (TRI a, TRI b) {
		return a.w > b.w;
	}
};

int t;
int n, d, c;
vector<pair<int, int>> map[10005];
int visit[10005];
priority_queue<TRI, vector<TRI>, cmp> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n >> d >> c;
		for (int i = 1; i <= n; i++) map[i].clear(), visit[i] = -1;
		while (d--) {
			int a, b, s;
			cin >> a >> b >> s;
			map[b].push_back(make_pair(a, s));
		}

		TRI x;
		x.a = 0, x.b = c, x.w = 0;
		pq.push(x);
		while (!pq.empty()) {
			x = pq.top();
			pq.pop();
			if (visit[x.b] != -1) continue;

			visit[x.b] = x.w;

			for (int i = 0; i < map[x.b].size(); i++) {
				int ch = map[x.b][i].first;
				int w = map[x.b][i].second;
				TRI y;
				y.a = x.b, y.b = ch, y.w = x.w + w;
				pq.push(y);
			}
		}

		int num = 0, maxTime = 0;
		for (int i = 1; i <= n; i++) {
			if (visit[i] != -1) {
				num++;
				maxTime = max(maxTime, visit[i]);
			}
		}
		cout << num << ' ' << maxTime << '\n';
	}
}