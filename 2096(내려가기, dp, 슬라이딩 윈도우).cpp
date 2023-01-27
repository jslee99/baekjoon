#include<iostream>

using namespace std;
int A, B, C;
int max_dp_A, max_dp_B, max_dp_C;
int min_dp_A, min_dp_B, min_dp_C;
int N;
int max_score, min_score;


int main(void) {
	cin >> N;
	cin >> A >> B >> C;
	max_dp_A = A, max_dp_B = B, max_dp_C = C;
	min_dp_A = A, min_dp_B = B, min_dp_C = C;
	for (int i = 1; i < N; i++) {
		cin >> A >> B >> C;
		int before_max_dp_A = max_dp_A, before_max_dp_B = max_dp_B, before_max_dp_C = max_dp_C;
		int before_min_dp_A = min_dp_A, before_min_dp_B = min_dp_B, before_min_dp_C = min_dp_C;

		max_dp_A = max(before_max_dp_A + A, before_max_dp_B + A);
		max_dp_B = max(max(before_max_dp_B + B, before_max_dp_A + B), before_max_dp_C + B);
		max_dp_C = max(before_max_dp_C + C, before_max_dp_B + C);

		min_dp_A = min(before_min_dp_A + A, before_min_dp_B + A);
		min_dp_B = min(min(before_min_dp_A + B, before_min_dp_B + B), before_min_dp_C + B);
		min_dp_C = min(before_min_dp_C + C, before_min_dp_B + C);
	}

	max_score = max(max(max_dp_A, max_dp_B), max_dp_C);
	min_score = min(min(min_dp_A, min_dp_B), min_dp_C);
	cout << max_score << " " << min_score << endl;
}