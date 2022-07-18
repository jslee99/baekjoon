#include<iostream>
#include<deque>
#include<iostream>
using namespace std;

int map[100001];
int N, K;

int main(void) {
	for (int i = 0; i <= 100000; i++) {
		map[i] = -1;
	}
	deque<int> dq;
	cin >> N >> K;
	dq.push_back(N);
	map[N] = 0;
	while (!dq.empty()) {
		int location = dq.front();
		if (location == K)
			break;
		dq.pop_front();
		if (2 * location <= 100000 && map[location * 2] == -1) {
			map[2 * location] = map[location];
			dq.push_front(2 * location);
		}
		if (location + 1 <= 100000 && map[location + 1] == -1) {
			map[location + 1] = map[location] + 1;
			dq.push_back(location + 1);
		}
		if (location - 1 >= 0 && map[location - 1] == -1) {
			map[location - 1] = map[location] + 1;
			dq.push_back(location - 1);
		}
		
	}
	printf("%d\n", map[K]);
}
