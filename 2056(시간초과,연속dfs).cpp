#include<iostream>
#include<vector>

using namespace std;

int N;
int cost_of_job[10000];
vector<vector<int>> order_of_job;
int startjob_of_order[10000];
int num_of_startjob = 0;
int max_cost = 0;

void dfs(int job_num, int cost) {
	cost = cost + cost_of_job[job_num];

	if (order_of_job[job_num].size() == 0) {
		if (max_cost < cost)
			max_cost = cost;
	}

	for (int i = 0; i < order_of_job[job_num].size(); i++) {
		dfs(order_of_job[job_num][i], cost);
	}
}

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		order_of_job.push_back(vector<int>());
	}

	for (int i = 0; i < N; i++) {
		scanf("%d", &cost_of_job[i]);
		int jobnum_of_before;
		scanf("%d", &jobnum_of_before);
		if (jobnum_of_before == 0) {
			startjob_of_order[num_of_startjob] = i;
			num_of_startjob++;
		}
		for (int j = 0; j < jobnum_of_before; j++) {
			int before_job;
			scanf("%d", &before_job);
			order_of_job[before_job - 1].push_back(i);
		}
	}

	for (int i = 0; i < num_of_startjob; i++) {
		dfs(startjob_of_order[i], 0);
	}

	cout << max_cost << endl;
}
