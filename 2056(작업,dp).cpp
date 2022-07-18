#include<iostream>
#include<vector>

using namespace std;

int N;
int cost_of_job[10000];
vector<vector<int>> beforejob_of_job;
int max_cost = 0;
int dp_cost_until_job[10000];


int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		dp_cost_until_job[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		beforejob_of_job.push_back(vector<int>());
	}

	for (int i = 0; i < N; i++) {
		scanf("%d", &cost_of_job[i]);
		int jobnum_of_before;
		scanf("%d", &jobnum_of_before);
		for (int j = 0; j < jobnum_of_before; j++) {
			int before_job;
			scanf("%d", &before_job);
			beforejob_of_job[i].push_back(before_job - 1);
		}
	}

	for (int job = 0; job < N; job++) {
		if (beforejob_of_job[job].size() == 0) {
			dp_cost_until_job[job] = cost_of_job[job];
		}

		for (int i = 0; i < beforejob_of_job[job].size(); i++) {
			if (dp_cost_until_job[job] < cost_of_job[job] + dp_cost_until_job[beforejob_of_job[job][i]])
				dp_cost_until_job[job] = cost_of_job[job] + dp_cost_until_job[beforejob_of_job[job][i]];
		}

		if (max_cost < dp_cost_until_job[job])
			max_cost = dp_cost_until_job[job];
	}

	cout << max_cost << endl;
}
