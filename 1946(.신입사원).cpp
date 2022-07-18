#include<iostream>
#include<algorithm>

using namespace std;

int T;
int N;
pair<int, int> score[100000];

int main(void) {
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> score[i].first >> score[i].second;
		}
		sort(score, score + N);
		int criteria_score = score[0].second;
		int num = 1;
		for (int i = 1; i < N; i++) {
			if (score[i].second < criteria_score) {
				num++;
				criteria_score = score[i].second;
			}
		}
		cout << num << endl;
	}
}
