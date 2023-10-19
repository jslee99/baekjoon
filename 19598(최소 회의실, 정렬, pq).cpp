#include<iostream>
#include<algorithm>
#include<queue>
#include<functional>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int n;
pair<int, int> a[100005];

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int ans = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;

	sort(a + 1, a + n + 1, cmp);

	pq.push(a[1].second);
	for (int i = 2; i <= n; i++) {
		while (!pq.empty() && pq.top() <= a[i].first) {
			pq.pop();
		}
		pq.push(a[i].second);
		ans = max(ans, (int)pq.size());
	}

	cout << ans;

	return 0;
}