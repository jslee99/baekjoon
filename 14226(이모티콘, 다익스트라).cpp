#include<iostream>
#include<queue>

int MAX = 1000;

using namespace std;

class TRI {
public:
	int b;
	int w;
};

struct cmp {
	bool operator()(TRI a, TRI b) {
		return a.w > b.w;
	}
};

int visit[2005];
int s;
priority_queue<TRI, vector<TRI>, cmp> pq;

bool isIn(int x) {
	return x >= 0 && x <= MAX;
}

int main() {
	cin >> s;

	for (int i = 0; i <= MAX; i++) visit[i] = -1;

	TRI x;
	x.b = 1, x.w = 0;
	pq.push(x);
	while (!pq.empty()) {
		x = pq.top();
		pq.pop();

		if (visit[x.b] != -1) continue;

		visit[x.b] = x.w;

		TRI y;
		y.b = x.b - 1, y.w = x.w + 1;
		if (isIn(y.b)) {
			pq.push(y);
		}

		if (x.b == 0) continue;

		for (int i = 2; i * x.b <= MAX; i++) {
			y.b = i * x.b, y.w = x.w + i;
			pq.push(y);
		}


	}

	cout << visit[s] << '\n';
}