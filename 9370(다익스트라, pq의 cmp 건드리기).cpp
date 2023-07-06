#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>

using namespace std;

int T;
int n, m, t, s, g, h;
class node {
public:
	int dist;
	bool iSGH;
	vector<pair<int, int>> adj;
};
node nodes[2005];
vector<int> cand;

class TRI {
public:
	int a;
	int b;
	int d;
	bool isGH;
};

//최단거리가 여러개 있을때 gh를 지나가는 최단거리를 더 우선순위로 둠
struct cmp {
	bool operator() (TRI a, TRI b) {
		if (a.d > b.d) {
			return true;
		}
		else if (a.d == b.d) {
			if (b.isGH && !a.isGH) return true;
			else return false;
		}
		else {
			return false;
		}
	}
};

priority_queue<TRI, vector<TRI>, cmp> pq;

bool isGhEdge(int x, int y) {
	return (x == g && y == h) || (y == g && x == h);
}

bool compare(int a, int b) {
	return a < b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> n >> m >> t;
		cin >> s >> g >> h;

		for (int i = 1; i <= n; i++) nodes[i].dist = INT_MAX, nodes[i].iSGH = false, nodes[i].adj.clear();
		cand.clear();

		while (m--) {
			int a, b, d;
			cin >> a >> b >> d;
			nodes[a].adj.push_back(make_pair(b, d));
			nodes[b].adj.push_back(make_pair(a, d));
		}

		while (t--) {
			int a;
			cin >> a;
			cand.push_back(a);
		}

		TRI x;
		x.a = 0, x.b = s, x.d = 0, x.isGH = false;;
		pq.push(x);
		while (!pq.empty()) {
			x = pq.top();
			pq.pop();

			if (nodes[x.b].dist != INT_MAX) continue;

			nodes[x.b].dist = x.d;
			nodes[x.b].iSGH = x.isGH;
			for (int i = 0; i < nodes[x.b].adj.size(); i++) {
				int to = nodes[x.b].adj[i].first;
				int w = nodes[x.b].adj[i].second;
				TRI y;
				y.a = x.b, y.b = to, y.d = x.d + w, y.isGH = x.isGH;

				if (isGhEdge(x.b, to)) y.isGH = true;

				pq.push(y);
			}
		}

		vector<int> ans;
		for (int i = 0; i < cand.size(); i++) {
			if (nodes[cand[i]].iSGH) ans.push_back(cand[i]);
		}

		sort(ans.begin(), ans.end(), compare);

		for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
		cout << '\n';
	}
	return 0;
}