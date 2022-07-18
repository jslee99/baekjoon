#include<iostream>
#include<queue>

using namespace std;

int w, L, n;
int truck[1000];
int truck_head = 0;
int t_time = 0;
int cur_weight = 0;
int cur_num = 0;
queue<int> bridge;

int main(void) {
	cin >> n >> w >> L;
	for (int i = 0; i < n; i++) {
		cin >> truck[i];
	}
	for (int i = 0; i < w; i++) {
		bridge.push(-1);
	}
	do {
		if (bridge.front() != -1) {
			cur_weight = cur_weight - truck[bridge.front()];
			bridge.pop();
			cur_num--;
		}
		else {
			bridge.pop();
		}

		if (truck_head < n && cur_weight + truck[truck_head] <= L) {
			cur_weight = cur_weight + truck[truck_head];
			bridge.push(truck_head);
			cur_num++;
			truck_head++;
		}
		else {
			bridge.push(-1);
		}
		t_time++;
	} while (cur_num > 0);

	cout << t_time;
}
