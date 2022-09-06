#include<iostream>
#include<limits>
using namespace std;

int num[8];
bool visited[8];
int seq[8];
int N;
int ans = 0;


void calc() {
	int sum = 0;
	for (int i = 0; i < N - 1; i++) {
		sum += abs(seq[i + 1] - seq[i]);
	}
	ans = max(ans, sum);
}

void make_seq(int depth) {
	if (depth == N) calc();

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			seq[depth] = num[i];
			visited[i] = true;
			make_seq(depth + 1);
			visited[i] = false;
		}
	}
}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	make_seq(0);

	cout << ans << endl;
}