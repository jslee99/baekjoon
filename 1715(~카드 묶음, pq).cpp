#include<iostream>
#include<queue>

using namespace std;

int N;
int bundle[100000];
priority_queue<int, vector<int>, greater<int>> pq;
int ans = 0;

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a1;
		cin >> a1;
		pq.push(a1);
	}

	while ((int)pq.size() > 1) {
		int a1, a2;
		a1 = pq.top();
		pq.pop();
		a2 = pq.top();
		pq.pop();
		ans += a1 + a2;
		pq.push(a1 + a2);
	}

	cout << ans << endl;
}
