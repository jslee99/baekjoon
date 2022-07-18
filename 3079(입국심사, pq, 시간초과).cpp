#include<iostream>
#include<queue>

using namespace std;

int N, M;//N개의 심사대 M명의 사람
long long check_time[100000];
long long ans;

int main(void) {
	priority_queue<pair<long long, long long>, vector<pair<long long,long long>> , greater<pair<long long,long long>>> pq;//finish time when i'm in  and   index of check
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> check_time[i];
		pq.push(make_pair(check_time[i], i));
	}
	for (int i = 0; i < M; i++) {
		if (i == M - 1)
			ans = pq.top().first;
		pair<long, long> temp = pq.top();
		pq.pop();
		pq.push(make_pair(temp.first + check_time[temp.second], temp.second));
	}
	cout << ans << endl;
}
