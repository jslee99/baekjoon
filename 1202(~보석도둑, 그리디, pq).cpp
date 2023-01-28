#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

struct cmp {
	bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
		return a.second < b.second;
	}
};

pair<int, int> diamond[300000]; // 무게 가격
int sack[300000];
int N, K;
int select_idx = 0;
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
long long ans = 0;

int main(void) {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> diamond[i].first >> diamond[i].second;
	}
	for (int i = 0; i < K; i++) {
		cin >> sack[i];
	}

	sort(diamond, diamond + N);
	sort(sack, sack + K);

	for (int i = 0; i < K; i++) {
		while (select_idx < N && diamond[select_idx].first <= sack[i]) {
			pq.push(diamond[select_idx++]);
		}

		if (!pq.empty()) {
			ans += (long long)pq.top().second;
			pq.pop();
		}
	}

	cout << ans << endl;

	return 0;
}

//2nlogn + klogk
//각 보석은 pq에 한번만 들어갔다가 나온다.