#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int map[100001];
int N, K;
struct cmp {
	bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}
};



int main(void) {
	for (int i = 0; i <= 100000; i++) {
		map[i] = -1;
	}
	cin >> N >> K;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
	pq.push(make_pair(0, N));
	map[N] = 0;
	while (!pq.empty()) {
		int location = pq.top().second;
		if (location == K)
			break;
		pq.pop();
		if (location * 2 <= 100000 && map[location * 2] == -1) {
			map[location * 2] = map[location];
			pq.push(make_pair(map[location * 2], location * 2));
		}
		if (location + 1 <= 100000 && map[location + 1] == -1) {
			map[location + 1] = map[location] + 1;
			pq.push(make_pair(map[location + 1], location + 1));
		}
		if (location - 1 >= 0 && map[location - 1] == -1) {
			map[location - 1] = map[location] + 1;
			pq.push(make_pair(map[location - 1], location - 1));
		}
	}
	cout << map[K];
	return 0;
}