#include<iostream>
#include<algorithm>

using namespace std;
int N, K;
int sensor[10000];
int _distance[9999];
int total_distance = 0;

bool compare(int i, int j) {
	return i > j;
}

int main(void){
	cin >> N;
	cin >> K;
	for (int i = 0; i < N; i++) {
		cin >> sensor[i];
	}
	if (K >= N) {
		cout << 0 << endl;
		exit(0);
	}

	sort(sensor, sensor + N);
	for (int i = 0; i < N - 1; i++) {
		_distance[i] = sensor[i + 1] - sensor[i];
		total_distance += sensor[i + 1] - sensor[i];
	}
	sort(_distance, _distance + (N - 1), compare);
	for (int i = 0; i < K - 1; i++) {
		total_distance -= _distance[i];
	}

	cout << total_distance << endl;
	
}