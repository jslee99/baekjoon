#include<iostream>
#include<cstdlib>
#include<limits>

using namespace std;

int door_num;
int open1, open2;
int N;
int want_to_open[21];
int min_cost = numeric_limits<int>::max();

void back_track(int open1, int open2, int target, int depth, int cost) {// always open1 < open2
	if (depth < N) {
		if (target == open1 || target == open2) {
			back_track(open1, open2, want_to_open[depth + 1], depth + 1, cost);
		}
		else if (open2 < target) {
			back_track(open1, target, want_to_open[depth + 1], depth + 1, cost + target - open2);
		}
		else if (open1 > target) {
			back_track(target, open2, want_to_open[depth + 1], depth + 1, cost + open1 - target);
		}
		else {
			//open1À» ´Ý´Â °æ¿ì
			back_track(target, open2, want_to_open[depth + 1], depth + 1, cost + target - open1);
			back_track(open1, target, want_to_open[depth + 1], depth + 1, cost + open2 - target);
		}
	}
	else {
		if (min_cost > cost) {
			min_cost = cost;
		}
	}
}

int main(void) {
	for (int i = 0; i < 21; i++) {
		want_to_open[i] = -1;
	}
	cin >> door_num;
	cin >> open1 >> open2;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		want_to_open[i] = number - 1;
	}

	if (open2 < open1) {
		int temp = open1;
		open1 = open2;
		open2 = temp;
	}

	back_track(open1 - 1, open2 - 1, want_to_open[0], 0, 0);

	cout << min_cost << endl;
}
