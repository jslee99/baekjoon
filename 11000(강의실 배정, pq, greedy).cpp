#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int N;
pair<int, int> lecture[200000];

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first < b.first;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> lecture[i].first >> lecture[i].second;
	}

	sort(lecture, lecture + N, compare);
	priority_queue<int, vector<int>, greater<int>> pq;

	pq.push(lecture[0].second);

	for (int i = 1; i < N; i++) {
		if (pq.top() <= lecture[i].first) {
			pq.pop();
			pq.push(lecture[i].second);
		}
		else {
			pq.push(lecture[i].second);
		}
	}

	cout << pq.size() << endl;

}