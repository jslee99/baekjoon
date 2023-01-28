#include<iostream>
#include<cfloat>
#include <limits>
#include<cmath>

typedef std::numeric_limits< double > dbl;

using namespace std;
int T;

void calc(int num_of_pts, bool is_start[], double& ans, pair<int, int> pts[]) {
	pair<int, int> sum_of_vec;
	sum_of_vec.first = 0, sum_of_vec.second = 0;

	for (int i = 0; i < num_of_pts; i++) {
		if (is_start[i]) {
			sum_of_vec.first -= pts[i].first;
			sum_of_vec.second -= pts[i].second;
		}
		else {
			sum_of_vec.first += pts[i].first;
			sum_of_vec.second += pts[i].second;
		}
	}

	ans = min(ans, sqrt(pow((double)sum_of_vec.first, 2) + pow((double)sum_of_vec.second, 2)));
}

void dfs(int num_of_start, int last_selected_idx,int num_of_pts, bool is_start[], double& ans, pair<int,int> pts[]) {
	if (num_of_start == num_of_pts / 2) {
		calc(num_of_pts, is_start, ans, pts);
		return;
	}

	for (int i = last_selected_idx + 1; i < num_of_pts; i++) {
		is_start[i] = true;
		dfs(num_of_start + 1, i, num_of_pts, is_start, ans, pts);
		is_start[i] = false;
	}
}

int main(void) {
	cin >> T;
	while (T--) {
		int N;
		pair<int, int> pts[20];
		bool is_start[20];
		double ans = DBL_MAX;
		cin >> N;
		for (int i = 0; i < N; i++) {
			is_start[i] = false;
		}

		for (int i = 0; i < N; i++) {
			cin >> pts[i].first >> pts[i].second;
		}

		dfs(0, -1, N, is_start, ans, pts);

		cout.precision(dbl::max_digits10);
		cout << ans << endl;
	}
}
//출발점과 도착점만 10개씩 정해주면 벡터의 합은 바로 정할 수 있다.
// ex 점 0 , 1 , 2 , 3 이 있을때 0 -> 1, 2 -> 3 의 합이나 0 -> 3, 2 -> 1의 합이나 같다.