#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;

class TRI {
public:
	int a;
	int b;
	long long d;
};

bool cmp(TRI a, TRI b) {
	return a.d < b.d;
}

vector<TRI> v;
long long sumCost;
int p[200005];
long long minCost;

int find(int x) {
	if (p[x] == x) {
		return x;
	}
	else {
		int pp = find(p[x]);
		p[x] = pp;
		return pp;
	}
}

void uni(int a, int b) {
	int rootB = find(b);
	int rootA = find(a);
	if (rootA < rootB) {
		p[rootB] = rootA;
	}
	else {
		p[rootA] = rootB;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> n >> m;
		sumCost = 0;
		minCost = 0;
		v.clear();
		for (int i = 0; i < n; i++)
			p[i] = i;

		if (n == 0 && m == 0)
			break;

		while (m--) {
			int a, b;
			long long d;
			cin >> a >> b >> d;
			if (a > b)
				swap(a, b);
			TRI x;
			x.a = a, x.b = b, x.d = d;
			v.push_back(x);
			sumCost += d;
		}

		sort(v.begin(), v.end(), cmp);

		for (vector<TRI>::iterator it = v.begin(); it != v.end(); it++) {
			TRI x = *it;
			if (find(x.a) == find(x.b))
				continue;

			uni(x.a, x.b);
			minCost += x.d;
		}

		cout << sumCost - minCost << '\n';
	}

}