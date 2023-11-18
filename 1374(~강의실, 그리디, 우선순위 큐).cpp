#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>

using namespace std;

struct cmp2 {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

int n;
pair<int, int> a[100005];
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp2> pq;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int b, c, d;
		cin >> b >> c >> d;
		a[i] = make_pair(c, d);
	}

	sort(a, a + n, cmp);
	pq.push(a[0]);
	for (int i = 1; i < n; i++) {
		if (a[i].first < pq.top().second) {
			pq.push(a[i]);
		}
		else {
			pq.pop();
			pq.push(a[i]);
		}
	}

	cout << pq.size() << '\n';

	return 0; 
}